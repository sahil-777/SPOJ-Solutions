/*
Problem code : LASTDIG (from SPOJ)
Concept : Number Theory.
Date : 20/06/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;
 
long long pow(long long base,long long power,long long m)
{
    long long result=1;
    while (power>0)
    {
            if (power&1)
            	result = (result*base) % m;
            
			base = (base*base)%m;
            power/=2;
    }
    return result;
}


int main(){
	int T;
	cin>>T;
	while(T--){
		long long a,b;
		cin>>a>>b;
		cout<<pow(a,b,10)<<"\n";
	}
	return 0;
}
