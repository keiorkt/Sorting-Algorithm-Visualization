#include "sorting.h"
#include <QRandomGenerator>

Sorting::Sorting(QObject* parent) : QThread(parent){
}

void Sorting::run(){
    shuffle(arr,size);
    if (algorithm == "Bubble Sort"){
        sort_bubble(arr,size);
    } else if (algorithm == "Selection Sort"){
        sort_selection(arr,size);
    } else if (algorithm == "Insertion Sort"){
        sort_insertion(arr,size);
    } else if (algorithm == "Quicksort"){
        sort_quick(arr,size,0,size-1);
    } else if (algorithm == "Cocktail Sort"){
        sort_cocktail(arr,size);
    }
}

void Sorting::shuffle(int* arr,int size){
    for (int i=0;i<size;++i){
        int j = QRandomGenerator::global()->bounded(0,i+1);
        swap(arr,size,i,j);
    }
}

void swap(int* arr,int size,int i,int j){
    if (i>=size || j>=size || i==j){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Sorting::createArray(){
    arr = new int[size];
    for (int i=0;i<size;++i){
        arr[i] = i+1;
    }
    shuffle(arr,size);
    int index[1] = {0};
    emit changed(arr,index);
}

void Sorting::sort_bubble(int *arr, int size){
    for (int max_index=size-1;max_index>0;--max_index){
        for (int i=0;i<max_index-1;++i){
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
            }
            int color[1] = {i};
            coloring(arr,color);
        }
    }
}

void Sorting::sort_insertion(int* arr, int size){
    for (int i=1;i<size;++i){
        int temp = i;
        while (temp>=1 && arr[temp-1]>arr[temp]){
            swap(arr,size,temp-1,temp);
            int color[1] = {temp};
            coloring(arr,color);
            --temp;
        }
    }
}

void Sorting::sort_selection(int *arr, int size){
    for (int i=0;i<size;++i){
        int minindex = i;
        int minvalue = arr[i];
        for (int j=i+1;j<size;++j){
            if (arr[j]<minvalue){
                minindex = j;
                minvalue = arr[j];
            }
            int color[2] = {i,j};
            coloring(arr,color);
        }
        swap(arr,size,i,minindex);
    }
}

void Sorting::sort_quick(int*arr,int size,int start,int end){
    if (start >= end){
        return;
    }

    int pivot = arr[end];
    int left = start;
    int right = end-1;

    while (true){
        while (arr[left]<pivot && left<end){
            int color[1] = {left};
            coloring(arr,color);
            ++left;
        }
        while (arr[right]>=pivot && right>left){
            int color[2] = {left,right};
            coloring(arr,color);
            --right;
        }
        if (left == end){
            sort_quick(arr,size,start,end-1);
            break;
        } else if (left == right){
            swap(arr,size,left,end);
            sort_quick(arr,size,start,left-1);
            sort_quick(arr,size,left+1,end);
            break;
        } else {
            swap(arr,size,left,right);
            continue;
        }
    }
}

void Sorting::sort_cocktail(int* arr, int size){
    int start = 0;
    int end = size-1;
    bool changed;
    while (start<end){
        changed = false;
        for (int i=start;i<end;++i){
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
                changed = true;
            }
            int color[1] = {i};
            coloring(arr,color);
        }
        --end;
        if (changed == false){
            break;
        }
        for (int i=end;i>start;--i){
            if (arr[i]<arr[i-1]){
                swap(arr,size,i-1,i);
                changed = true;
            }
            int color[1] = {i};
            coloring(arr,color);
        }
        if (changed == false){
            break;
        }
        ++start;
    }
}

void Sorting::coloring(int* arr, int* colorindex){
    emit changed(arr,colorindex);
    this->usleep(animDelay);
}