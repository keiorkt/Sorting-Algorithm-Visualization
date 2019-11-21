#include "algorithms.h"
using namespace std;

void bubble(int arr[], int size){
    bool changed = true;
    while (changed){
        changed = false;
        for (int i=0;i<size-1;++i){
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
                changed = true;
                print(arr,size);
            }
        }
    }
}

void insertion(int arr[], int size){
    for (int i=1; i<size; ++i){
        insert(arr,size,i);
        print(arr,size);
    }
}

void selection(int arr[], int size){
    for (int i=0; i<size; ++i){
        int minindex = findminindex(arr,size,i,size-1);
        swap(arr,size,i,minindex);
    }
}

void quick(int arr[],int size,int start,int end){
    if (start >= end)
        return;
    
    int pivot = arr[end];
    int left = start;
    int right = end-1;
    
    while (true){
        while (arr[left] < pivot && left < end){
            left++;
        }
        while (arr[right] >= pivot && right > left){
            right--;
        }
        
        if (left == end){
            quick(arr,size,start,end-1);
            break;
        } else if (left == right) {
            swap(arr,size,left,end);
            print(arr,size);
            quick(arr,size,start,left-1);
            quick(arr,size,left+1,end);
            break;
        } else {
            swap(arr,size,left,right);
            print(arr,size);
            continue;
        }
    }
}

void cocktail(int arr[],int size){
    bool changed = true;
    while (changed){
        changed = false;
        for (int i=0;i<size-1;i++){
            if  (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
                changed = true;
                print(arr,size);
            }
        }
        for (int i=size-1;i>0;--i){
            if (arr[i]<arr[i-1]){
                swap(arr,size,i,i-1);
                changed = true;
                print(arr,size);
            }
        }
    }
}

void bogo(int arr[],int size){
    print(arr,size);
    while (sorted(arr,size) == false){
        randompermute(arr,size);
        print(arr,size);
    }
}
