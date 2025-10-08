#include<iostream>
using namespace std;

int main()
{
    int a[5]={3,5,7,9,11};
    int *p;
    p = new int[5];
    int p_values[5]={2,4,6,8,10};
    for(int i=0; i<5; i++)
    {
        p[i]=p_values[i];
    }
    for(int i=0; i<5; i++)
    {
        cout<<p[i]<<"\t";
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<"\t";
    }

    delete[] p;

    return 0;
}