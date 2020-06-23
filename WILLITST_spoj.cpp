/*
Problem code : WILLITST (from SPOJ)
Concept : Ad-hoc. 
Date : 23/06/2020
*/

#include<iostream>
#include<vector>
# define SIZE 50000
using namespace std;

int main()
{
	unsigned long long N,f=1;
	cin>>N;
	while(N>2){
		if(N&1){
			f=0;
			break;
		}
		N=N/2;
	} 
	if(f)cout<<"TAK\n";else cout<<"NIE\n";
    return 0;
} 
