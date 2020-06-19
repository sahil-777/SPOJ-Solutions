/*
Problem code : TOANDFRO (from SPOJ)
Concept : Implementation.
Date : 20/06/2020
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;

int main() {
 int i,j,k,t,n,e;
 string s;
 
 while(1)
 {
     cin>>n;
     if(n==0)
     return 0;
     cin>>s;
     long len=s.length();
     char a[len/n][205];
     e=0,k=0;
    for(i=0;i<len;i++)
    {
        if(e==0)
        {
            for(j=0;j<n;j++)
            {
            a[k][j]=s[i];
            i++;
            }
            k++;
            e=1;
        }
        else
        {
            for(j=n-1;j>=0;j--)
            {
                a[k][j]=s[i];
                i++;
                
            }
            k++;
            e=0;
        }
        i--;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<(len/n);j++)
        cout<<a[j][i];
    }
    cout<<"\n";
   
 }
 return 0;
}

