#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void recc(int ind, int sum1, int sum){
	if(sum1 == sum){
		cnt++;
		return;
	}
	if(ind > 1){
		recc(ind-1, sum1+ind, sum);
		recc(ind-1, sum1, sum);
	}

}

int main(){
	int n;
	cin >> n;
	int sum = n*(n+1)/2;
	if(sum % 2 == 0){
		recc(n,0,sum/2);
	} 
	cout << cnt <<"\n";
}