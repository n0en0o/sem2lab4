#ifndef LAB2_MENU_H
#define LAB2_MENU_H
#include <iostream>

class Menu{
public:
    static void get_menu(){
        std::cout << "*---Menu---*" << std::endl;
        std::cout << "1.Show tree" << std::endl;
        std::cout << "2.Add to tree" << std::endl;
        std::cout << "3.Map tree" << std::endl;
        std::cout << "4.Find in tree" << std::endl;
        std::cout << "5.Get Subtree" << std::endl;
        std::cout << "Enter 'stop' to exit." << std::endl;
    }
};

#endif //LAB2_MENU_H
