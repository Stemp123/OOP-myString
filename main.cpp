#include <iostream>
#include "mystring.h"
#include <cassert>
#include "sten_trace.h"
using namespace std;

USING_COUT_TRACE

myString mittNamn(){
    traceme;
    return "Ragnar";
}
void anropByValue(myString str){
    traceme;
    cout << str << endl;
}
void anropByRef(const myString &str){
    traceme;
    cout << str << endl;
}
bool arVersaler(const myString &str){
    traceme;
    for (int i=0; i<str.size(); ++i)
        if (str[i] != toupper(str[i]))
    return false;
return true;
}
void konverteraTillVersaler(myString &str){
    traceme;
    for (int i=0; i<str.size(); ++i)
        str[i] = toupper(str[i]);
}

void stringQuizz(){
traceme
myString s1( "Hello" );
s1 = "Hej";
}

void testaStrang(){
    traceme;
    myString str1;
    assert( str1 == "");
    myString str2 = "Hej";
    assert( str2.size() == 3 );

    str2 = "Sol";
    assert( str2.size() == 3 );
    assert( str2[1] == 'o');
    str2 += "sken!";
    assert( str2.size() == 8 );

    assert( str2 == "Solsken!");
    myString str3 = mittNamn();
    anropByValue(str3);
    anropByRef(str3);
    assert( !arVersaler(str2) );
    konverteraTillVersaler(str2);
    assert( arVersaler(str2) );

    cout << "testaStrang lyckades" << endl;
}
int main()
{
    traceme;
    //testaStrang();
    stringQuizz();
}
