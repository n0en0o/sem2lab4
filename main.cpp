#include <iostream>
#include "Tests.h"
#include "Menu.h"


template <typename T>
T func1(T item) {
    item++;
    return item;
}

int main() {
    if(tests<int>() != 0){
        std::cout << "Tests crushed." << std::endl;
        return -1;
    }

    BinaryTree<int> tree;

    while(true) {
        char input[20];
        Menu::get_menu();

        std::cin >> input;
        if (std::string(input) == "stop") {
            std::cout << "Bye!" << std::endl;
            break;
        }

        int action = std::atoi(input);

        switch (action) {
            case 1:
            {
                std::string s = tree.toString("RNL");
                std::cout << s << std::endl;
                break;
            }

            case 2:
            {
                std::cout << "Enter element to add:" << std::endl;
                char item[20];
                std::cin >> item;
                int act = std::atoi(item);
                tree.insert(act);
                break;
            }

            case 3:
            {
                tree.map(func1);
                break;
            }

            case 4:
            {
                std::cout << "Enter element to find:" << std::endl;
                char item[20];
                std::cin >> item;
                int act = std::atoi(item);
                std::cout << "Element is here." << std::endl;
                break;
            }

            case 5:
            {
                std::cout << "Enter element to get subtree from:" << std::endl;
                char item[20];
                std::cin >> item;
                int act = std::atoi(item);

                break;
            }

            default: {
                std::cout << "Unknown command." << std::endl;
                break;
            }
        }
    }
    return 0;
}


/*if (std::all_of(input.begin(), input.end(), [](unsigned char c){ return std::isdigit(c); })) {
            action = std::stoi(input);
        }
        else
        {
            throw std::out_of_range("Unknown command.");
        }*/