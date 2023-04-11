#include <iostream>
#include <listed.h>

using namespace std;

void test_base();
void test_base_extra();
void test_add();
void test_add_extra();
void test_elems();
void test_combine();
void test_sort();
int comp(int &r1, int &r2);
void test_index();
void test_array();
void test_iterators();
void test_inizalisation();
void test_remove();

int main()
{
    test_base();
    test_base_extra();
    test_inizalisation();
    test_add();
    test_add_extra();
    test_elems();
    test_remove();
    test_combine();
    test_sort();
    test_index();
    test_array();
    test_iterators();
    return 0;
}

void test_base(){
  list<int> b;//конструктор по умолчанию
  cout << "1. a list by comporator is made" << endl;
  cout << "----------------------------" << endl;
  list<int> a(2); //конструктор c длиной
  cout << "2. a list 'a' with size is made" << endl;
  cout << "len of 'a' - " << a.get_length() << endl;
  cout << "elements of list 'a': " << endl;
  for (int i = 0; i < a.get_length(); i++)
      cout << a[i] << " ";
  cout << endl;
  cout << "----------------------------" << endl;
  list<int> a2 = a;
  cout << "3. a list 'a2' is copied by 'a'" << endl;
  cout << "len of 'a2' - " << a2.get_length() << endl;
  cout << "elements of list 'a2': " << endl;
  for (int i = 0; i < a2.get_length(); i++)
      cout << a2[i] << " ";
  cout << endl;
  cout << "----------------------------" << endl;
}

