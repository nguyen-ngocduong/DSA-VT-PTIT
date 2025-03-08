#include<bits/stdc++.h>
using namespace std;

vector<string> v;
int a[100];
string s = "";

void Dequy(int n) {
    if(n == 0) {
        return;
    }
    s += "[";
    for(int i = 0; i < n-1; i++) {
        s += to_string(a[i]) + " ";
    }
    s += to_string(a[n-1]) + "]";
    v.push_back(s);
    s = "";

    for(int k = 0; k < n-1; k++) {
        a[k] = a[k] + a[k+1];
    }

    Dequy(n-1);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        v.clear(); // 🔥 Sửa lỗi quan trọng
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Dequy(n);
        for(int i = v.size()-1; i >= 0; i--) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
