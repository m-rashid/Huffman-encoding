//
// Created by Mustafa on 02/05/2017.
//

#include <memory>
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

    
}

