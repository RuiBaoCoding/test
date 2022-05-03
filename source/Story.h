#ifndef _STORY_H_
#define _STORY_H_

//typedef struct Plot* P;
struct Plot{
    string title;
    string body;
    int flag;//0��ʾδ���ʹ���1��ʾ���ʹ�
};

struct Node{
    bool choice = true;
    int left;
    int right;
};

class Story{
private:
    map<int,struct Plot> Plotm;//���-���
    int State;//��¼��ǰ����Ľڵ����
    map<int,struct Node> Link; //���-���Һ���
    int PlotNum;
public:
    Story();
    void Print();
    bool GetNextNode(char c);
    int GetState();
};

#endif