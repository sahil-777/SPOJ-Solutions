/*
Problem code : STAMPS (from SPOJ)
Concept : Ad-hoc.
Date : 25/06/2020
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
 
int main(){
	long long T,i,l,j;
	cin>>T;
	for(l=1;l<=T;l++){
		long long N,mainsum;
		cin>>mainsum>>N;
		long long A[N];
		for(i=0;i<N;i++)
		cin>>A[i];
		
		sort(A,A+N,greater<long long>());
		long long sum=0;
		for(i=0;i<N;i++){
			sum+=A[i];
			if(mainsum<=sum)
			break;
		}
		
		cout<<"Scenario #"<<l<<":\n";
		if(i!=N)
		cout<<i+1<<"\n\n";
		else 
		cout<<"impossible\n\n";
		
	}
	return 0;
}
