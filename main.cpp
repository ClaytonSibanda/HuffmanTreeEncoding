#include <iostream>
#include <string>
#include "huffman.h"


using namespace std;

int main(int argc,char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

   string inputfile =string(argv[1]);
   string outputfile = string(argv[2]);
cout<<inputfile<<" "<<outputfile<<endl;

SBNCLA002::populateMap();
SBNCLA002::buildTree();
SBNCLA002::printTable(outputfile);


    return 0;

}