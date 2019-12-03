#include "sorting.h"
#include <QRandomGenerator>

Sorting::Sorting(QObject* parent) : QThread(parent){
}

void Sorting::run(){
    //shuffle(arr,size);
    num_changes = 0;
    num_comparisons = 0;
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
    } else if (algorithm == "Gnome Sort"){
        sort_gnome(arr,size);
    }

//    int color[0]={};
//    visualize(arr,size,color,0);

    emit done();
}

void Sorting::shuffle(){
    delete [] arr;
    arr = new  int[size];
    for (int i=0;i<size;++i){
        arr[i] = numberMax*(i+1)/size;
    }
    if (shuffleType == "Random"){
        for (int i=0;i<size;++i){
            int j = QRandomGenerator::global()->bounded(0,i+1);
            swap(arr,size,i,j);
        }
    } else if (shuffleType == "Reverse"){
        for (int i=0;i<size/2;++i){
            swap(arr,size,i,size-1-i);
        }
    } else if (shuffleType == "Almost sorted"){
        int i = QRandomGenerator::global()->bounded(0,size-1);
        int j;
        do {
            j = QRandomGenerator::global()->bounded(0,size);
        } while (arr[i] == arr[j]);
        swap(arr,size,i,j);
    }

    num_changes = 0;
    num_comparisons = 0;
}

void Sorting::swap(int* arr,int size,int i,int j){
    if (i>=size || j>=size || arr[i]==arr[j]){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    num_changes += 2;
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
        ++num_comparisons;
        if (L[left] <= R[right]){
            if (arr[merged] != L[left]){
                arr[merged] = L[left];
                ++num_changes;
            }
            ++left;
//            int color[2] = {merged,lsize+merged};
//            visualize(arr,size,color,2);
            color_size = 2;
            color = new int[color_size];
            color[0] = merged;
            color[1] = start-1+lsize+right;
            visualize(arr,size,color,color_size);
            delete [] color;
        } else {
            if (arr[merged] != R[right]){
                arr[merged] = R[right];
                ++num_changes;
            }
            ++right;
//            int color[2] = {merged,rsize+merged};
//            visualize(arr,size,color,2);
            color_size = 2;
            color = new int[color_size];
            color[0] = merged;
            color[1] = start-1+lsize+right;
            visualize(arr,size,color,color_size);
            delete [] color;
        }
        ++merged;
    }

    while (left<lsize){
        if (arr[merged] != L[left]){
            arr[merged] = L[left];
            ++num_changes;
        }
        color_size = 1;
        color = new int[color_size];
        color[0] = merged;
        visualize(arr,size,color,color_size);
        delete [] color;
        ++left;
        ++merged;
    }
    while (right<rsize){
        if (arr[merged] != R[right]){
            arr[merged] = R[right];
            ++num_changes;
        }
        color_size = 2;
        color = new int[color_size];
        color[0] = merged;
        color[1] = start-1+lsize+right;
        visualize(arr,size,color,color_size);
        delete [] color;
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

    if (left<heapsize){
        ++num_comparisons;
        if (arr[left]>arr[maxindex]){
            maxindex = left;
        }
    }

    if (right<heapsize){
        ++num_comparisons;
        if (arr[right]>arr[maxindex]){
            maxindex = right;
        }
    }

    if (maxindex != i){
        swap(arr,size,i,maxindex);
//        int color[1] = {i};
//        visualize(arr,size,color,1);
        color_size = 1;
        color = new int[color_size];
        color[0] = i;
        visualize(arr,size,color,color_size);
        delete [] color;
        heapify(arr,size,heapsize,maxindex);

    }
}

void Sorting::insert(int* arr,int size,int i){
    if (i>size-1){
        return;
    }

    int index = i;
    for (index=i;index>0;--index){
        ++num_comparisons;
        if (arr[index-1]<arr[i]){
            break;
        }
    }
    int temp = arr[i];
    for (int j = i;j>index;--j){
        if (arr[j] != arr[j-1]){
            ++num_changes;
        }
        arr[j] = arr[j-1];
    }
    if (arr[index] != temp){
        ++num_changes;
    }
    arr[index] = temp;
//    int color[1] = {index};
//    visualize(arr,size,color,1);
    color_size = 1;
    color = new int[color_size];
    color[0] = index;
    visualize(arr,size,color,color_size);
    delete [] color;
}

void Sorting::createArray(){
    arr = new int[size];
    for (int i=0;i<size;++i){
        arr[i] = numberMax*(i+1)/size;
    }
//    shuffle(arr,size);
    shuffle();
    int index[1] = {0};
    emit changed(arr,size,index,1);
}

void Sorting::sort_bubble(int *arr, int size){
    bool changed = true;
    int maxindex = size-1;
    while (changed){
        changed = false;
        for (int i=0;i<maxindex;++i){
            ++num_comparisons;
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
                changed = true;
            }
//            int color[1] = {i};
//            visualize(arr,size,color,1);
            color_size = 1;
            color= new int[color_size];
            color[0]=i+1;
            visualize(arr,size,color,color_size);
            delete [] color;
        }
        --maxindex;
    }
}

