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

float func(int ind, int head, int tail, float p){
	if(ind < 0) return 0;
	if(ind < 0 && head > tail){

	}
	func(ind-1,head+1,tail,p)*p;
	func(ind-1,head,tail+1,p)*(1-p);
}