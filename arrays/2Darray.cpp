#include<iostream>
using namespace std;

int main()
{
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //In stack


    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }


    int *B[3]; //One in stack and one in Heap
    B[0] = new int[4]; 
    B[1] = new int[4];
    B[2] = new int[4];


    int **C; //Only in Heap
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];



    return 0;
} 