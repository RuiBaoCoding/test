#ifndef _STORY_H_
#define _STORY_H_

//typedef struct Plot* P;
struct Plot{
    string title;
    string body;
    int flag;//0表示未访问过，1表示访问过
};

struct Node{
    bool choice = true;
    int left;
    int right;
};

class Story{
private:
    map<int,struct Plot> Plotm;//序号-情节
    int State;//记录当前到达的节点序号
    map<int,struct Node> Link; //序号-左右孩子
    int PlotNum;
public:
    Story();
    void Print();
    bool GetNextNode(char c);
    int GetState();
};

#endif