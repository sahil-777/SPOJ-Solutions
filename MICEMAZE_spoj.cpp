/*
Problem code : MICEMAZE (from SPOJ)
Concept : SSSP, Dijkstra.
Date : 24/07/2020
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define SIZE 100001
#define INF  1e9
#define ll   long long					 

set<pair<ll,ll>>sp;
ll cost[SIZE];
vector<pair<ll,ll>>adj[SIZE]; 

void dijkstra( ll s ){
	sp.insert(make_pair(0,s));
	cost[s]=0;
	while(!sp.empty()){
		pair<ll,ll>temp=*sp.begin();
		sp.erase(sp.begin());
		ll u=temp.second;
		for(pair<ll,ll>child : adj[u]){
			ll v=child.first;
			ll w=child.second;
			if(cost[v]>cost[u]+w){
				if(cost[v]!=INF)
				sp.erase(sp.find(make_pair(cost[v],v)));
				
				cost[v]=cost[u]+w;
				sp.insert(make_pair(cost[v],v));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,E,T,M;
    cin>>N>>E>>T>>M;
    while(M--){
    	ll x,y,w;
    	cin>>x>>y>>w;
    	adj[y].push_back(make_pair(x,w));
	}
	ll cnt=0;
	
	for(ll i =1;i<=N;i++)
	cost[i]=INF;
	
	dijkstra(E);
	
	for(ll i=1;i<=N;i++){
		if(cost[i]<=T)
		cnt++;
	}
	cout<<cnt<<"\n"; 
    return 0;
}
