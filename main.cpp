#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "algorithms.h"

using namespace std;

int main(){
    srand(time(0));
    int size;
    do {
        cout<<"Input number of elements: ";
        cin>>size;
    } while (size<=0);
    int* arr = new int[size];
    for (int i=0; i<size; ++i)
        arr[i] = i+1;
    randompermute(arr,size);
    print(arr,size);
    int option;
    cout<<"Choose algorithm: "<<endl
    <<"1. Bubble sort"<<endl
    <<"2. Insertion sort"<<endl
    <<"3. Selection sort"<<endl
    <<"4. Quicksort"<<endl
    <<"5. Cocktail sort"<<endl
    <<"6. Bogosort"<<endl
    <<endl<<"Input: ";
    cin>>option;
    print(arr,size);
    switch(option){
        case 1:
            bubble(arr,size);
            break;
        case 2:
            insertion(arr,size);
            break;
        case 3:
            selection(arr,size);
            break;
        case 4:
            quick(arr,size,0,size-1);
            break;
        case 5:
            cocktail(arr,size);
            break;
        case 6:
            bogo(arr,size);
            break;
        default:
            cout<<"Invalid input, try again."<<endl;
            break;
    }

    //checking
    cout<<endl;
    if (sorted(arr,size)){
        cout<<"Success"<<endl;
    } else {
        cout<<"Failure"<<endl;
    }
    cout<<endl;
    
    delete [] arr;
}

