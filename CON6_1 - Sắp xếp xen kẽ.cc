#include<bits/stdc++.h>
using namespace std;
void Bubble_Sort(vector<int> &a, int n, int k) {
    for(int i = 0 ; i < n - 1 ; i ++) {
        for(int j = 0 ; j < n - i - 1; j ++) {
            if (abs(a[j] - k) > abs(a[j + 1] - k))
                swap(a[j], a[j + 1]);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        Bubble_Sort(a, n, k);
        for(auto x: a) cout << x << " ";
        cout << endl;
    }
    return 0;
}