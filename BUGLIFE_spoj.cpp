/*
Problem code : BUGLIFE (from SPOJ)
Concept : DFS, Bipartite graph test, 2-way colouring problem.
Date : 29/06/2020
*/

#include<iostream>
#include<set>
#include<vector>
#include<stack>
using namespace std;
#define SIZE 100001

vector<long long>adj[SIZE];
bool visited[SIZE];
stack<long long>st;
long long colour[SIZE];

bool dfs(long long s){
    st.push(s);
    visited[s]=1;
    long long i,u;
    while(!st.empty()){
        u=st.top();
        st.pop();
        //cout<<u<<" ";
        for(i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==0){
                visited[adj[u][i]]=1;
                st.push(adj[u][i]);
                colour[adj[u][i]]=colour[u]^1;
            }
            else if(colour[adj[u][i]]==colour[u]){
            	return false;
			}
        }
    }
    return true;
}


int main(){
    
	long long T,l;
    cin>>T;
    for(l=1;l<=T;l++){
    
	for(long long i=1;i<=SIZE;i++){
        visited[i]=0;
        colour[i]=0;
        adj[i].clear();
    }
    
    long long N,M;
    cin>>N>>M;
    long long i,j,x,y;
    for(i=0;i<M;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
	long long f=1;
	for(i=1;i<=N;i++){
		if(visited[i]==0){
			if(dfs(i)==0){
				f=0;
				break;
			}
		}
	}
	
	cout<<"Scenario #"<<l<<":\n";
	if(f==0)
	cout<<"Suspicious bugs found!\n";
	else
	cout<<"No suspicious bugs found!\n";
	 
    //cout<<dfs(1)<<"\n";// True if Bipartite
	}
	return 0;
}
