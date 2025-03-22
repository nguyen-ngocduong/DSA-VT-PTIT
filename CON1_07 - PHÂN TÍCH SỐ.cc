#include <bits/stdc++.h>
using namespace std;

void Dequy(int n, int max, string prefix) {
    if (n == 0) {
        cout << "(" << prefix.substr(0, prefix.size() - 1) << ") ";
        return;
    }
    for (int i = min(n, max); i >= 1; i--) {
        Dequy(n - i, i, prefix + to_string(i)+" ");
    }
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Dequy(n, n, "");
        cout << endl;
    }
    return 0;
}