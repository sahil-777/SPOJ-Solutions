/*
Problem code : PT07Z (from SPOJ)
Concept : Graph theory,DFS,BFS. This problem can also be solved by doing BFS two times.
Date : 23/06/2020
*/

#include <bits/stdc++.h>
using namespace std;
 
bool visited[10001];
int ans;
 
 
int DFS(vector<int> graph[],int start)
{
   int lgst = 0,lgst2 = 0;
   int temp = INT_MIN;
   
   visited[start] = 1;
   for(int i=0; i<graph[start].size() ;++i)
   {
      if(!visited[graph[start][i]])
      {
         temp = DFS(graph,graph[start][i]);
         
         if(temp >= lgst)
         {
           
            lgst2 = lgst;
            lgst = temp;
         }
          
         else if(temp > lgst2)
            lgst2 = temp;
      }	
   }
   ans = max(ans , lgst+lgst2);
   return lgst+1;
}
 
int main() {
   ios::sync_with_stdio(false);
   
   int n,u,v;
   cin>>n;
   
   vector<int> graph[n+1];
   
   for(int i=0;i<n-1 ;++i)	
   {
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   DFS(graph,1);
   
   cout<<ans<<"\n";
   
   return 0;
} 
