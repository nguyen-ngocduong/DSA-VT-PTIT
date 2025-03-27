#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		int n = s.size();
		while (n < k)
			n *= 2;
		while (n - s.size()){
			if (k > n / 2){
				k = n / 2;
				if (k > 1)
					k--;
				else
					k /= 2;
			}
			n /= 2;
		}
		cout << s[k - 1] << endl;
	}
    return 0;
}