#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i){
			cin >> a[i];
		}
		stable_sort(a.begin(), a.end(), [x](int a, int b){
			return abs(x-a) < abs(x-b);
		});
		for (int num: a){
			cout << num << " ";
		}
        cout << endl;
	}
}