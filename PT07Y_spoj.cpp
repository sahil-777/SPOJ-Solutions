/*
Problem code : PT07Y (from SPOJ)
Concept : Graph theory,DFS.
Date : 23/06/2020
*/

#include<iostream>
#include<vector>
# define SIZE 50000
using namespace std;

 
vector<int>adj[SIZE];
bool visited[SIZE];
bool flag=false;
 
void dfs(int s)
{
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(!visited[i])
        dfs(i);
        else
        {
            flag=1;
        }   
    }
}
 
 
int main()
{
    int N,M,i,j,x,y;
    cin>>N>>M;
    for(i=0;i<SIZE;i++)
    visited[i]=false;
    
    for(i=0;i<M;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
      //  adj[y].push_back(x);
    }
    
    for(i=1;i<=N;i++)
    {
        if(flag)
        break;
        if(!visited[i])
        dfs(i);
    }
    if(flag)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
    
    return 0;
} 
