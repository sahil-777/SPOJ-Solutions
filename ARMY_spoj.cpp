/*
Problem code : ARMY (from SPOJ)
Concept : Ad-hoc.
Date : 25/06/2020
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
 
int main()
{
	int T,ng,nm,i;
	cin>>T;
	while(T--){
		cin>>ng>>nm;
		int g[ng],m[nm];
		
		for(i=0;i<ng;i++)
		cin>>g[i];
		
		for(i=0;i<nm;i++)
		cin>>m[i];
		
		sort(g,g+ng);
		sort(m,m+nm);
		
		if(g[ng-1]>=m[nm-1])
		cout<<"Godzilla"<<endl;
		else
		cout<<"MechaGodzilla"<<endl;
	}
	return 0;
}

