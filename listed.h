#ifndef LISTED_H
#define LISTED_H
#include "exception.h"
#include "iterators.h"

#include <initializer_list>
template<typename Type>
class list {
private:
    int amount;
    Type *m_lis;
public:
    list(); //конструктор
    list(const list <Type>&lst);//констурктор копирования
    list(list<Type>&&list);//конструткор перемещения
    explicit list(std::initializer_list<Type> lst);//конструктор со списком инициализации
    ~list();//деструктор
    list<Type>&operator = (const list<Type>&lst);//перегрузка оператора
    int get_length() const{return amount;}
    Type& operator[](int index);
    void add(const Type &elem);
    list(int length);
    void resize(int amount);
    void add_range(const list <Type> &lst);
    void add_range(Type *arr, int size);
    void set_elem(int index, const Type& elem);
    Type &get_elem(int index);
    void remove_elem(int index);
    list<Type> &combine(const list<Type> &lst);
    bool comp(Type &r1, Type &r2);
    void sort(int (*comp)(const Type &r1, const Type &r2));
    int get_index(Type elem)const;
    Type* to_array();
    Iterator<Type> begin();
    Iterator<Type> end();

};

template <typename Type>
list<Type>::list(){
    amount = 0;
    try {
        m_lis = new Type[amount];
    } catch (bad_alloc ex){
        throw MyException("not memory");
    }
}

template<typename Type>
list<Type>::list(const list<Type>&lst) :amount(lst.amount)//констурктор копирования
{
    amount = lst.amount;
    try {
        m_lis = new Type[amount];
        for (int i = 0; i < amount; i++){
            m_lis[i] = lst.m_lis[i];
        }
    }catch(bad_alloc ex){
        throw MyException("not memory");
    }
}

template<typename Type>
list<Type>::list(list<Type>&&list)//конструткор перемещения
{
    amount = list.amount;
    m_lis = list.m_lis;
    list.m_lis = nullptr;
    list.amount = 0;
}

template<typename Type>
list<Type>::list(std::initializer_list<Type> lst)//конструктор со списком инициализации
{
    amount = lst.size();
    m_lis = new Type[amount]{};
    int i = 0;
    for (Type item : lst)
        m_lis[i++] = item;
}

template<typename Type>//деструктор
list<Type>::~list()
{
    if (m_lis != nullptr)
        delete[] m_lis;
}

template<typename Type>
list<Type> &list<Type>::operator = (const list<Type>&lst)//перегрузка оператора
{
    m_lis = new Type[lst.amount]{};
    amount = lst.amount;
    for (int i = 0; i < lst.amount; i++)
        m_lis[i] = lst.m_lis[i];
    return *this;
}

template<typename Type>
list<Type>::list(int length) : amount(length)//задавание списка с опр. длиной
{
    try {
        m_lis = new Type[length]{};
    }catch (bad_alloc ex){
        throw MyException("not memory");
    }
}

template<typename Type>
Type &list<Type>::operator[](int index){//доступ к элементу
    //return *(m_lis + index);//сделать через гет елем
    return get_elem(index);
}

template<typename Type>
void list<Type>::add(const Type &elem){
    amount++;
    resize(amount);
    m_lis[amount - 1] = elem;
}

template<typename Type>
void list<Type>::resize(int amount){
    try {
        m_lis = (Type*)realloc(m_lis, sizeof(Type) * amount);
    } catch (bad_alloc ex){
        throw MyException("not memory");
    }
}

template<typename Type>
void list<Type>::add_range(const list <Type> &lst){
    amount += lst.amount;
    resize(amount);
    int tmp = amount - lst.amount;
    for (int i = tmp; i < amount; i++)
        m_lis[i] = lst.m_lis[i-tmp];
}

template<typename Type>
void list<Type>::add_range(Type *arr, int size){
    if (size < 0 || size * sizeof(Type) <= sizeof(arr))
        throw MyException("out of range!\n");
    amount += size;
    resize(amount);
    int tmp = amount - size;
    for (int i = tmp; i < amount; i++)
        m_lis[i] = arr[i - tmp];
}

template<typename Type>
void list<Type>::set_elem(int index, const Type& elem){
    if (index < amount && index >= 0)
        m_lis[index] = elem;
    else
        throw MyException(" - out of range\n");
}

template<typename Type>
Type& list<Type>::get_elem(int index){
    if (index < amount && index >= 0)
        return m_lis[index];
    else
        throw MyException(" - out of range\n");
}

template<typename Type>
void list<Type>::remove_elem(int index){
    if (index < amount && index >= 0){
        for (int i = index; i < amount; i++)
            m_lis[i] = m_lis[i+1];
        amount--;
    }
    else
        throw MyException(" - out of range!/n");
}

template<typename Type>
list<Type>& list<Type>::combine(const list<Type>&lst){
    this -> add_range(lst);
    return *this;
}

template<typename Type>
void list<Type>::sort(int (*comp)(const Type &r1, const Type &r2)){
    int tmp;
    for (int i = 0; i < amount - 1; i++)
        for (int j = 0; j < amount - 1; j++)
            if (comp(m_lis[j + 1], m_lis[j])){
                tmp = m_lis[j + 1];
                m_lis[j + 1] = m_lis[j];
                m_lis[j] = tmp;
            }
}

template<typename Type>
bool list<Type>::comp(Type &r1, Type &r2){
    return r1 < r2;
}

template<typename Type>
int list<Type>::get_index(Type elem) const{
    for (int i = 0; i < amount; i++)
        if (m_lis[i] == elem)
            return i;
    return -1;
}

template<typename Type>
Type* list<Type>::to_array(){
    Type* new_array = new Type[amount];
    for (size_t i = 0; i < amount; i++)
        new_array[i] = m_lis[i];
    return new_array;
}

template<typename Type>
Iterator<Type> list<Type>::begin()
{
    return Iterator<Type>(*this);
}

template<typename Type>
Iterator<Type> list<Type>::end() {
    return Iterator<Type>(*this, (this->amount) - 1);
}
#endif // LISTED_H


