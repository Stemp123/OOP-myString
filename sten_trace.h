#include <string>
#include <iostream>
#include <QtDebug>
#ifndef TRACE_H
#define TRACE_H
#define traceme trace traceobjekt( __func__ );
#define tracemex( extra ) trace traceobjekt( __func__ , extra );
#define tracemess( meddelande ) traceobjekt.message( meddelande );
#define USING_COUT_TRACE \
    int trace::s_aktuelltDjup = 0; \
    trace::Outputtype trace::s_utskriftsMetod = trace::output_cout;
#define USING_QDEBUG_TRACE \
    int trace::s_aktuelltDjup = 0; \
    trace::Outputtype trace::s_utskriftMetod 0 trace::output_qdebug;

class trace
{
public:

    enum Outputtype {output_cout, output_qdebug};

    void message(const std::string& str){
        printline( indentering() + "tracemess:" + str);
    }
    ~trace(){
        s_aktuelltDjup --;
        printline(indentering() + "<<" + m_funktionsnamn + "<<");
    }

    trace(const std::string& funktionsnamn, const std::string& extra){
        m_funktionsnamn = funktionsnamn;
        printline(indentering() + ">>" + m_funktionsnamn + " | " + extra + ">>");
        s_aktuelltDjup += 1;
    }

    trace(const std::string& funktionsnamn){
        m_funktionsnamn = funktionsnamn;
        printline(indentering() + ">>" + m_funktionsnamn + ">>");
        s_aktuelltDjup ++;
    }

private:   
    static int s_aktuelltDjup;
    static Outputtype s_utskriftsMetod;
    std::string m_funktionsnamn;
    std::string indentering(){
        std::string tempString;

        for (int i = 0 ; i<3*s_aktuelltDjup; i++)
            tempString += " ";
        return tempString;
    }
    void printline(const std::string& str){
        if (s_utskriftsMetod == output_cout)
            std::cout << str << std::endl;
        else qDebug() << str.c_str();
    }
};
#endif // TRACE_H
