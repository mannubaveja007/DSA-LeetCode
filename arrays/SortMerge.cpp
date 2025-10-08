#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n1, n2;
    cout<<"Enter the size for array 1: "<<endl;
    cin>>n1;
    int arr1[n1];

    cout<<"Enter the elements for first array: "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    

    cout<<"Enter the size for array 2: "<<endl;
    cin>>n2;    
    int arr2[n2];
    cout<<"Enter the elements for second array: "<<endl;
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }

    insertionSort(arr1, n1);
    insertionSort(arr2, n2);

    int n = n1+n2;
    int A[n];
    int i=0, j=0, k=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            A[k++]=arr1[i++];
        }   
        else
        {
            A[k++]=arr2[j++];
        }
    }
    for(; i<n1; i++)
    {
        A[k++]=arr1[i];
    }
    for(; j<n2; j++)
    {
        A[k++]=arr2[j];
    }
    
    cout<<"The new array is: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<"\t";
    } 

    return 0;
}