void test_base_extra(){
    list<int> a(2);
    list<int> b;
    list<int> a2 =a;
    list<int> a3 = std::move(a2);//конструктор перемещения
    a2 = std::move(a);//конструктор перемещения
    list<int> b1 = std::move(b);
    cout << "len of 'b1' - " << b1.get_length() << endl;
    cout << "len of 'b' - " << b.get_length() << endl;
    cout << "4. a list 'a3' is moved from 'a2'" << endl;
    cout << "len of 'a3' - " << a3.get_length() << endl;
    cout << "elemets of list 'a3': " << endl;
    for (int i = 0; i < a3.get_length(); i++)
         cout << a3[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}
void test_inizalisation(){
    list<int> a4{1,2,3,4,5};//список инициализации
    list<int> a100{};
    list<int> a228;
    list<int> a105;
    a105 = a4;
    a228 = a100;
    //a4 = a100;//+присваивание ицниалиазции ++ .. иниц + пустой
    cout << "len of 'a100' - " << a100.get_length() << endl;
    cout << "len of 'a228' - " << a228.get_length() << endl;
    cout << "5. a list 'a4' is initialized by numbers (1,2,3,4,5)" << endl;
    cout << "len of 'a4' - " << a4.get_length() << endl;
    cout << "elemets of list 'a4': " << endl;
    for (int i = 0; i < a4.get_length(); i++)
        cout << a4[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
    list<int> a5;
    a5 = a4;//перегрузка оператора присваивания
    cout << "6. a list 'a5' is assigned by 'a4'" << endl;
    cout << "len of 'a5' - " << a5.get_length() << endl;
    cout << "elemets of list 'a5': " << endl;
    for (int i = 0; i < a5.get_length(); i++)
        cout << a5[i] << " ";
    cout << endl;
}
void test_add(){
    cout << "----------------------------" << endl;
    list<int> a6{1,2,3,4};
    cout << "7. a list 'a6' is initialized with (1,2,3,4)" << endl;
    a6.add(123);
    a6.add(123);//2 раза добавим 123
    cout << "123 is added to list 'a6'" << endl;
    cout << "elemets of list 'a6': " << endl;
    for (int i = 0; i < a6.get_length(); i++)
        cout << a6[i] << " ";
    cout << endl;
    list<int> a7{1,2,3};
    list<int> a8{4,5};
    list<int> a12{};
    cout << "----------------------------" << endl;
    cout << "8. a list 'a7' is initialized with (1,2,3) " << endl;
    cout << "a list 'a8' is initialized with (4,5) " << endl;
    a7.add_range(a8);
    a7.add_range(a12);//a7 add range пустой
    cout << "elemets of list 'a7' + 'a8': " << endl;
    for (int i = 0; i < a7.get_length(); i++)
        cout << a7[i] << " ";
    cout << endl;
}

void test_add_extra(){
    try {
        cout << "----------------------------" << endl;
        list<int> a9{1,2};
        cout << "9. a list 'a9' is initialized with (1,2) " << endl;
        cout << "an arr is with (-1,-2,-3,-4) " << endl;
        int arr[4]{-1,-2,-3,-4};
        a9.add_range(arr, 3);
        cout << "elements of list 'a9' + 'arr':" << endl;
        for (int i = 0; i < a9.get_length(); i++)
            cout << a9[i] << " ";
        cout << endl;
        a9.add_range(arr, -3);
    }catch(MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_elems(){
    try {
        cout << "----------------------------" << endl;
        list<int> a10{1,2,3,4};
        cout << "10. a list 'a10' is initialized with (1,2,3,4) " << endl;
        cout << "the first element is changed to '0'" << endl;
        a10.set_elem(0,0);
        cout << "elements of list 'a10':" << endl;
        for (int i = 0; i < a10.get_length(); i++)
            cout << a10[i] << " ";
        cout << endl;
        cout << "----------------------------" << endl;
        a10.set_elem(-1,-1);
    }catch (MyException& ex) {
        cout << ex.what() << endl;
    try{
        list<int> a11{1,2,3,4,5};
        cout << "11. a list 'a11' is initialized with (1,2,3,4,5) " << endl;
        cout << "the first element is - " << a11.get_elem(0) << endl;
        cout << "----------------------------" << endl;
        a11.get_elem(-900);
    } catch (MyException& ex){
        cout << ex.what() << endl;
        }
    }
}

void test_remove(){
    try {
        list<int> a12{1,2,3,4};
        cout << "12. a list 'a12' is initialized with (1,2,3,4) " << endl;
        cout << "the second element is removed" << endl;
        a12.remove_elem(1);
        cout << "elements of list 'a12':" << endl;
        for (int i = 0; i < a12.get_length(); i++)
            cout << a12[i] << " ";
        cout << endl;
        a12.remove_elem(-69);
    }catch (MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_combine(){
    cout << "----------------------------" << endl;
    list<int> a13 {1,2,3};
    list<int> a14 {4,5};
    list<int> a15{};
    cout << "13. a list 'a13' is initialized with (1,2,3) " << endl;
    cout << "a list 'a14' is initialized with (4,5) " << endl;
    a13.combine(a14);
    a14.combine(a15);//на всякий пожарный
    cout << "elements of list 'a13', which was combined with 'a14':" << endl;
    for (int i = 0; i < a13.get_length(); i++)
        cout << a13[i] << " ";
    cout << endl;
}

int comp(const int &r1, const int &r2)
{
    return r1 > r2;
}

void test_sort(){
    cout << "----------------------------" << endl;
    list<int> a15 {5,2,1,4,3};
    list<int> a229 {}; //sort для пустого
    cout << "14. a list 'a15' is initialized with (5,2,1,4,3) " << endl;
    cout << "a list 'a15' is sorted " << endl;
    a15.sort(comp);
    a229.sort(comp);
    cout << "elements of list 'a15':" << endl;
    for (int i = 0; i < a15.get_length(); i++)
        cout << a15[i] << " ";
    cout << endl;
    cout << "elements of list 'a15':" << endl;
    for (int i = 0; i < a229.get_length(); i++)
        cout << a229[i] << " ";
    cout << endl;
}

void test_index(){
    try {
        cout << "----------------------------" << endl;
        list<int> a16 {1,2,3,4,5};
        cout << "15. a list 'a16' is initialized with (1,2,3,4,5) " << endl;
        cout << "element '2' has index " << a16.get_index(2);
        cout << endl;
        cout << "element '2' has index " << a16.get_index(-200);//на дурака
        cout << endl;
    }catch(MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_array(){
    cout << "----------------------------" << endl;
    list<int> a17 {1,2,3,4,5};
    list<int> a18 {};
    cout << "16. a list 'a17' is initialized with (1,2,3,4,5) " << endl;
    int *array = a17.to_array();
    int *array2 = a18.to_array();//для пустого дурака (сделано)
    cout << "elements of list 'a17' are moved to array" << endl;
    cout << "elements of array:" << endl;
    for (int i = 0; i < a17.get_length(); i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "elements of list 'a18' are moved to array" << endl;
    cout << "elements of array:" << endl;
    for (int i = 0; i < a18.get_length(); i++)
        cout << array[i] << " ";
    free(array);
    free(array2);
    cout << endl;
}

void test_iterators(){
    cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << endl;
    list<int> a18{10,20,30,40,50,60,70,80,90,100};
    cout << "17. a list 'a18' is initialized with (10,20,30,40,50,60,70,80,90,100) " << endl;
    Iterator<int> iterator(a18);
    cout << "\nthe value of iterator is - " << iterator.value() << endl;
    cout << "\nthe value of iterator after next() is - " << iterator.next().value() << endl;
    cout << "\nis it end? - " << iterator.is_end() << endl;
    auto a19 = a18.begin();
    ++a19;
    cout << "\nthe list 'a19' is made and iterator is moved to second element" << endl;
    if (iterator == a19){
        cout << "the position of iterator and element is similar" << endl;
        cout << *iterator << " == " << a19.value() << endl;}
    else{
        cout << "the position of iterator and element is different" << endl;
        cout << *iterator << " != " << *a19 << endl;}
    auto a20 = a18.end();
    if (a19 != a20){
        cout << "\nthe end of list 'a18' is not similar as position of iterator" << endl;
        cout << *a19 << " != " << a20.value() << endl;}
    else{
        cout << "\nthe end of list 'a18' is similar as position of iterator" << endl;
        cout << *a19 << " == " << *a20 << endl;}
}

