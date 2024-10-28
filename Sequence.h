
#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H

#include <cstddef>

template <typename  T>
class Sequence{
public:
    virtual ~Sequence() = default;

    [[nodiscard]] virtual size_t getLength() const = 0;
    virtual T& operator[](size_t index) const = 0;
    virtual T& get(int index) const = 0;
    virtual T& getFirst() const = 0;
    virtual T& getLast() const = 0;
    virtual Sequence<T>* append(const T& item) = 0;
    virtual Sequence<T>* prepend(const T& item) = 0;
    virtual Sequence<T>* insertAt(const T& item, int index) = 0;
    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T>* concatenation(const Sequence<T>* arr1,const Sequence<T>* arr2) = 0;
    virtual Sequence<T>* map(T (*func1)(T)) = 0;
    virtual size_t find(const T& item) = 0;
    virtual void show() = 0;
};

#endif //LAB2_SEQUENCE_H
