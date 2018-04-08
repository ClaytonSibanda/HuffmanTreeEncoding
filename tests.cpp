//
// Created by clayza on 2018/04/07.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "huffman.h"

//testing populateMap which has frequency calculation
SCENARIO("Characters  frequencies varies with number of identical character","[populateMap]"){


GIVEN("An empty map of the object c"){
containerClass c;
std::string testString;

WHEN("using a string with no duplicates") {
    testString = "abcd";
    SBNCLA002::populateMap(testString, c.huffMap);

    THEN("The frequency each letter should be 1 ") {

        REQUIRE(c.huffMap['a'] == 1);
        REQUIRE(c.huffMap['b'] == 1);
        REQUIRE(c.huffMap['c'] == 1);
        REQUIRE(c.huffMap['d'] == 1);
    }
}

WHEN("using a string with duplicate characters") {
    testString = "aavvsss";
    SBNCLA002::populateMap(testString, c.huffMap);

    THEN("Frequency of letters varies") {

        REQUIRE(c.huffMap['a'] == 2);
        REQUIRE(c.huffMap['v'] == 2);
        REQUIRE(c.huffMap['s'] == 3);
    }

}
WHEN("using a string with white space and other non-alphabet characters") {
    testString = "!;' /'?<.<> ><<> <<> ;''''; ";
    SBNCLA002::populateMap(testString, c.huffMap);

    THEN("Expect same behaviour as alphanumeric characters") {
        std::cout << "The last test case should fail" << std::endl;
        REQUIRE(c.huffMap['<'] == 6);
        REQUIRE(c.huffMap['?'] == 1);
        REQUIRE(c.huffMap[' '] == 5);
    }
}

}
}

//Now testing populeteQueue
SCENARIO("Populating priority queue from Map","[queue]")
{
    containerClass c;
    std::string testString ="claytonsibanda12345";
   GIVEN("an empty queue of an object") {
       WHEN("map is empty ") {
           SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
           THEN("queue should also be empty"){
               REQUIRE(c.huffQueue.empty());
           }

       }

       WHEN("map has been populated"){
           SBNCLA002::populateMap(testString,c.huffMap);
           SBNCLA002::populateQueue(c.huffMap,c.huffQueue);

           THEN("queue should not be empty"){
            REQUIRE(!c.huffQueue.empty());

           }

       }

   }
}

SCENARIO("building a tree","[buildTree]"){
    containerClass c;
    std::string testString ="claytonsibanda12345";
    GIVEN("An empty huffman tree of nodes"){
        HuffmanTree tree;
        WHEN("The queue is empty"){
            SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
            SBNCLA002::buildTree(c.huffQueue);
            THEN("tree should also be empty"){
                REQUIRE(tree.isEmpty(tree.getRoot()));
                REQUIRE(c.huffQueue.size()==0);

            }
        }
        WHEN("The queue is filled"){
            SBNCLA002::populateMap(testString,c.huffMap);
            SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
            SBNCLA002::buildTree(c.huffQueue);
            THEN("tree should also not be empty"){
                REQUIRE(!tree.isEmpty(tree.getRoot()));
                REQUIRE(c.huffQueue.size()==1);

            }
        }

    }
}
SCENARIO("building table/traversing the tree","[buildTable]"){
    containerClass c;
    std::string testString ="claytonsibanda12345";
    GIVEN("an empty table  of characters and bitstreams"){
        HuffmanTree tree;
        SBNCLA002::populateMap(testString,c.huffMap);
        SBNCLA002::populateQueue(c.huffMap,c.huffQueue);
//        SBNCLA002::buildTree(c.huffQueue);

        WHEN("The tree is empty"){
            tree.setRoot(nullptr);
            SBNCLA002::inOrder(tree.getRoot(),"",c.table);

            THEN("table map should also be empty"){
             REQUIRE(tree.isEmpty(tree.getRoot()));
             REQUIRE(c.table.empty());

         }
        }

        WHEN("The tree is filled and table has been build"){
            SBNCLA002::buildTree(c.huffQueue);
            SBNCLA002::inOrder(tree.getRoot(),"",c.table);
            THEN("table map should not be empty"){
                REQUIRE(!tree.isEmpty(tree.getRoot()));
                REQUIRE(!(c.table.empty()));

            }
        }

    }
}

