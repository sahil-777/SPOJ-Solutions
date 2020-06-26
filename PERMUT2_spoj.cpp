/*
Problem code : PERMUT2 (from SPOJ)
Concept : Ad-hoc.
Date : 26/06/2020
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<sstream>
using namespace std;

 
int main()
{
	long long N;
	cin>>N;   
    while(N!=0)
    {
    	long long i,j,A[N+1],pos[N+1],f=1;
		for(i=1;i<=N;i++)
			cin>>A[i];
			 
		for(i=1;i<=N;i++){
			if(A[A[i]]!=i){
				f=0;
				break;
			}
		}
			 
		
		if(f)
		cout<<"ambiguous\n";
		else
		cout<<"not ambiguous\n";
		 
		
    	cin>>N; 
    }
    return 0;
}
