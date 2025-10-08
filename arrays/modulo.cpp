#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2,5,3,22,4,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size <<endl; 
    // for (int i = 1; i <= 20; i++)
    // {
    //     int modulo = (i-1) % size;
    //     cout<<arr[modulo]<<"\t";
    // }
    cout<<"Size of the given array is: "<<size<<endl;
    int count;
    cout<<"enter the number of times to repeat the loop for: "<<endl;
    cin>>count;

    for (int i = 1; i <= count; i++)
    {
        int modulo = (i-1) % size;
        cout<<arr[modulo]<<"\n";
    }
    
    return 0;
}