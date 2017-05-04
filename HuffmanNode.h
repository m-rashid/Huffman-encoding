//
// Created by Mustafa on 02/05/2017.
//

#ifndef _HUFFMANNODE_H
#define _HUFFMANNODE_H

#include <memory>

namespace RSHMUS001 {

    class HuffmanNode {

    private:
        char letter;
        int frequency;
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;

    public:
        HuffmanNode();                          //default constructor
        HuffmanNode(char letter, int freq);     //parameterized constructor
        ~HuffmanNode();                         //destructor
        HuffmanNode(const HuffmanNode& node);   //copy constructor
        HuffmanNode(HuffmanNode&& node);        //move constructor

        //accessors
        char getLetter();
        int getFrequency();

        //mutators
        void setLetter(char l);
        void setFreq(int f);

    };
}
#endif //_HUFFMANNODE_H
