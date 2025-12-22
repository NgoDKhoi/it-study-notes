#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int countSimpleVertex(vector<vector<int>>graph){
    int n=graph.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!graph[i].size())  cnt++;
    }
    return cnt;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int > > graph(m);
    while(n){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        --n;
    }
    cout<<countSimpleVertex(graph);
}