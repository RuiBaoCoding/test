#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include"Story.h"

class Interface{
private:
    map<int,string>M;
    int N;//³¡¾°ÊýÁ¿
public:
    Interface();
    void print(int x);
    friend void Story::Print();
};

#endif