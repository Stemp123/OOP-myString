#include "mystring.h"
#include <iostream>
#include <cstring>
#include "sten_trace.h"

using namespace std;

myString::~myString(){

    tracemex("dekonstruktor");
    delete [] m_cstr;
}

myString::myString(const char *cstr){
    tracemex("typkonvertering-konstruktor");

    if (cstr == nullptr || *cstr == 0){
        char * str = new char [1];
        *str = 0;
        m_cstr = str;
        m_size = 0;
    } else {
        char * str = new char [strlen(cstr) + 1];
        m_cstr = str;
        for (unsigned i = 0; i<strlen(cstr);i++)
            str[i] = cstr[i];
        m_size = strlen(cstr);
    }
}
myString::myString(const myString& otherString){
    tracemex("copy-konstruktor");

    if (otherString.m_cstr == nullptr){
        char * str = new char [1];
        *str = 0;
        m_cstr = str;
        m_size = strlen(str);
    } else {
        char * str = new char [strlen(otherString.m_cstr) +1];
        m_cstr = str;
        for (unsigned i = 0; i<strlen(otherString.m_cstr);i++)
            str[i] = otherString[i];
        m_size = strlen(str);
    }
}
myString::myString(myString &&otherString){
    tracemex("move-konstruktor");
    cout << "move" << endl;
    m_cstr = otherString.m_cstr;
    otherString.m_cstr = nullptr;
    m_size = otherString.m_size;
    otherString.m_size = 0;
}
const myString& myString::operator=(const myString& otherString){
    tracemex("tilldelning const");
    cout << "tilldelning const" << endl;
    if (this == &otherString)
        return *this;

    delete [] m_cstr;
    unsigned strLenght = strlen(otherString.m_cstr);
    m_cstr = new char [strLenght + 1];
    for (unsigned i = 0; i<strlen(otherString.m_cstr);i++)
        m_cstr[i] = otherString.m_cstr[i];
    m_size = strlen(m_cstr);
    return *this;
}
const myString& myString::operator=(myString&& otherString){
    tracemex("tilldelning ej const ");
    cout << "tilldelning" << endl;
    if (this == &otherString)
        return otherString;
    if (otherString.m_cstr == nullptr) {
        m_cstr = nullptr;
        m_size = 0;
        return *this;
    }

    delete [] m_cstr;
    unsigned strLenght = strlen(otherString.m_cstr);
    m_cstr = new char [strLenght + 1];
    for (unsigned i = 0; i<strlen(otherString.m_cstr);i++)
        m_cstr[i] = otherString[i];
    m_size = strlen(otherString.m_cstr);
    m_cstr[m_size] = '\0';

    return *this;
}
const myString& myString::operator+=(const myString otherString){
    tracemex("+= const");

    unsigned totalLenght = strlen(otherString.m_cstr) + strlen(m_cstr);
    const myString temp = this->m_cstr;
    unsigned strLenght = strlen(m_cstr);
    delete [] m_cstr;
    m_cstr = new char [totalLenght + 1];

    for (unsigned i = 0; i<strLenght;i++)
        m_cstr[i] = temp[i];
    for (unsigned p = 0; p<strlen(otherString.m_cstr);p++)
        m_cstr[strLenght + p] = otherString[p];
    m_size = totalLenght;
    return *this;
}
bool myString::operator==(const myString& otherString) const{
     traceme;
     if (strlen(m_cstr) != strlen(otherString.m_cstr))
         return false;
     for (unsigned i = 0; i<(strlen(m_cstr)); i++)
         if (m_cstr[i] != otherString[i])
             return false;
     return true;
}
int myString::size() const {
    traceme;
    return m_size;
}
char& myString::operator[](int x){
    traceme;
    return m_cstr[x];
}
char myString::operator[](int x) const{
    traceme;
    return m_cstr[x];
}
const char* myString::c_str() const{
    traceme;
    return m_cstr;
}
bool operator!=(const myString& a, const myString& b){
    traceme;
    return (a==b? false : true);
}
ostream& operator<<(ostream& out, const myString& str){
    traceme;
    out << str.c_str();
    return out;
}
