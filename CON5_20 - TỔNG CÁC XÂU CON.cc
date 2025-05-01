#include<bits/stdc++.h>
using namespace std;
/*
- prev lưu tổng của tất cả các số tạo bởi các xâu con kết thúc tại vị trí trước đó (i - 1).
- num * (i + 1) la vì có (i + 1) xâu con kết thúc tại vị trí i, nên num góp mặt (i + 1) lần ở cuối mỗi xâu đó.
*/
int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        long long res = 0, prev = 0;
        for(int i = 0; i<n; i++){
            int num = s[i] - '0';
            long long curr = prev * 10 + num * (i+1);
            res = res + curr;
            prev = curr;
        }
        cout << res << endl;
    }
    return 0;
}