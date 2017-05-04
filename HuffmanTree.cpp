//
// Created by Mustafa on 02/05/2017.
//

#include <memory>
#include <queue>
#include "HuffmanTree.h"
using namespace std;

namespace RSHMUS001 {

    HuffmanTree::HuffmanTree() : root(nullptr) {}; //default constructor

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
        bool operator()(const HuffmanNode& a, const HuffmanNode& b)
        {
            return a.getFrequency() < b.getFrequency();
        }
    };


    void HuffmanTree::buildTree(unordered_map<char, int> & frequencyTable){

        priority_queue<HuffmanNode,vector<HuffmanNode>, compare > pq;

        for(auto it = frequencyTable.begin(); it != frequencyTable.end(); ++it){
            char l = it -> first;
            int f = it -> second;
            HuffmanNode node (l, f);
            pq.push(node);
        }

        while (pq.size() > 1){

            HuffmanNode parent;
            HuffmanNode l = pq.top(); //left child
            pq.pop();
            HuffmanNode r = pq.top(); //right child
            pq.top();

            parent.setLeft(l);
            parent.setRight(r);
            parent.setFreq(l.getFrequency() + r.getFrequency());
            parent.setLetter('\0');

            pq.push(parent);
        }

        root = make_shared<HuffmanNode>(pq.top());

    }

    void HuffmanTree::generateCodeTable(shared_ptr<HuffmanNode> node, string code){

        if (node != nullptr) {

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

    
}

