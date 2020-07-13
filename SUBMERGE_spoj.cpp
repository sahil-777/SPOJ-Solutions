/*
Problem code : SUBMERGE (from SPOJ)
Concept : Articulation point, DFS.
Date : 09/07/2020
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<queue>
#include<stack>
using namespace std;
#define SIZE 100001

vector<long long>adj[SIZE];
bool visited[SIZE];
long long parent[SIZE];
long long in_time[SIZE];
long long low[SIZE];

set<long long>s;// Use set to count number of Articulation points, don't use counter
long long timer =0,ch=0;
bool AP[SIZE];
void dfs_AP(long long u ){
	
	visited[u]=1;
	in_time[u]=timer;
	low[u]=timer;
	timer++;
	ch=0;
	
	for(long long child : adj[u]){
		
		if(visited[child]==0){
			parent[child] = u;	
			ch++;		
			dfs_AP(child);
			low[u]=min(low[child],low[u]);
			
			if((parent[u]==-1) and(ch>1))
			AP[u]=true,s.insert(u);
			if((parent[u]!=-1)and(low[child]>=in_time[u]))
			AP[u]=true,s.insert(u);
			}
			else if(parent[u]!=child){
			low[u]=min(in_time[child],low[u]);
			}
		}
}

int main()
{
 
	long long N,M;
	cin>>N>>M;
	
	while((N!=0)and(M!=0))
	{
	long long i,x,y;
	
	for(i=1;i<=N;i++){
		visited[i]=0;
		parent[i]=-1;
		low[i]=INT32_MAX;
		adj[i].clear();
		AP[i]=false;
	}
	
	
	 
	for(i=0;i<M;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
    
	dfs_AP(1);
	
	cout<< s.size()<<"\n";
 
	timer=0;
	s.clear();
	cin>>N>>M;
	 
}

	return 0;
}

 
