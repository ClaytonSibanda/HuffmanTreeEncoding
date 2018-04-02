//
// Created by clayza on 2018/04/02.
//

#ifndef ASSIGNMENT3_HUFFMAN_H
#define ASSIGNMENT3_HUFFMAN_H

#include <bits/shared_ptr.h>
class HuffmanNode;
class HuffmanTree{
private:
    std::shared_ptr<HuffmanNode>root;
public:
    bool compare(const HuffmanNode& a, const HuffmanNode& b)
    {
        if(a < b) return true; // or > if the algorithm requires that ordering
        else return false;
    }
    std::priority_queue<HuffmanNode, compare>;

HuffmanTree(){
}

};

class HuffmanNode{
private:
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
    char letter;
    int frequncy;

public:
    //desttructor
    ~HuffmanNode(){}
    //default contructor
    HuffmanNode(){}
    //move constructor
    //copy constructor
    //move assignment operator
    //overload the < operator
    operator




};


#endif //ASSIGNMENT3_HUFFMAN_H
