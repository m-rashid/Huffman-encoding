//
// Created by Mustafa on 07/05/2017.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include <unordered_map>
#include <queue>
#include "HuffmanTree.h"

using namespace RSHMUS001;
using namespace std;

TEST_CASE ("Compressing files by building a HuffmanTree", "[compression]") {

    SECTION("Building tree"){

        unordered_map<char, int> test_freq = {{'h', 8}, {'e', 6}, {'l', 5}};
        HuffmanTree huffman;
        priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, HuffmanTree::compare> pq;

        for(auto it = test_freq.begin(); it != test_freq.end(); ++it){
            char l = it -> first;
            int f = it -> second;
            shared_ptr<HuffmanNode> node (new HuffmanNode(l, f));
            pq.push(node);
        }

        shared_ptr<HuffmanNode> root_test = huffman.getRoot();
        REQUIRE(root_test->getFrequency() == 19);

        REQUIRE(root_test->getLeft()->getFrequency() == 8);
        REQUIRE(root_test->getLeft()->getLetter() == 'h');

        REQUIRE(root_test->getRight()->getFrequency() == 11);
        REQUIRE(root_test->getLeft()->getLetter() == '\0');

        REQUIRE(root_test->getRight()->getLeft()->getFrequency() == 5);
        REQUIRE(root_test->getRight()->getLeft()->getLetter() == 'l');

        REQUIRE(root_test->getRight()->getRight()->getFrequency() == 6);
        REQUIRE(root_test->getRight()->getRight()->getLetter() == 'e');

    }

    

}