//
// Created by clayza on 2018/04/02.
//

#include "huffman.h"
#include <iostream>
#include <fstream>


using namespace std;

HuffmanTree::HuffmanTree() {}
HuffmanTree::~HuffmanTree(){
    root= nullptr;
    cout<<"destructor has been called here and tree hass been destroyed"<<endl;
};

//move constructor
HuffmanNode::HuffmanNode(HuffmanNode &&node) :letter(node.letter),frequency(node.frequency) {
    left =std::move(node.left);
    right= std::move(node.right);
    node.left= nullptr;
    node.right= nullptr;
    node.letter=0;
    node.frequency=0;
    std::cout<<"move constructor called"<<std::endl;
}

//move assignment operator
HuffmanNode &HuffmanNode::operator=(HuffmanNode &&node) {
    letter=node.letter;
    frequency= node.frequency;
    left =std::move(node.left);
    right= std::move(node.right);
    node.left= nullptr;
    node.right= nullptr;
    node.letter=0;
    node.frequency=0;
    return *this;//return a self reference
}
//copy constructor
HuffmanNode::HuffmanNode(const HuffmanNode &node) :letter(node.letter),frequency(node.frequency){
    left=node.left;
    right=node.right;
    std::cout<<"copy constructor called"<<std::endl;
}

HuffmanNode::HuffmanNode() :letter(0),frequency(0){
    std::cout<<"default constructor called"<<std::endl;

}



std::unordered_map<char,int> huffMap;
//define a priority queue for building the Tree
std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> huffQueue;

//populate the map with characters and frequncies
void SBNCLA002::populateMap(){



    string s="jehjrherehjreqhrkehqkjhrlq";
    for(int i=0;i<s.size();i++){
        if(huffMap.find(s[i])==huffMap.end()){

            huffMap.insert({s[i],1});
        }
        else{
            huffMap[s[i]]++;

        }
    }

//loop over a huffMap

    for(auto item:huffMap){
        HuffmanNode node;
        node.setLetter(item.first);
        node.setFrequency(item.second);
        huffQueue.push(node);
 //   cout<<(char)node.getLetter()<<":"<<node.getFrequency()<<'\t';
        //int val =huffQueue.top().getFrequency();
        //huffQueue.pop();
       // cout<<"Top is "<<val<<endl;
    }
}

//lets build the tree here broe
void SBNCLA002::buildTree() {
    cout<<"******** Now building the tree***********"<<endl;

    while (huffQueue.size()>1){
        HuffmanNode node;//internal node
        node.left=make_shared<HuffmanNode>(huffQueue.top());
//        cout<<"first top is "<<huffQueue.top().getFrequency()<<endl;

        huffQueue.pop();//remove the first node


        node.right=make_shared<HuffmanNode>(huffQueue.top());
        huffQueue.pop();//remove the second node

        node.setFrequency(node.left->getFrequency()+node.right->getFrequency());
        huffQueue.push(node);
//       cout<<"The new right is "<<node.right->getFrequency()<<endl;
    }
    HuffmanTree tree;
    tree.setRoot(make_shared<HuffmanNode>(huffQueue.top()));
   // cout<<"The new top is "<<huffQueue.top().left->getFrequency()<<endl;
    SBNCLA002::inOrder(tree.getRoot(),"");
}


//Traverse the tree here
unordered_map<char,string> table;
//string bitString ="";
void SBNCLA002::inOrder(shared_ptr<HuffmanNode> &root,string bitString) {
    //cout<<"running an inorder algorithm now"<<endl;

    if(!root) {

        cout<<"Now exiting"<<endl;
        return;
    }
    if(root->left){
//        bitString+="0";
        SBNCLA002::inOrder(root->left,bitString+"0");

    }
    if(root->right){
//        bitString+="1";
        SBNCLA002::inOrder(root->right,bitString+"1");


    }

//check if root is leaf
    if(!root->left && !root->right ){
        cout<<(char)root->getLetter()<<": "<<root->getFrequency()<<": "<<bitString<<endl;
      table.insert({(char)root->getLetter(),bitString});
    }


}
string buffer;
 void SBNCLA002::printTable(string filename){
    filename+=".hdr";
    ofstream file(filename);
    file<<"count"<<" "<<table.size()<<endl;

    for(auto item:table){
        buffer+=item.second;
        cout<<item.first<<'\t'<<item.second<<endl;
        file<<item.first<<'\t'<<item.second<<endl;
    }
}

