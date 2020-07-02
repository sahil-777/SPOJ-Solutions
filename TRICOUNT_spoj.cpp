/*
Problem code : TRICOUNT (from SPOJ)
Concept : Ad-hoc, Maths, formula based.
Date : 02/07/2020
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
#define SIZE 100005

 
int main()
{ 
	long long T;
	cin>>T;
	while(T--){
		long long N;
		cin>>N;
		if(N&1)
		cout<<(N* (N+2)* (2*N+1)-1)/8<<"\n";	
		else
		cout<<(N* (N+2)* (2*N+1)+1)/8<<"\n";
	}
	return 0;
}
  
