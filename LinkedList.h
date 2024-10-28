#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include "Sequence.h"
#include <iostream>

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        Node(const T &val) : value(val), next(nullptr) {}

        T value;
        Node *next;
    };

    Node *head{0};
    size_t size{0};

public:

    class Iterator {
        friend class LinkedList;
    protected:
        Node* node;
        const LinkedList* list;
    public:
        Iterator() : node(nullptr), list(nullptr) {}

        Iterator(const LinkedList* list, Node* node): node(node), list(list) {}

        T& operator*() { return node->value; }

        bool operator==(const Iterator& It) const { return list == It.list && node == It.node; }

        bool operator!=(const Iterator& It) const { return *this != It; }

        Iterator next_it() const {
            if (node != nullptr)
                return Iterator(list, node->next);
            return *this;
        }

        Iterator& operator++() {
            if (node != nullptr)
                node = node->next;
            return *this;
        }
    };

    Iterator begin() const {
        return Iterator(this, (LinkedList<T>::Node*) getFirst());
    }
    Iterator end() const {
        return Iterator(this, (LinkedList<T>::Node*) getLast()).next_it();
    }


    LinkedList() : head(nullptr), size(0) {}

    LinkedList(T* arr, size_t size) : size(size) {
            head = nullptr;
            Node* current = nullptr;
            for (size_t i = 0; i < size; ++i) {
                Node* newNode = new Node(arr[i]);
                if (i == 0) {
                    head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
            }
    }

    LinkedList(LinkedList<T>& other) : size(other.size) {
        if (other.head == nullptr) {
            head = nullptr;
        } else {
            head->value = other.head->value;
            head->next = other.head->next;
            Node* current = head;
            Node* otherCurrent = other.head->next;
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->value);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    [[nodiscard]] size_t getLength() const {
        return size;
    }


    T &operator[](size_t index) const {
        return get(index);
    }


    T &get(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range.");
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }


    T &getFirst() const {
        if (size == 0) {
            throw std::out_of_range("Index out of range.");
        }
        return get(0);
    }


    T &getLast() const {
        if (size == 0) {
            throw std::out_of_range("Index out of range.");
        }
        return get(size - 1);
    }

    LinkedList<T>* append(const T& item) {
        Node* newNode = new Node(item);
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
        return this;
    }

    LinkedList<T>* prepend(const T& item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        size++;
        return this;
    }


    LinkedList<T>* insertAt(const T& item, int index) {
        if (index < 0 || index > size){
            throw std::out_of_range("Index out of range.");
        }
        Node* newNode = new Node(item);
        if (size == 0 || index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
        return this;
    }

    LinkedList<T>* remove(const T& item) {
        if (head == nullptr) return this;
        if (head->value == item) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            size--;
            return this;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->value != item) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
            size--;
            return this;
        }
        return this;
    }

    LinkedList<T>* getSubsequence(int startIndex, int endIndex){
        if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size){
            throw std::out_of_range("Index out of range.");
        }
        auto* newList = new LinkedList<T>();
        Node* current = head;
        size_t index = 0;

        while (current != nullptr && index < startIndex) {
            current = current->next;
            index++;
        }

        while (current != nullptr && index <= endIndex) {
            newList->append(current->value);
            current = current->next;
            index++;
        }
        return newList;
    }


    LinkedList<T>* concatenation(const LinkedList<T>* arr1,const LinkedList<T>* arr2) {
        auto *newList = new LinkedList<T>;
        for (size_t i = 0; i < arr1->getLength(); i++){
            newList->append(arr1->get(i));
        }
        for (size_t i = 0; i < arr2->getLength(); i++){
            newList->append(arr2->get(i));
        }
        return newList;
    }


    LinkedList<T>* map(T (*func1)(T)) {
        auto* newList = new LinkedList<T>;
        newList->head = head;
        newList->size = size;
        Node* current = newList->head;
        while(current != nullptr){
            current->value = func1(current->value);
            current = current->next;
        }
        return newList;
    }


    size_t find(const T& item) {
        size_t index = -1;
        size_t cnt = 0;
        Node* current = head;
        while(current != nullptr){
            if(current->value == item){
                index = cnt;
                break;
            }
            cnt++;
        }
        return index;
    }


    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

#endif //LAB2_LINKEDLIST_H
