/*
Problem code : CANTON (from SPOJ)
Concept : Ad-hoc.
Date : 25/06/2020
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
using namespace std;
 
int main()
{
    long long T;
    cin>>T;
    while(T--)
    {
    	long long N,X,sub,sum;
        cin>>X;
        N=ceil((-1+sqrt(1+8*X))/2);
        sub = X - N*(N-1)/2;
        sum = N+1;
        if (N%2==0)
        	cout<<"TERM "<<X<<" IS "<<sub<<"/"<<sum-sub<<"\n";
        else
            cout<<"TERM "<<X<<" IS "<<sum-sub<<"/"<<sub<<"\n";
    }
    return 0;
}
