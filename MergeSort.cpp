#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void mergeSortRec(vector <int> arr);
void merge(vector <int> arr, vector <int> left, vector <int> right);

int main(){

}

void merge(vector <int> arr, vector <int> left, vector <int> right){
    int nleft = left.size();
    int nright = right.size();

    int i = 0;
    int j = 0;
    int k = 0;

    while (i<nleft && j<nright){
        if (left[i] < right[j]){
            arr[k] = left[i];
            i = i + 1;
        }//endif   
        else{
            arr[k] = right[j];
            j = j + 1;
        k = k + 1;
        }//endelse    
    }

    while(i<nleft){
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }    

    while (j<nright){
        arr[k] = right[j];
        j = j + 1;
        k = k + 1;
    }    
}

void mergeSortRec(vector <int> arr){
    int len = arr.size();

    if (len<2){
        return;
    }

    vector <int> left;
    vector <int> right;

    for (int i=0; i<len/2; i++){
        left.push_back(arr[i]);
    }

    for (int i=(len/2)+1; i<len; i++){
        right.push_back(arr[i]);
    }

    mergeSortRec(left);
    mergeSortRec(right);
    merge(arr,left,right);
}

