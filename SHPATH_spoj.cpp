/*
Problem code : SHPATH (from SPOJ)
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
map<string,int>sm;

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
    
	ll T;
	cin>>T;
	while(T--){
		ll total_cities,i,M,x,y,w;
		cin>>total_cities;
		sm.clear();
		for(i=1;i<=total_cities;i++)
		adj[i].clear();
		for(i=1;i<=total_cities;i++){
			string S;
			cin>>S;
			sm.insert({S,i});
			
			cin>>M;
			while(M--){
				x=i;
				cin>>y>>w;
				adj[x].push_back(make_pair(y,w));
			}
		}
		
		ll Paths;
		cin>>Paths;
		while(Paths--){
			string Start,Desti;
			cin>>Start>>Desti;
			for(i=1;i<=total_cities;i++){
				cost[i]=INF;
				
			}
			dijkstra(sm[Start]);
			cout<<cost[sm[Desti]]<<"\n";
		}
	} 
    return 0;
}
