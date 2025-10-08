#include<iostream>
using namespace std;

class arrayFun
{
private:
    int *arr;
    int n=0;


public:
    arrayFun()
    {
        cout<<"Enter the number of elements for array: "<<endl;
        cin>>n;
        arr= new int[n];
        cout<<"Enter the elements for array: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
    }
    
    ~arrayFun()
    {
        delete[] arr;
    }

    void get(int index)
    {
        cout<<arr[index]<<endl;
    }

    void set(int index, int x)
    {
        arr[index]=x;
        cout<<"The updated elements for array: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

    void average()
    {
        int total=0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        cout<<"Sum = "<<total<<endl;

        int Average=0;
        Average=total/n;
        cout<<"Average = "<<Average<<endl;
    }

    void max()
    {
        int m;
        m = arr[0];
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>m)
            {
                m = arr[i];
            }
        }    
        cout<<"Max = "<<m<<endl;
    }

    void display()
    {
        cout<<"The elements for array are: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

};

int main()
{
    arrayFun A;
   
    A.get(2);
    A.max();
    A.average();
    A.set(3,69);

    A.display();

    return 0;
}