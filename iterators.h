#include <iostream>

template <typename Type>
class list;

template <typename Type>
class Iterator {
private:
    list<Type>* container_obj;
    Type* pointer;
public:
    Iterator(list<Type>& container_obj);
    Iterator(list<Type>& container_obj, int index);
    Iterator<Type> next();
    Type value();
    bool is_end();
    Iterator<Type>& operator++();
    Type& operator*();
    bool operator==(Iterator& b);
    bool operator!=(Iterator& b);
};

template <typename Type>
Iterator<Type>::Iterator(list<Type>& container_obj) {
    this->container_obj = &container_obj;
    this->pointer = &(container_obj[0]);
}

template <typename Type>
Iterator<Type>::Iterator(list<Type>& container_obj, int index) {
    this->container_obj = &container_obj;
    this->pointer = &(container_obj[0]) + index;
}

template <typename Type>
Iterator<Type> Iterator<Type>::next() {
    if (!is_end())
        ++pointer;
    return *this;
}

template <typename Type>
Type Iterator<Type>::value() {
    return *pointer;
}

template <typename Type>
bool Iterator<Type>::is_end() {
    int length = container_obj->get_length();
    if (pointer > &((*container_obj)[length - 1]))
        return true;
    return false;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator++() {
    this->next();
    return *this;
}

template <typename Type>
Type& Iterator<Type>::operator*() {
    return *pointer;
}

template <typename Type>
bool Iterator<Type>::operator==(Iterator& b) {
    return this->pointer == &(*b);
}

template <typename Type>
bool Iterator<Type>::operator!=(Iterator& b) {
    return !(this->pointer == &(*b));
}
