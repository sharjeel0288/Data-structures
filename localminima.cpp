#include<iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cout<<"Enter length : ";
    cin>>n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"-> ";
        cin>>arr[i];
    }
    int l,r;
    for(int i=0;i<n;i++)
    {
        if(i-1>=0)
        l=arr[i-1];
        else l=INT8_MAX;
        if(i+1<n)
        r=arr[i+1];
        else r=INT8_MAX;
        // cout<<"l : "<<l<<"   r : "<<r<<"   arr[i] : "<<arr[i]<<endl;
        if(arr[i]<= l && arr[i]<=r)
        {
            cout<<"Local minima is at index : "<<i;
            return 0;
        }
    }
    return 0;
}