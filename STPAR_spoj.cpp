/*
Problem code : STPAR (from SPOJ)
Concept : stack.
Date : 23/06/2020
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int N;
	cin>>N;
	while(N!=0){
		int i,j;
		int A[N];
		for(i=0;i<N;i++)
		cin>>A[i];
		
		vector<int>v;
		stack<int>st;
		
		v.push_back(0);
	 
		for(i=0;i<N;i++){
 
			if(*(v.end()-1)+1==A[i])
			v.push_back(A[i]);
			else
			st.push(A[i]);
			
			while((!st.empty())and(st.top()==*(v.end()-1)+1)){
				v.push_back(st.top());
				st.pop();
			}
		}
		int f=0;
		for(i=0;i<=N;i++){
			if(i!=v[i]){
				f=1;
				break;
			}
		}
 
		if(f)cout<<"no\n";
		else
		cout<<"yes\n";	
		
		cin>>N;	
	}
	return 0;  
}
