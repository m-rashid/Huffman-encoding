//
// Created by Mustafa on 02/05/2017.
//

#include <memory>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "HuffmanTree.h"
using namespace std;

namespace RSHMUS001 {

    HuffmanTree::HuffmanTree() {}; //default constructor

    HuffmanTree::HuffmanTree(const HuffmanTree & rhs) : root(rhs.root) {    //copy constructor

    };

    HuffmanTree::~HuffmanTree() {   //destructor
        root = nullptr;
    }

    HuffmanTree::HuffmanTree(HuffmanTree && rhs) : root(std::move(rhs.root)){ //move constructor
        rhs.root = nullptr;
    }

    /*
    bool compare (const HuffmanNode& a, const HuffmanNode& b){
        if(a<b){
            return true;
        }
        else{
            return false;
        }
    }
     */

    struct compare
    {
        bool operator()(const shared_ptr<HuffmanNode>& a, const shared_ptr<HuffmanNode>& b)
        {
            return a->getFrequency() > b->getFrequency();
        }
    };


    void HuffmanTree::buildTree(unordered_map<char, int> & frequencyTable){
      //cout << "In buildTree method" << endl;

        priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> pq;

        for(auto it = frequencyTable.begin(); it != frequencyTable.end(); ++it){
            char l = it -> first;
            int f = it -> second;
            shared_ptr<HuffmanNode> node (new HuffmanNode(l, f));
            pq.push(node);
        }

        while (pq.size() > 1){

            shared_ptr<HuffmanNode> parent (new HuffmanNode('\0', 0));
            shared_ptr<HuffmanNode> l = pq.top(); //left child
            parent->setLeft(l);
            pq.pop();
            shared_ptr<HuffmanNode> r = pq.top(); //right child
            parent->setRight(r);
            pq.pop();
            parent->setFreq(l->getFrequency() + r->getFrequency());
            pq.push(parent);
        }

        root = pq.top();

    }

    void HuffmanTree::generateCodeTable(shared_ptr<HuffmanNode> node, string code){
      //cout << "In generateCodeTable method" << endl;

        if (node != nullptr) {
            //cout << "node != nullptr" << endl;
            if(node -> getLeft() != nullptr){
                generateCodeTable(node -> getLeft(), code+"0");
            }

            if(node -> getLetter() != '\0'){
                codeTable[node -> getLetter()] = code;
            }

            if(node -> getRight() != nullptr){
                generateCodeTable(node -> getRight(), code+"1");
            }
        }
    }

    void HuffmanTree::compress(string input , string output){

        //cout << "In compress method" << endl;

        ifstream fin(input.c_str());
        if (!fin){
            cerr << "File open failed!" << endl;
        }

        string data;
        string bitbuffer;
        int numChars = 0;

        while (getline(fin, data)){
            for (int i =0; i < data.length(); i++){
                //cout << data[i] << endl;
                bitbuffer += codeTable[data[i]];
                numChars++;
            }
        }

        string output_hdr = output + ".hdr";
        ofstream fout(output_hdr.c_str());
        if (!fout){
            cerr << "File open failed!" << endl;
        }

        fout << "Count: " << codeTable.size() << endl;

        for(auto it = codeTable.begin(); it != codeTable.end(); ++it) {
            //fout << it->first << " : " << it->second << endl;
            stringstream ss;
            ss << it->first;
            string c;
            ss >> c;
            fout << c << " : " << it->second << endl;
        }

        fout.close();


        string output_bin = output + ".bin";
        ofstream bout(output_bin.c_str());
        bout << bitbuffer.c_str();

        bout.close();

        cout << "Compression Ratio: " << (bitbuffer.length())/numChars << endl;

        /*
        while (!fin.eof()){

            for (data ; getline(fin, data) ; ){
                for (int i=0; i<data.length(); i++){
                    output += codeTable[data[i]];
                }
            }

        }
         */
    }

    std::shared_ptr<HuffmanNode> HuffmanTree::getRoot() const {
        return root;
    }

    HuffmanTree & HuffmanTree::operator = (const HuffmanTree & rhs){
        if (this != &rhs) {
            root = rhs.root;
            codeTable = rhs.codeTable;
        }
        return *this;
    }

    HuffmanTree & HuffmanTree::operator = (HuffmanTree && rhs) //Move assignment operator
    {

        if (this != &rhs) {

            root = rhs.root;
            codeTable = rhs.codeTable;

            rhs.root = nullptr;

        }
        return *this;

    }


}
