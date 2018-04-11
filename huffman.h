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
    bool isEmpty(std::shared_ptr<HuffmanNode> &root){
        if(root)
            return true;
        return false;
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
    void populateMap(std::string,std::unordered_map<char,int> & huffMap);
    void buildTree(std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> &huffQueue);
    void inOrder(std::shared_ptr<HuffmanNode> &root, std::string bitString, std::unordered_map<char, std::string> &table);
    void printTable(std::string,std::unordered_map<char,std::string> &table);
    void populateQueue(std::unordered_map<char,int>& huffMap,std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> &huffQueue);
    void decode();
    std::string readFile(std::string);

//    void inOrder(std::shared_ptr<HuffmanNode> &root, std::string bitString, std::unordered_map<char, std::string> &table);
//    void printTable(std::string filename, std::unordered_map<char, std::string> &table);
   void bitStream(std::string str, std::string filename);
}

//class to associate my containers with a object
class containerClass{
public:
 std::unordered_map<char,int> huffMap;
 //define a priority queue for building the Tree
 std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> huffQueue;
 std::unordered_map<char,std::string> table;
};


#endif //ASSIGNMENT3_HUFFMAN_H
