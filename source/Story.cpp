#include<iostream>
#include<map>
#include<string>
#include <fstream>
#include<windows.h>//头文件 
using namespace std;

#include"Story.h"
#include"Interface.h"

Story::Story():State(1),PlotNum(12){
    //构造Link
    ifstream infile; //build a file stream object
    string filename = "tree.txt";
    infile.open(filename.data());//Connect a file stream object to a file
    if (infile.is_open()){//if open fails,return false
        string s;
        while(getline(infile,s)){//read line by line
            int a[3];
            int cnt = 0; 
            string str = "";
            for ( int i = 0 ; i < s.length(); i ++ ){
                if (s[i]==' '){
                    a[cnt] = stoi(str);
                    str = "";
                    cnt ++;
                }else{
                    str += s[i];
                }
            }
            Link[a[0]].left=a[1];
            if (cnt == 2){
                Link[a[0]].choice=false;
            }else{
                Link[a[0]].right=a[2];
            }
        }
    }
    //end
    //通过读文件构造每个结构体以及map
    for(int i=1;i<=PlotNum;i++){
        ifstream infile; //build a file stream object
        infile.open((".\\story\\"+to_string(i)+".txt").data());//Connect a file stream object to a file
        if (infile.is_open()){//if open fails,return false
            string s;
            string str="";
            string T;//title;
            string B;//body
            int num=0;
            for(int j=0;getline(infile,s);j++){//read line by line
                if(j==0){//first line
                    num=atoi(s.c_str());//序号
                }else if(j==1){
                    T=s;
                }else{
                    B=B+s;//*→sleep
                }  
            }
            Plot CurrP;
            CurrP.title=T;
            CurrP.body=B;
            if(num==1){
                CurrP.flag=1;
            }else{
                CurrP.flag=0;
            }
            Plotm[num]=CurrP;
            infile.close(); //close file input stream
        }
    }
}
void Story::Print(){//打印第一个节点
    //test
    Interface m;
    cout<<"   "<<Plotm[State].title<<endl<<endl<<"    ";
    Sleep(600);
    //cout<<Plotm[State].body<<endl;
    int count=2;//count the number
    for(int i=0;i<(Plotm[State].body).length()-1;i=i+2){
        string a="";
        a=a+(Plotm[State].body)[i]+(Plotm[State].body)[i+1];
        if(a>="00"&&a<="07"){
            int ni=a[1]-'0';
            m.print(ni);
            Sleep(1000);
        }else if(a=="**"){
            count=2;
            cout<<endl<<endl<<"    ";
            Sleep(200);
        }else{
            count++;
            if(count==36){
                count=0;
                cout<<a;
                cout<<endl<<endl;
                Sleep(100);
            }else{
                cout<<a;
                Sleep(100);
            }
        }
    }
    //cout<<endl;
}
bool Story::GetNextNode(char c){
    if (Link[State].choice){
        switch(c){
            case 'A':
                State = Link[State].left;
                break;
            case 'B':
                State = Link[State].right;
                break;
            
            default:
                return false;
        }
    }else{
        State = Link[State].left ;
    }
    return true;
}
int Story::GetState(){
    return State;
}