#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public std::exception
{
private:
    char *msg;
public:
    MyException(const char *message):std::exception() {msg = (char*)message;}
    const char *what() const noexcept {return msg;}
};
