#ifndef helper_h
#define helper_h

#include <iostream>
#include <stdio.h>

bool sorted(int arr[],int size);
void print(int arr[],int size);
void swap(int arr[],int size,int pos1,int pos2);
void substitute(int arr[],int size,int pos,int value);
int findminindex(int arr[],int size,int start,int end);
void insert(int arr[],int size,int position);
void randompermute(int arr[],int size);

#endif /* helper_hpp */
