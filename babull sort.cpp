#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	//Bubble Sort

    int a[100];
    int n,i,j;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(i=0; i<n; i++)
        cout<<a[i]<<endl;

    return 0;
}

