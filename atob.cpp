#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>

int func(int ind, int wt){
	if(ind < 0) return 0;
	if(wt < s[ind]){
		func(ind-1,wt+w[ind])+v[ind];
	}
	
}

int main(){
	
}