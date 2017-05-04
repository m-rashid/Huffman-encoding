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
        std::shared_ptr<HuffmanNode> leftNode;
        std::shared_ptr<HuffmanNode> rightNode;

    public:
        HuffmanNode();                          //default constructor
        HuffmanNode(char letter, int freq);     //parameterized constructor
        ~HuffmanNode();                         //destructor
        HuffmanNode(const HuffmanNode& node);   //copy constructor
        HuffmanNode(HuffmanNode&& node);        //move constructor

        void setRight (HuffmanNode r);
        void setLeft (HuffmanNode l);

        //accessors
        char getLetter() const ;
        int getFrequency() const ;

        //mutators
        void setLetter(char l);
        void setFreq(int f);

    };


}
#endif //_HUFFMANNODE_H
