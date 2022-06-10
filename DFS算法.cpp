//以邻接表G做深度优先
#include<iostream>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef char VertexType;

typedef struct ArcNode{
    int adjvex;                 //该弧所指向顶点的位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
    //InfoType *info;           记录元素信息
}ArcNode;


typedef struct VNode{
    VertexType data;            //顶点信息
    ArcNode *firstarc;          //指向第一条依附该结点的弧
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;            //数组
    int vexnum,arcnum;          //图的当前顶点数和弧数
    int kind;
}ALGraph;

//采用邻接表储存表示 构造无向图G
void CreateUDG(ALGraph &G)
{
    cin>>G.vexnum>>G.arcnum;        //cin>>IncInfo  输入图的顶点个数 弧数
    for(int i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;    //输入顶点值
        G.vertices[i].firstarc=NULL;//初始化链表头指针为空
    }
    
}

bool visited[100];                  //visited函数在两层函数中均要起作用
void DFSTraverse(ALGraph G)
{
    int v;
    for(v=0;v<G.vexnum;v++)
        visited[v]=false;           //该结点未被访问过
    for(v=0;v<G.vexnum;v++)
    {
        if(!visited[v])
            DFS(G,v);
    }
}


//从第v个顶点出发递归地深度优先遍历图G
void DFS(ALGraph G,int v)
{
    ArcNode *p;
    int w;
    visited[v]=true;
    cout<<G.vertices[v].data;         //访问第v个结点
    for(p=G.vertices[v].firstarc;p;p=p->nextarc)
    {
        w=p->adjvex;
        if(!visited[w])                 //w结点未被访问过
            DFS(G,w);
    }
}

int main()
{
    ALGraph G;
}