//
// Created by Mustafa on 02/05/2017.
//

#include <memory>
#include "HuffmanNode.h
using namespace std;

namespace RSHMUS001{

    //default constructor
    HuffmanNode::HuffmanNode() : frequency(0), letter(0){

    }

    //parametrized constructor
    HuffmanNode::HuffmanNode(char l = '\0', int f = 0) : frequency(f), letter(l) {

    }

    //destructor
    HuffmanNode::~HuffmanNode(){

    }

    //copy constructor
    HuffmanNode::HuffmanNode(const HuffmanNode & rhs) : letter(rhs.letter), frequency(rhs.frequency){

    }

    //move constructor
    HuffmanNode::HuffmanNode (HuffmanNode && rhs) : letter(rhs.letter), frequency(rhs.frequency){
        rhs.frequency = 0;
    }

    char HuffmanNode::getLetter() const {
        return letter;
    }

    int HuffmanNode::getFrequency() const {
        return frequency;
    }

    void HuffmanNode::setLetter(char l){
        letter = l;
    }

    void HuffmanNode::setFreq(int f) {
        frequency = f;
    }

    /*
    bool HuffmanNode::compare(HuffmanNode a, HuffmanNode b){
        if((a.getFrequency() < b.getFrequency())){
            return true;
        }
        else{
            return false;
        }
    }
     */

    void HuffmanNode::setLeft(HuffmanNode l) {
        leftNode = make_shared<HuffmanNode>(l);
    }

    void HuffmanNode::setRight(HuffmanNode r) {
        rightNode = make_shared<HuffmanNode>(r);
    }

}

