#include<iostream>
using namespace std;

int main()
{
/*  Finding missing elements

    For unsorted
    int arr[10]={3,7,4,9,12,6,1,11,2,10};

    int m;
    m = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]>m)
        {
            m = arr[i];
        }
    } 

    int l=arr[0], u=m, n=10;
    int hash_array[m+1]={0};
    for (int i = 0; i < n; i++)
    {
        hash_array[arr[i]]++;
    }
    for (int i = l; i <= u; i++)
    {
        if (hash_array[i]==0)
        {
            cout<<i<<"\t";
        } 
    }     
 
    for n natural numbers
    int l=arr[0], u=arr[8], n = 10;
    int diff = l-0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i]-i)
            {
                cout<<"Missing element = "<<i+diff<<endl;
                diff++;
            }
        }    
    }


   
    for first n natural numbers
    int sum1=0, sum2=0, n=10;
    for (int i = 0; i < 9; i++)
    {
        sum1 += arr[i];
    }
    
    sum2 = n*(n+1)/2;

    if (sum1<sum2)
    {
        cout<<sum2 - sum1;
    }
    else
    {
        cout<<"0";
    }
*/
    return 0;
}