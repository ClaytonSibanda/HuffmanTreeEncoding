#include <iostream>
#include <string>
#include "huffman.h"


using namespace std;

int main(int argc,char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

   string inputfile =string(argv[1]);
   string outputfile = string(argv[2]);
cout<<inputfile<<" "<<outputfile<<endl;
containerClass c;
string fileString = SBNCLA002::readFile(inputfile);
//cout<<fileString<<endl;
SBNCLA002::populateMap(fileString,c.huffMap);
SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
SBNCLA002::buildTree(c.huffQueue);

    HuffmanTree tree;
    if(!c.huffQueue.empty()) {
        tree.setRoot(make_shared<HuffmanNode>(c.huffQueue.top()));
    }
    SBNCLA002::inOrder(tree.getRoot(),"",c.table);
    SBNCLA002::printTable(outputfile,c.table);

    return 0;

}