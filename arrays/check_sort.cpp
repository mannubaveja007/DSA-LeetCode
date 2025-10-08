#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }
    
    int x=0;
    cout<<"Checking if the array is sorted..."<<endl;
    for(int i = 0; i<5-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            x=-1;
            break;
        }
    }
    if(x==0)
    {
        cout<<"Array is sorted."<<endl;
    }
    else
    {
        cout<<"Array is unsorted."<<endl;
    }

    return 0;
}