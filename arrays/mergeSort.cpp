#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements for arrray: "<<endl;
    cin>>n;
    int arr[n]={0};
    cout<<"Enter the elements for array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Displaying the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    
    

    return 0;
}