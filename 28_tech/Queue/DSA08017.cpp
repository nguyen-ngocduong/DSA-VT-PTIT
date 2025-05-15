/*Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy
liệt kê các số lộc phát có không quá N chữ số.*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        deque<string> res;
        q.push("6");
        q.push("8");
        while(q.back().size() <= n+1){
            string tmp = q.front();
            res.push_back(tmp);
            q.pop();
            q.push(tmp + "6");
            q.push(tmp + "8");
        }
        res.pop_back();
        while(res.size()) {
            cout << res.back() << " ";
            res.pop_back();
        }
        cout << endl;
    }
    return 0;
}