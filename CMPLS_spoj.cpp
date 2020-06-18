
/*
Problem code : CMPLS (from SPOJ)
Concept : Method of Differences, Lagrange's Polynomial.
Date : 18/06/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;
 

int main(){
   	
	int T;
	cin>>T;
	while(T--){
		int N,C,i,j,val,cnt;
		cin>>N>>C;
		vector<int>a,diff,orig;
		vector<int>::iterator k;
		for(i=0;i<N;i++){
			cin>>val;
			a.push_back(val);
			orig.push_back(val);
		}
		
		if(N==1){
			for(i=0;i<C;i++)
			cout<<a[0]<<" ";
		}
		else{
		//cout<<*(a.end()-1)<<"\n";
		set<int>unq;
		for(j=0;j<C;j++){
			cnt=*(a.end()-1);
			//cout<<cnt<<"\n";
			while(unq.size()!=1){
				unq.clear();
				for(i=0;i<a.size()-1;i++){
					//diff.push_back(a[i+1]-a[i]);
					//unq.insert(a[i+1]-a[i]);
					a[i]=a[i+1]-a[i];
					unq.insert(a[i]);
				}
				k=a.end()-1;
				a.erase(k);
				cnt+=a[a.size()-1];
				//cout<<cnt<<"\n";
			}
			cout<<cnt<<" ";
			a.clear();
			unq.clear();
			a=orig;
			a.push_back(cnt);
			orig=a;
			//cout<<a.size()<<" *\n";
		}
		}
		cout<<"\n";
	}
	return 0;
}


 




