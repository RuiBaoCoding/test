#include<iostream>
#include<map>
#include<string>
#include <fstream>
#include<windows.h>//ͷ�ļ� 
using namespace std;
#include"Story.h"
#include"Interface.h"

int main()
{
    Interface n;
    n.print(0);
    cout<<"��ӭ�������ֺ󹬣���������水ť�е����ֿ�ʼ��Ϸ��";
    string str;
    while (1)
    {
        cin>>str;
        if (str=="PLAY")
        {
            break;
        }
        cout<<"���������������������룺";
    }
    Story m;
    while(1){
        m.Print();
        char c;
        cin>>c;
        m.GetNextNode(c);
        if (m.GetState()==0){
            cout<<"��Ϸ����"<<endl;
            break;
        }
    }
	return 0;
}

