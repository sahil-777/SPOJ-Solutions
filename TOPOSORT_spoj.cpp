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
long long in_degree[SIZE];			 
priority_queue<long long,vector<long long>,greater<long long>> pq;
vector<long long>answer;

void kahns_topo(long long N){
	
	for(long long i=1;i<=N;i++)
		if(in_degree[i]==0)
			pq.push(i);
			
	while(!pq.empty()){
		long long u=pq.top();
		answer.push_back(u);
		pq.pop();
		for(long long child:adj[u]){
			in_degree[child]--;
			if(in_degree[child]==0)
				pq.push(child);
		}
	}
	
	if(answer.size()!=N)
	cout<<"Sandro fails.\n";
	else
	for(long long node:answer)
	cout<<node<<" ";		
	//cout<<"\n";
} 
 
int main()
{
	long long N,M;
	cin>>N>>M;
	
	long long i,j,x,y;
	 
	while(M--){
		cin>>x>>y;
		adj[x].push_back(y);
		in_degree[y]++;  
	}
	
	kahns_topo(N);
	
	return 0;
}
 
