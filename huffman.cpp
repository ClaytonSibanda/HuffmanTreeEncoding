//
// Created by clayza on 2018/04/02.
//

#include "huffman.h"
#include <queue>
#include <unordered_map>

HuffmanNode::~HuffmanNode();

HuffmanNode::HuffmanNode(){
    letter='';
    frequency=0;
}

HuffmanNode &HuffmanNode::operator=(HuffmanNode &&node) {
    letter=node.letter;
    frequency= node.frequency;
    node.letter='';
    node.frequency=0;
    return *this;//return a self reference
}

HuffmanNode::HuffmanNode(const HuffmanNode &node) :letter(node.letter),frequency(node.frequency){

    std::cout<<"copy constructor called"<<std::endl;
}


std::priority_queue<HuffmanNode,std::vector<HuffmanNode>, Compare>;


