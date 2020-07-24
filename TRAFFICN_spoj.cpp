/*
Problem code : TRAFFICN (from SPOJ)
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
#include<stack>
using namespace std;
#define SIZE 100001
#define INF  1e9
#define ll   long long					 

set<pair<ll,ll>>sp;
ll cost1[SIZE],cost2[SIZE];
vector<pair<ll,ll>>adj1[SIZE],adj2[SIZE];

void dijkstra(ll s,vector<pair<ll,ll>>adj[],ll cost[]){
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
		ll N,M,K,Start,Desti;
		cin>>N>>M>>K>>Start>>Desti;
		
		for(ll i=1;i<=N;i++){
			adj1[i].clear();
			adj2[i].clear();
			cost1[i]=INF;
			cost2[i]=INF;
		}
		while(M--){
			ll x,y,w;
			cin>>x>>y>>w;
			adj1[x].push_back(make_pair(y,w));
			adj2[y].push_back(make_pair(x,w));
		}
		dijkstra(Start,adj1,cost1);
		dijkstra(Desti,adj2,cost2);
 
		ll ans=INF;
		if(K==0)
		cout<<cost1[Desti]<<"\n";
		else{
		while(K--){
			ll u,v,w;
			cin>>u>>v>>w;
			ans=min(ans, min(cost1[Desti], w+min(cost1[u]+cost2[v], cost1[v]+cost2[u]))) ;
		}
		if(ans==INF)ans=-1;
		cout<<ans<<"\n";
		}
	} 
    
    return 0;
}
