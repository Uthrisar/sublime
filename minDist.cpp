#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[100];

void merge(int lo, int mid, int hi){
    int i = lo, j = mid+1;
    vector<int> tmp;
    while(i <= mid && j <= hi){
        if(a[i] <= a[j]){
            tmp.push_back(a[i]);
            i++;
        } else {
            tmp.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid){
        tmp.push_back(a[i]);
        i++;
    }
    while(j <= hi){
        tmp.push_back(a[j]);
        j++;
    }
    for(int k=0; k<(hi-lo+1); k++){
        a[lo+k] = tmp[k];
    }
}

void mergeSort(int lo, int hi){
    if(lo == hi) return;
    int mid = lo+(hi-lo)/2;
    mergeSort(lo, mid);
    mergeSort(mid+1, hi);
    merge(lo, mid, hi);
}


int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    mergeSort(0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i] <<" ";
    }
}
