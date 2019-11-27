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
    } else if (algorithm == "Merge Sort"){
        sort_merge(arr,size,0,size-1);
    } else if (algorithm == "Heap Sort"){
        sort_heap(arr,size);
    }
}

void Sorting::shuffle(int* arr,int size){
    for (int i=0;i<size;++i){
        int j = QRandomGenerator::global()->bounded(0,i+1);
        swap(arr,size,i,j);
    }
}

void Sorting::swap(int* arr,int size,int i,int j){
    if (i>=size || j>=size || i==j){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Sorting::merge(int* arr,int size,int start,int end){
    int div = (start+end)/2;
    int lsize = div-start+1;
    int rsize = end-div;

    int* L = new int[lsize];
    int* R = new int[rsize];

    for (int i = 0; i<lsize; ++i){
        L[i] = arr[start+i];
    }
    for (int i = 0; i<rsize;  ++i){
        R[i] = arr[div+1+i];
    }
    int left = 0;
    int right = 0;
    int merged = start;

    while (left<lsize && right<rsize){
        if (L[left] <= R[right]){
            arr[merged] = L[left];
            ++left;
            int color[2] = {merged,lsize+merged};
            coloring(arr,size,color,2);
        } else {
            arr[merged] = R[right];
            ++right;
            int color[2] = {merged,rsize+merged};
            coloring(arr,size,color,2);
        }
        ++merged;
    }

    while (left<lsize){
        arr[merged] = L[left];
        ++left;
        ++merged;
    }
    while (right<rsize){
        arr[merged] = R[right];
        ++right;
        ++merged;
    }
    delete [] L;
    delete [] R;
}

void  Sorting::heapify(int *arr, int size, int heapsize, int i){
    int maxindex = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<heapsize && arr[left]>arr[maxindex]){
        maxindex = left;
    }

    if (right<heapsize && arr[right]>arr[maxindex]){
        maxindex = right;
    }

    if (maxindex != i){
        swap(arr,size,i,maxindex);
        int color[1] = {i};
        coloring(arr,size,color,1);
        heapify(arr,size,heapsize,maxindex);
    }
}

void Sorting::createArray(){
    arr = new int[size];
    for (int i=0;i<size;++i){
        arr[i] = numberMax*(i+1)/size;
    }
    shuffle(arr,size);
    int index[1] = {0};
    emit changed(arr,size,index,1);
}

void Sorting::sort_bubble(int *arr, int size){
    for (int max_index=size-1;max_index>0;--max_index){
        for (int i=0;i<max_index-1;++i){
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
            }
            int color[1] = {i};
            coloring(arr,size,color,1);
        }
    }
}

void Sorting::sort_insertion(int* arr, int size){
    for (int i=1;i<size;++i){
        int temp = i;
        while (temp>=1 && arr[temp-1]>arr[temp]){
            swap(arr,size,temp-1,temp);
            int color[1] = {temp};
            coloring(arr,size,color,1);
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
            coloring(arr,size,color,2);
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
            coloring(arr,size,color,1);
            ++left;
        }
        while (arr[right]>=pivot && right>left){
            int color[2] = {left,right};
            coloring(arr,size,color,2);
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
            coloring(arr,size,color,1);
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
            coloring(arr,size,color,1);
        }
        if (changed == false){
            break;
        }
        ++start;
    }
}

void Sorting::sort_merge(int *arr, int size, int start, int end){
    if (start<end){
        int div = (start+end)/2;
        sort_merge(arr,size,start,div);
        sort_merge(arr,size,div+1,end);
        merge(arr,size,start,end);
    }
}

void Sorting::sort_heap(int *arr, int size){
    for (int i = size/2-1; i>=0; --i){
        heapify(arr,size,size,i);
    }

    for (int i=size-1;i>=0;--i){
        swap(arr,size,0,i);
        int color[1] = {i};
        coloring(arr,size,color,1);
        heapify(arr,size,i,0);
    }
}

void Sorting::coloring(int* arr,int size_arr,int* colorindex,int size_color){
    emit changed(arr,size_arr,colorindex,size_color);
    this->usleep(animDelay);
}
