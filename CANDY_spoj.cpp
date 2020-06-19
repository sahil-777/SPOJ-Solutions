/*
Problem code : CANDY (from SPOJ)
Concept : Ad-hoc.
Date : 20/06/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;
 

int main(){
   	
	int N;
	cin>>N;
	while(N!=-1){
		
		int A[N];
		int i,j,sum=0;
		for(i=0;i<N;i++){
			cin>>A[i];
			sum+=A[i];
		}  
		if(sum%N!=0)cout<<-1<<"\n";
		else{
			int cnt=sum/N;
			sum=0;
			for(i=0;i<N;i++)
			{
				if(A[i]>cnt)
				sum+=(A[i]-cnt);
			}
			cout<<sum<<"\n";
		}
		cin>>N;
		
	}
	return 0;
}


 




