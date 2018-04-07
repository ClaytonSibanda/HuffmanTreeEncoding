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
SBNCLA002::populateMap(inputfile,c.huffMap);
SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
SBNCLA002::buildTree(c.huffQueue);
SBNCLA002::printTable(outputfile);


    return 0;

}