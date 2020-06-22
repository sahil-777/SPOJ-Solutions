/*
Problem code : CANDY3 (from SPOJ)
Concept : Ad-hoc.
Date : 22/06/2020
*/

#include<iostream>
using namespace std;

int main(){
	 long long T;
	 cin>>T;
	 while(T--){
	 	long long N,sum=0,val;
	 	cin>>N;
	 	for(long long i=0;i<N;i++){
	 		cin>>val;
	 		sum+=val%N;
		 }
		 if(sum%N==0)cout<<"YES\n";
		 else
		 cout<<"NO\n";
	}
	return 0;	
} 
