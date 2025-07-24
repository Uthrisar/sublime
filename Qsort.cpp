#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int partition(int lo, int hi){
	int pivot = arr[hi];
	int i = lo;
	for(int j=lo; j<=hi; j++){
		if(arr[j] < pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[hi]);
	return i;
}

void QuickSort(int lo, int hi){
	if(lo >= hi) return;
	int pi = partition(lo, hi);
	QuickSort(lo, pi-1);
	QuickSort(pi+1, hi);
}

int main(){
	int n;
	cin>>n;
	arr = vector<int>(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	QuickSort(0, n-1);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}