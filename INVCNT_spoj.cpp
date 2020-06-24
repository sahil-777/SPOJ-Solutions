/*
Problem code : INVCNT (from SPOJ)
Concept : Merge-Sort.
Date : 25/06/2020
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
 
long long merge(long long A[], long long l, long long m, long long r){
	long long n1=m-l+1;
	long long n2=r-m;
	long long L[n1],R[n2],i,j,cnt=0;
 
	for(i=0;i<n1;i++)
		L[i]=A[l+i];
	
	for(j=0;j<n2;j++)
		R[j]=A[m+1+j]; 
	
	long long k=l;i=0;j=0;
	while((i<n1)and(j<n2)){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		 	cnt+=(m-i-l+1);
		}
		k++;
	}
	
	while(i<n1){
		A[k]=L[i];
		i++;k++;
	}
	
	while(j<n2){
		A[k]=R[j];
		j++;k++;
	}
 
	return cnt;
}

long long mergesort(long long A[], long long l, long long r){
	long long cnt=0;
	if(l<r){
		long long m=l+(r-l)/2;
		 
		cnt+=mergesort(A,l,m);
		cnt+=mergesort(A,m+1,r);
		
		cnt+=merge(A,l,m,r);
	}
	return cnt;
}

int main(){
	long long T;
	cin>>T;
	while(T--){
		long long N;
		cin>>N;
		long long A[N];
		for(long long i=0;i<N;i++)
			cin>>A[i];
	 	 	
		long long k=mergesort(A,0,N-1);
		cout<<k<<"\n";
	}
	return 0;
}
