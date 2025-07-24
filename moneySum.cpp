#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

vector<int> ans;

void func(int idx, int sum, vector<int>& v){
	if(idx > v.size()) return;
	ans.push_back(sum);
	func(idx+1, sum, v);
	func(idx+1, sum+v[idx], v);
}

int main(){
	int n;
	cin >> n;
	vector<int> v1(n);
	for(int i = 0; i < n; ++i){
		cin >> v1[i];
	}
	func(0,0,v1);
	set<int> s1;
	for(int i = 0; i < ans.size(); i++){
		s1.insert(ans[i]);
	}
	s1.erase(0);
	cout << s1.size() << nline;
	for(auto &elmt: s1){
		cout << elmt << " ";
	}
}