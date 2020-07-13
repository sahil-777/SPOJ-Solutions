/*
Problem code : EC_P (from SPOJ)
Concept : Bridges, DFS.
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

long long timer =0;
vector<pair<long long,long long>>bridges;

void dfs_Bridge(long long u ){
	
	visited[u]=1;
	in_time[u]=timer;
	low[u]=timer;
	timer++;
	
	for(long long child : adj[u]){
		
		if(visited[child]==0){
			parent[child] = u;			
			dfs_Bridge(child);
			low[u]=min(low[child],low[u]);
			
			if(low[child]>in_time[u]){
			if(u<child) 	//don't swap() it will ruin program 
			bridges.push_back(make_pair(u,child ));
			else
			bridges.push_back(make_pair(child,u));
			}
		}
		else if(parent[u]!=child){
			low[u]=min(in_time[child],low[u]);
		}
	}
}

int main()
{
	long long T,l=0;
	cin>>T;
	while(T--){
	long long N,M;
	cin>>N>>M;
	 
	long long i,x,y;
	
	for(i=1;i<=N;i++){
		visited[i]=0;
		parent[i]=-1;
		low[i]=INT32_MAX;
		adj[i].clear();
	}
	
	
	 
	for(i=0;i<M;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
    long long s=1;
	dfs_Bridge(s);
	
	l++;
	sort(bridges.begin(),bridges.end());
	cout<<"Caso #"<<l<<"\n";
	if(bridges.empty())
	cout<<"Sin bloqueos\n";
	else{
		cout<<bridges.size()<<"\n";
		for(pair<long long,long long> p:bridges)
		cout<<p.first<<" "<<p.second<<"\n";
	}
	
	timer=0;
	bridges.clear();
	
}
	return 0;
}

 
