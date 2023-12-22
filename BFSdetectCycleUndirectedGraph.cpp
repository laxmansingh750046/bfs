#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<class T>
class graph{
 public:
 unordered_map<T,list<T>>adj;
 void addedge(T u,T v){
     adj[u].push_back(v);
     adj[v].push_back(u);
}
 
 void printgraph(){
   for(auto i:adj){
      cout<<i.first<<" ->";
      for(auto j:i.second){
          cout<<j<<",";
      }cout<<endl;
   }
 }     
 };
 
 bool isCycleBFS(unordered_map<int,list<int>>& adj,int firstNode){
      unordered_map<int,bool>visited;
      unordered_map<int,int>parent;
     
     
      queue<int>qu;
        visited[firstNode]=true;
        parent[firstNode]=-1;
        qu.push(firstNode);
        
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            for(const int& x:adj[curr]){
                if(!visited[x]){
                   visited[x]=true;
                   parent[x]=curr;
                   qu.push(x);
                }
                else if(x != parent[curr]){
                    return true;
                }
        }
        }
        return false;
}
 int main(){
    graph<int>g;
    int m;
    cout<<"Enter number of edges :";
    cin>>m;
    for(int i=0;i<m;i++){
       int u,v;
       cout<<"Enter starting and ending nodes of edge "<<i+1<<" :";
       cin>>u>>v;
       g.addedge(u,v);
    }
    g.printgraph();
    int startNode;
    cout<<"Enter starting node :";
    cin>>startNode;
    
   cout<<isCycleBFS(g.adj,startNode);  
   return 0;
 }
