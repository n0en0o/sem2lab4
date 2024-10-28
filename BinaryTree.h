#ifndef LAB4_BINARYTREE_H
#define LAB4_BINARYTREE_H

#include <iostream>
#include <string>
#include "Node.h"

template <typename T>
class BinaryTree{
private:

    Node<T>* root;

    void clear() {
        destroy(root);
    }

    void destroy(Node<T>* &node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:

    BinaryTree() : root(nullptr) {}

    explicit BinaryTree(Node<T>* rt): root(rt){}


    Node<T>* insertItem(Node<T>* &node, const T& value) {
        if (node == nullptr) {
            node = new Node(value);
            return node;
        }
        if (value < node->value)
            node->left = insertItem(node->left, value);
        else if (value > node->value)
            node->right = insertItem(node->right, value);
        return node;
    }


    void insert(const T& value){
        root = insertItem(root, value);
    }


    Node<T>* searchItem(Node<T>* node, const T& value) const{
        if (node != nullptr)
        {
            if (value == node->value) return node;
            if (value < node->value) return searchItem(node->left, value);
            else return searchItem(node->right, value);
        }
        return nullptr;
    }


    Node<T>* search(const T& value) const{
        return searchItem(root, value);
    }


    Node<T>* findMinNode(Node<T>* node){
        Node<T>* tmp = node;
        while (tmp->left)
        {
            tmp = tmp->left;
        }
        return tmp;
    }


    Node<T>* deleteItem(T& value, Node<T>* node){
        if (node == nullptr){
            return nullptr;
        }
        else if (value < node->value){
            node->left = deleteItem(value, node->left);
        }
        else if(value > node->value){
            node->right = deleteItem(value, node->right);
        }
        else{
            if(node->left == nullptr){
                Node<T>* tmp = node->right;
                if(node == root){
                    root = tmp;
                }
                delete node;
                return tmp;
            }
            else if(node->right == nullptr){
                Node<T>* tmp = node->left;
                if(node == root){
                    root = tmp;
                }
                delete node;
                return tmp;
            }
            else{
                Node<T>* tmp = findMinNode(node->right);
                node->value = tmp -> value;
                node->right = deleteItem(tmp->value, node->right);
            }
        }
        return node;
    }


    void remove(T value){
        deleteItem(value, root);
    }


    void map(T (*func)(T item), Node<T>* node)
    {
        if (node)
        {
            node->value = func(node->value);
            map(func, node->left);
            map(func, node->right);
        }
    }


    void map(T (*func)(T data))
    {
        map(func, root);
    }


    void inorderPrint(Node<T> *node)
    {
        if (node)
        {
            inorderPrint(node->left);
            std::cout << node->value << " ";
            inorderPrint(node->right);
        }
    }


    void inorderPrint()
    {
        inorderPrint(root);
        std::cout << std::endl;
    }


    void postorderPrint(Node<T>* node){
        if(node){
            postorderPrint(node->left);
            postorderPrint(node->right);
            std::cout << node->value << " ";
        }
    }


    void postorderPrint(){
        postorderPrint(root);
        std::cout << std::endl;
    }


    void preorderPrint(Node<T>* node){
        if(node){
            std::cout << node->value << " ";
            preorderPrint(node->left);
            preorderPrint(node->right);
        }
    }


    void preorderPrint(){
        preorderPrint(root);
        std::cout << std::endl;
    }


    void reverseInorderPrint(Node<T> *node){
        if(node){
            reverseInorderPrint(node->right);
            std::cout << node->value << " ";
            reverseInorderPrint(node->left);
        }
    }


    void reverseInorderPrint(){
        reverseInorderPrint(root);
        std::cout << std::endl;
    }


    void reversePreorderPrint(Node<T>* node){
        if(node){
            std::cout << node->value << " ";
            reversePreorderPrint(node->right);
            reverseInorderPrint(node->left);
        }
    }


    void reversePreorderPrint(){
        reversePostorderPrint(root);
        std::cout << std::endl;
    }


    void reversePostorderPrint(Node<T>* node){
        if(node){
            reversePostorderPrint(node->right);
            reversePostorderPrint(node->left);
            std::cout << node->value << " ";
        }
    }


    void reversePostorderPrint(){
        reversePostorderPrint(root);
        std::cout << std::endl;
    }


    Node<T>* subtree(Node<T>* node){
        Node<T>* newRoot = nullptr;
        if(node){
            newRoot = new Node(node->value);
            newRoot->left = subtree(node->left);
            newRoot->right = subtree(node->right);
        }
        else{
            return nullptr;
        }
        return newRoot;
    }


    BinaryTree<T>* subtree(T value){
        auto* tr = new BinaryTree<T>(subtree(search(value)));
        return tr;
    }

    std::string toString(std::string traversal, Node<T> *node, bool isFirst)
    {
        static std::string ans = "";
        if(isFirst){
            ans = "";
        }
        if (node)
        {
            if(traversal == "NLR"){
                ans += std::to_string(node->value) + " ";
                toString(traversal, node->left, false);
                toString(traversal, node->right, false);
            }
            else if(traversal == "NRL"){
                ans += std::to_string(node->value) + " ";
                toString(traversal, node->right, false);
                toString(traversal, node->left, false);
            }
            else if(traversal == "LRN"){
                toString(traversal, node->left, false);
                toString(traversal, node->right, false);
                ans += std::to_string(node->value) + " ";
            }
            else if(traversal == "LNR"){
                toString(traversal, node->left, false);
                ans += std::to_string(node->value) + " ";
                toString(traversal, node->right, false);
            }
            else if(traversal == "RLN"){
                toString(traversal, node->right, false);
                toString(traversal, node->left, false);
                ans += std::to_string(node->value) + " ";
            }
            else if(traversal == "RNL"){
                toString(traversal, node->right, false);
                ans += std::to_string(node->value) + " ";
                toString(traversal, node->left, false);
            }
        }
        return ans;
    }


    std::string toString(std::string traversal)
    {
        return toString(traversal, root, true);
    }

    Node<T>* mergeTrees(Node<T>* t1, Node<T>* t2) {
        if (!t1 && !t2) return nullptr;
        if (!t1) return t2;
        if (!t2) return t1;

        auto* tree = new Node<T>(t1->value + t2->value);
        tree->left = mergeTrees(t1->left, t2->left);
        tree->right = mergeTrees(t1->right, t2->right);
        return tree;
    }


    ~BinaryTree() {
        clear();
    }
};

#endif //LAB4_BINARYTREE_H
