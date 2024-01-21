#include<bits/stdc++.h>
using namespace std;
void merge(int arr[ ], int first, int mid, int last);
void mergesort(int arr[ ], int first, int last)
{
    if(first < last)
    {
        int mid = (first + (last - 1))/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}
void merge(int *arr, int first, int mid, int last)
{
    int k;
    int leftarraysize = mid - first + 1;
    int rightarraysize = last - mid;
    int array1[leftarraysize], array2[rightarraysize];

    for(int i = 0; i < leftarraysize; i++)
    {
        array1[i] = arr[first + i];
    }
    for(int j = 0; j < rightarraysize; j++)
    {
        array2[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0;
    k = first;
    while(i < leftarraysize && j < rightarraysize)
    {
        if(array1[i] <= array2[j])
        {
            arr[k] = array1[i];
            i++;
        }
        else
        {
            arr[k] = array2[j];
            j++;
        }
        k++;
    }
    while(i < leftarraysize)
    {
        arr[k] = array1[i];
        i++;
        k++;
    }
    while(j < rightarraysize)
    {
        arr[k] = array2[j];
        j++;
        k++;
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int i = 0,arr[ ] = {5,4,3,2,1};
    int arr[5],i = 0;
    for(i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,arr_size-1);
    for(i = 0; i < arr_size; i++)
    {
        cout<<arr[i]<<" ";
    }

}