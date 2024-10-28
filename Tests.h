#ifndef LAB2_TESTS_H
#define LAB2_TESTS_H

#include <string>
#include "BinaryTree.h"
#include "Node.h"

template <typename T>
T func(T item) {
    item++;
    return item;
}


template <typename T>
int tests(){

    auto* t = new BinaryTree<int>;
    t->insert(3);
    t->insert(5);
    t->insert(4);
    t->insert(7);
    t->insert(2);

    std::string s = t->toString("NLR");


    if (s != "3 2 5 4 7 "){
        std::cout << "Insert1 is not working." << std::endl;
        return -1;
    }

    s = t->toString("NRL");

    if (s != "3 5 7 4 2 "){
        std::cout << "Insert2 is not working." << std::endl;
        return -1;
    }

    s = t->toString("LRN");

    if (s != "2 4 7 5 3 "){
        std::cout << "Insert3 is not working." << std::endl;
        return -1;
    }

    s = t->toString("LNR");

    if (s != "2 3 4 5 7 "){
        std::cout << "Insert4 is not working." << std::endl;
        return -1;
    }

    s = t->toString("RLN");

    if (s != "7 4 5 2 3 "){
        std::cout << "Insert5 is not working." << std::endl;
        return -1;
    }

    s = t->toString("RNL");

    if (s != "7 5 4 3 2 "){
        std::cout << "Insert6 is not working." << std::endl;
        return -1;
    }

    t->map(func);
    s = t->toString("RNL");
    if (s != "8 6 5 4 3 "){
        std::cout << "Map is not working." << std::endl;
        return -1;
    }

    t->remove(8);
    s = t->toString("RNL");

    if (s != "6 5 4 3 "){
        std::cout << "Remove is not working." << std::endl;
        return -1;
    }


    auto* t1 = t->subtree(5);
    s = t1->toString("RNL");


    if (s != "5 "){
        std::cout << "Subtree is not working." << std::endl;
        return -1;
    }


    return 0;
}

#endif //LAB2_TESTS_H
