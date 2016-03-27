//
// Created by anjun on 3/27/16.
//

#include <stdio.h>
void quick_sort(int*,int ,int);
int main(void){
    int a[6] = {2,1,0,5,4,3};
    int i;
    quick_sort(a,0,5);
    for(i=0;i<6;++i)
        printf("\d\n",a[i]);
    return 0;
}
int findPos(int *a,int low,int high) {
    int val = a[low];
    while (low < high){
        while ( a[high]>=val)
            --high;
        a[low] =a[high];
        while ( a[low]<=val)
            ++low;
        a[high]=val;
    }
    a[low] = val;
    return  low;
}
void quick_sort(int*a,int low ,int high){
    int pos;
    if(low<high){
        pos=findPos(a,low,high);
        quick_sort(a,low,pos-1);
        quick_sort(a,low,pos+1);
    }
}

