#include<iostream>
using namespace std;

int main()
{
    int i;
    int *p;
    p = new int[5];
    p[0]=5;p[1]=10;p[2]=15;p[3]=20; p[4]=25;
    int *q;
    q = new int[10];
    for(i=0;i<10;i++)
    {
        q[i] = 0;
    }

    for(i=0;i<5;i++)
    {
        q[i] = p[i];
    }

    for(i=0;i<10;i++)
    {
        cout<<q[i]<<"\t";
    }
    delete[] p;
    delete[] q;
    return 0;
}