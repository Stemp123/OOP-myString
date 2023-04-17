#ifndef MYSTRING_H
#define MYSTRING_H
#include <ostream>

class myString
{
public:
    ~myString();
    myString(const char *cstr = nullptr);
    myString(const myString& otherString);
    myString(myString &&otherString);

    const myString& operator=(const myString& otherString);
    const myString& operator=(myString&& otherString);
    const myString& operator+=(const myString otherString);

    bool operator==(const myString& otherString) const;

    int size() const;

    char& operator[](int ix);
    char  operator[](int ix) const;

    const char* c_str() const;

private:
    char* m_cstr;
    int m_size;
};

bool operator!=(const myString& a, const myString b);

std::ostream& operator<<(std::ostream& out, const myString& str);

#endif // MYSTRING_H
