//���ڽӱ�G���������
#include<iostream>
using namespace std;

const int MAX_VERTEX_NUM=20;
typedef char VertexType;

typedef struct ArcNode{
    int adjvex;                 //�û���ָ�򶥵��λ��
    struct ArcNode *nextarc;    //ָ����һ������ָ��
    //InfoType *info;           ��¼Ԫ����Ϣ
}ArcNode;


typedef struct VNode{
    VertexType data;            //������Ϣ
    ArcNode *firstarc;          //ָ���һ�������ý��Ļ�
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;            //����
    int vexnum,arcnum;          //ͼ�ĵ�ǰ�������ͻ���
    int kind;
}ALGraph;

//�����ڽӱ����ʾ ��������ͼG
void CreateUDG(ALGraph &G)
{
    cin>>G.vexnum>>G.arcnum;        //cin>>IncInfo  ����ͼ�Ķ������ ����
    for(int i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;    //���붥��ֵ
        G.vertices[i].firstarc=NULL;//��ʼ������ͷָ��Ϊ��
    }
    
}

bool visited[100];                  //visited���������㺯���о�Ҫ������
void DFSTraverse(ALGraph G)
{
    int v;
    for(v=0;v<G.vexnum;v++)
        visited[v]=false;           //�ý��δ�����ʹ�
    for(v=0;v<G.vexnum;v++)
    {
        if(!visited[v])
            DFS(G,v);
    }
}


//�ӵ�v����������ݹ��������ȱ���ͼG
void DFS(ALGraph G,int v)
{
    ArcNode *p;
    int w;
    visited[v]=true;
    cout<<G.vertices[v].data;         //���ʵ�v�����
    for(p=G.vertices[v].firstarc;p;p=p->nextarc)
    {
        w=p->adjvex;
        if(!visited[w])                 //w���δ�����ʹ�
            DFS(G,w);
    }
}

int main()
{
    ALGraph G;
}