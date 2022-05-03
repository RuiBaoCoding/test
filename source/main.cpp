#include<iostream>
#include<map>
#include<string>
#include <fstream>
#include<windows.h>//头文件 
using namespace std;
#include"Story.h"
#include"Interface.h"

int main()
{
    Interface n;
    n.print(0);
    cout<<"欢迎来到文字后宫！请输入封面按钮中的文字开始游戏：";
    string str;
    while (1)
    {
        cin>>str;
        if (str=="PLAY")
        {
            break;
        }
        cout<<"您的输入有误，请重新输入：";
    }
    Story m;
    while(1){
        m.Print();
        char c;
        cin>>c;
        m.GetNextNode(c);
        if (m.GetState()==0){
            cout<<"游戏结束"<<endl;
            break;
        }
    }
	return 0;
}

