/*
Problem code : NAKANJ (from SPOJ)
Concept : BFS on grid.
Date : 30/06/2020
*/
 
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define SIZE 81
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string U,V;
        cin>>U>>V;
        pair<int,int>u,v;
        u.first=U[0]-96;u.second=U[1]-48;
        v.first=V[0]-96;v.second=V[1]-48;
        int i,j;
        int P[8][2]={{-2,1},{-2,-1},{2,1},{2,-1},{-1,2},{-1,-2},{1,2},{1,-2}},fr,sc;
        
        
		queue<pair<int,int> >q;
        bool visited[9][9];
        int dist[9][9];
        for(i=1;i<=8;i++)
        
		for(j=1;j<=8;j++){
			visited[i][j]=0;dist[i][j]=0;
			}
        
		pair<int,int>s; 
        q.push(u);
        visited[u.first][u.second]=1;
        while(!q.empty())
        {
            s=q.front();
            q.pop();
            for(i=0;i<8;i++)
            {
                fr=s.first+P[i][0];
                sc=s.second+P[i][1];
                if(((fr>=1)and(fr<=8)and(sc>=1)and(sc<=8))and(visited[fr][sc]==0))
                {
                    visited[fr][sc]=1;
                    q.push(make_pair(fr,sc));
                    dist[fr][sc]=dist[s.first][s.second]+1;
                }
            }
                
            
        }
        cout<<dist[v.first][v.second]<<"\n";
    }
    return 0;
} 
