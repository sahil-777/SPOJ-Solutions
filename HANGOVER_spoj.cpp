/*
Problem code : HANGOVER (from SPOJ)
Concept : Ad-hoc.
Date : 22/06/2020
*/
#include<iostream>
using namespace std;

int main(){
	 double A[300],sum[276];
	 long long i;A[0]=0;
	 for(i=1;i<=300;i++){
	 	A[i]=A[i-1]+double(1/(double(i)+1));
	 }
 
	 double val;
	 cin>>val;
	 while(val!=0){
	 	for(i=1;i<=300;i++){
	 		if(A[i]>=val){
	 			cout<<i<<" card(s)\n";
	 			break;
			 }
		 }
		 cin>>val;
	 }
}
