#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int pf[26];
		for(int i = 0; i < 26; i++){
			pf[i] = 0;
		}
		for(int i = 0; i < str.size(); i++){
			pf[str[i]-'a']++;
		}
		int min_idx = 0;
		int min_val = 1e9+10;
		cout <<pf['u'-'a']<<"\n";
		for(int i = 0; i < 26; i++){
			if(pf[i] > 0 && pf[i] < mx_val){
				mx_val = pf[i];
				mx_idx = i;
			}
		}
		char ch = 'a'+ mx_idx;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ch){
				cout << str[i];
			} else {
				cout <<" "<< str[i];
			}
		}
	}
		
}