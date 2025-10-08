#include<iostream>
using namespace std;

int main()
{
    int i=0, j=0, n=0;
    cout<<"Enter the number of elements for array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements for array: "<<endl;
    for (i = 0; i<n;  i++)
    {
        cin>>arr[i];
    }
    
    //Reversing array
    for(i=0, j=n-1; i<j; i++, j--)
    {
        int temp = arr[i];
        arr [i] = arr[j];
        arr[j] = temp;
    }

    cout<<"The reversed array is: "<<endl;
    for (i = 0; i<n;  i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    cout<<"Left shift"<<endl;
    //Left Shift
    int temp = arr[0];
    for (int i = 0; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1] = temp;
    
    cout<<"The shifted array is: "<<endl;
    for (i = 0; i<n;  i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0;
}