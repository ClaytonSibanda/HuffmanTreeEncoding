//
// Created by clayza on 2018/04/02.
//


#ifndef ASSIGNMENT3_HUFFMAN_H
#define ASSIGNMENT3_HUFFMAN_H

#include <memory>
#include <queue>
#include <unordered_map>
#include <iostream>



class HuffmanNode;
class HuffmanTree{
private:
    std::shared_ptr<HuffmanNode> root;
public:
    HuffmanTree();
    ~HuffmanTree();

    void setRoot(std::shared_ptr<HuffmanNode> rt){
        root=std::move(rt);

    }

    std::shared_ptr<HuffmanNode>& getRoot(){
        return root;

    }

};

class HuffmanNode{
private:

    char letter;
    int frequency;

public:
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
    //destructor
    ~HuffmanNode(){};
    //default contructor
   HuffmanNode();
    //move constructor
    HuffmanNode (HuffmanNode&& node);
    //copy constructor
    HuffmanNode(const HuffmanNode &node);
    //move assignment operator
    HuffmanNode &operator=(HuffmanNode &&node);

    void setLetter(char lettr){
        letter=lettr;
    }
    void setFrequency(int freq){
        frequency=freq;
    }

   int getFrequency ()const {
       return frequency;
   }
    int getLetter ()const {
        return letter;
    }



};

class Compare{
    //used to compare the two objects
public:
    bool operator()(HuffmanNode & a,HuffmanNode & b){
        return a.getFrequency()>b.getFrequency();
    }
};

namespace  SBNCLA002{
    void populateMap();
    void buildTree();
    void inOrder(std::shared_ptr<HuffmanNode> &node,std::string);
    void printTable(std::string);
}




#endif //ASSIGNMENT3_HUFFMAN_H
