/*
Problem code : COINS (from SPOJ)
Concept : Dynamic Programming,Recursion.
Date : 20/06/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;
#define SIZE 1000000 

long long DP[SIZE],i;

long long findcoins(long long N){
	if(N<SIZE){
		if(DP[N]==-1){
			if((N==1)or(N==0))
			return DP[N];
			
			DP[N]=max(N,findcoins(N/2)+findcoins(N/3)+findcoins(N/4));
			return DP[N];
		}
		else 
		return DP[N]; 
	}
	else
	return max(N,findcoins(N/2)+findcoins(N/3)+findcoins(N/4));
}


int main(){
	for(i=0;i<SIZE;i++){
		DP[i]=-1; 
	}
	DP[0]=0;DP[1]=1;
	
	long long N;
   	while(cin>>N){
   		cout<<findcoins(N)<<"\n";
	}
   	return 0;
}


 




