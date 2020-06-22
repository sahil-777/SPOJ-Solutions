/*
Problem code : EIGHTS (from SPOJ)
Concept : Ad-hoc.
Date : 22/06/2020
*/
#include<iostream>
using namespace std;

int main(){
	long long T;
	cin>>T;
	while(T--){
		long long N;
		cin>>N;
		cout<<192+(N-1)*250<<"\n";
	}
}
