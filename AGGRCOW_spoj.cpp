/*
Problem code : AGGRCOW (from SPOJ)
Concept : Binary Search.
Date : 21/06/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h> 
#include<iterator>
using namespace std;

int N,C;

int func(int num,int array[])
{
    int cows=1,pos=array[0];
    for (int i=1; i<N; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==C)
                return 1;
        }
    }
    return 0;
}
int bs(int array[])
{
    int ini=0,last=array[N-1],max=-1;
    while (last>ini)
    {
        //cout<<last<<" "<<ini<<endl;
        int mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            //cout<<mid<<endl;
            if (mid>max)
                max=mid;
            ini=mid+1;
        }
        else
            last=mid;
    }
    return max;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>N>>C;
        int array[N];
        for (int i=0; i<N; i++)
		cin>>array[i];
        sort(array,array+N);
        cout<<bs(array)<<"\n";
    }
    return 0;
} 
