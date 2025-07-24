#include <bits/stdc++.h>

using namespace std;


struct Item{
	int val, wt;
	Item(int value, int weight){
		this->val = value;
		this->wt = weight;
	}
};

static bool cmp(struct Item a, struct Item b){
	double valToWeightRationOfA = (double)a.val/(double)a.wt;
	double valToWeightRationOfB = (double)b.val/(double)b.wt;
	return valToWeightRationOfA > valToWeightRationOfB;
}

int main(){
	int N, cap;
	cin >> N >> cap;
	vector<Item> items;
	for(int i=0; i<N; i++){
		int val, wt;
		cin >> val >> wt;
		items.push_back(Item(val, wt));
	}

	sort(items.begin(), items.end(), cmp);

	double ans = 0;

	for(int i=0; i<N; i++){
		if(items[i].wt <= cap){
			cap -= items[i].wt;
			ans += items[i].val;
		} else {
			ans += items[i].val*((double)cap/(double)items[i].wt);
			break;
		}
	}

	cout << fixed << setprecision(5) << ans;
}