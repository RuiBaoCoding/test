#include<iostream>
#include<map>
#include<string>
#include <fstream>
#include<windows.h>//м╥нд╪Ч

using namespace std;
#include"Interface.h"

Interface::Interface():N(7){
    for ( int i = 0 ; i < N ; i ++ ){
        ifstream infile; //build a file stream object
        infile.open((".\\picture\\"+to_string(i)+".txt").data());//Connect a file stream object to a file
        if (infile.is_open()){//if open fails,return false
            string s;
            string str="";
            while(getline(infile,s)){//read line by line
                str+=s+"\n";  
            }
            M[i]=str;
            infile.close(); //close file input stream
        }
    }
}    
void Interface::print(int x){
    cout<<M[x];
}