void Sorting::sort_insertion(int* arr, int size){
    for (int i=1;i<size;++i){
        insert(arr,size,i);
    }
}

void Sorting::sort_selection(int *arr, int size){
    for (int i=0;i<size;++i){
        int minindex = i;
        int minvalue = arr[i];
        for (int j=i+1;j<size;++j){
            ++num_comparisons;
            if (arr[j]<minvalue){
                minindex = j;
                minvalue = arr[j];
            }
//            int color[2] = {i,j};
//            visualize(arr,size,color,2);
            color_size = 3;
            color = new int[color_size];
            color[0] = i;
            color[1] = j;
            color[2] = minindex;
            visualize(arr,size,color,color_size);
            delete [] color;
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
        ++num_comparisons;
        while (arr[left]<pivot && left<end){
//            int color[1] = {left};
//            visualize(arr,size,color,1);
            color_size = 1;
            color = new int[color_size];
            color[0] = left;
            visualize(arr,size,color,color_size);
            delete [] color;

            ++left;
            ++num_comparisons;
        }
        ++num_comparisons;
        while (arr[right]>=pivot && right>left){
//            int color[2] = {left,right};
//            visualize(arr,size,color,2);
            color_size = 2;
            color = new int[color_size];
            color[0] = left;
            color[1] =  right;
            visualize(arr,size,color,color_size);
            delete [] color;
            --right;
            ++num_comparisons;
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
            ++num_comparisons;
            if (arr[i]>arr[i+1]){
                swap(arr,size,i,i+1);
                changed = true;
            }
//            int color[1] = {i};
//            visualize(arr,size,color,1);
            color_size = 1;
            color = new int[color_size];
            color[0] = i+1;
            visualize(arr,size,color,color_size);
            delete [] color;
        }
        --end;
        if (changed == false){
            break;
        }
        for (int i=end;i>start;--i){
            ++num_comparisons;
            if (arr[i]<arr[i-1]){
                swap(arr,size,i-1,i);
                changed = true;
            }
//            int color[1] = {i};
//            visualize(arr,size,color,1);
            color_size = 1;
            color = new int[color_size];
            color[0] = i-1;
            visualize(arr,size,color,color_size);
            delete [] color;
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
//        int color[1] = {i};
//        visualize(arr,size,color,1);
        color_size = 1;
        color = new int[color_size];
        color[0] = i;
        visualize(arr,size,color,color_size);
        delete [] color;
        heapify(arr,size,i,0);
    }
}

void Sorting::sort_gnome(int *arr, int size){
    int i=0;
    while (i<size){
        if (i == 0){
            i=1;
        }
        ++num_comparisons;
        if (arr[i]>=arr[i-1]){
            ++i;
        } else {
            swap(arr,size,i-1,i);
            --i;
        }
//        int color[1] = {i};
//        visualize(arr,size,color,1);
        color_size = 1;
        color = new int[color_size];
        color[0] = i;
        visualize(arr,size,color,color_size);
        delete [] color;
    }
}

void Sorting::visualize(int* arr,int size_arr,int* colorindex,int size_color){
    emit changed(arr,size_arr,colorindex,size_color);
    this->usleep(animDelay);
}
