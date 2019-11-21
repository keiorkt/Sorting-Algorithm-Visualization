#include "helper.h"
using namespace std;

bool sorted(int arr[], int size){
    for (int i=0; i<size-1; ++i){
        if (arr[i]>arr[i+1])
            return false;
    }
    return true;
}

void print(int arr[], int size) {
    cout<<"{"<<arr[0];
    for (int i=1;  i<size; ++i)
        cout<<","<<arr[i];
    cout<<"}"<<endl;
}

void swap(int arr[], int size, int i, int j){
    if (i>=size || j>=size)
        return;
    if (i==j)
        return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void substitude(int arr[], int size, int pos, int value){
    if (pos >= size)
        return;
    arr[pos] = value;
}

int findminindex(int arr[],int size,int start,int end){
    if (start == end)
        return start;
    int minindex = start;
    int min = arr[start];
    for (int i = start; i<=end; ++i){
        if (arr[i] < min){
            min = arr[i];
            minindex = i;
        }
    }
    return minindex;
}

void insert(int arr[],int size,int position){
    int i = position;
    while (true){
        if (i==0)
            break;
        if (arr[i] < arr[i-1]){
            swap(arr,size,i,i-1);
            i--;
        } else {
            break;
        }
    }
}

void randompermute(int arr[],int size){
    for (int i=1;i<size;++i){
        int j = rand()%(i+1);
        swap(arr,size,i,j);
    }
}
