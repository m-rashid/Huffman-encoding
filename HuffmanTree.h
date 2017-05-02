//
// Created by Mustafa on 02/05/2017.
//

#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H


#include <algorithm>
#include <string>
#include <unordered_map>

namespace RSHMUS001{
    class HuffmanTree{

    private:
        std::shared_ptr<HuffmanNode> root;
        std::unordered_map<char, std::string> codeTable;

    public:
        HuffmanTree() : root(nullptr) {}; //default constructor
        ~HuffmanTree(); //destructor
        HuffmanTree(const HuffmanTree & rhs) : root(rhs.root) {}; //copy constructor
        HuffmanTree(HuffmanTree && rhs) : root(std::move(rhs.root)){ //move constructor
            rhs.root = nullptr;
        }

    };

}

#endif //_HUFFMANTREE_H
