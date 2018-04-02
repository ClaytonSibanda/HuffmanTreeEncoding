//
// Created by clayza on 2018/04/02.
//


#ifndef ASSIGNMENT3_HUFFMAN_H
#define ASSIGNMENT3_HUFFMAN_H

#include <bits/shared_ptr.h>
#include <queue>
#include <unordered_map>
#include <iostream>
namespace SBNCLA002{
    std::unordered_map<char, int>;

}


class HuffmanNode;
class HuffmanTree{
private:
    std::shared_ptr<HuffmanNode>root;
public:
    HuffmanTree(){}
    ~HuffmanTree(){}


};

class HuffmanNode{
private:
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
    char letter;
    int frequency;

public:
    //destructor
    ~HuffmanNode();
    //default contructor
    HuffmanNode();
    //move constructor
    HuffmanNode (HuffmanNode&& node):letter(letter),frequency(frequency){
        node.letter='';
        node.frequency=0;
        std::cout<<"move constructor called"<<std::endl;
    }
    //copy constructor
    HuffmanNode(const HuffmanNode &node);
    //move assignment operator
    HuffmanNode & operator =(HuffmanNode &&node);

   int getFrequency(){
       return frequency;
   }




};

class Compare{
    //used to compare the two objects
    bool operator<(HuffmanNode & a,HuffmanNode & b){
        return a.getFrequency()<b.getFrequency();
    }
};

#endif //ASSIGNMENT3_HUFFMAN_H
