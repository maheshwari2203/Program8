#include <iostream>
#include <climits>
using namespace std;
#define V 4
int minKey(int key[], bool mst[])
{ 
  int min=INT_MAX, idx; 
  for(int v=0;v<V;v++) 
    if(!mst[v] && key[v]<min)
      min=key[v], idx=v;
  return idx; 
}
int main()
{
    int graph[V][V]={{0,10,6,5},{10,0,0,15},{6,0,0,4},{5,15,4,0}};
    int parent[V], key[V];
     bool mstSet[V]={0};
    for(int i=0;i<V;i++) 
      key[i]=INT_MAX; 
      key[0]=0; 
       parent[0]=-1;
    for(int c=0;c<V-1;c++)
    { 
      int u=minKey(key,mstSet);
      mstSet[u]=true; 
      for(int v=0;v<V;v++) 
        if(graph[u][v] &&!mstSet[v] && graph[u][v]<key[v])
        { 
          parent[v]=u; 
          key[v]=graph[u][v]; 
        } 
    }
    cout<<"Edge Cost\n"; 
    int total=0;
    for(int i=1;i<V;i++)
    { 
      cout<<parent[i]+1<<" - "<<i+1<<" : "<<graph[i][parent[i]]; 
      cout<<endl;
      total+=graph[i][parent[i]];
     } 
     cout<<"Min Cost: "<<total;
    return 0;
}
