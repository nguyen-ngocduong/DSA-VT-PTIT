/*Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số
nguyên tố có 4 chữ số). Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn
đồng thời những điều kiện dưới đây:
a. Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó
(ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);b. Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch
chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
c. Số các bước dịch chuyển là ít nhất.
Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành T = 8179 là 6 bao gồm các phép
dịch chuyển như sau:
8179 -> 8779 -> 3779 -> 3739 -> 3733 -> 1733 -> 1033.*/
#include<bits/stdc++.h>
using namespace std;
bool prime[10001];
void sang(){
    fill(prime, prime + 10001, true);
    for(int i = 2; i<= 100; i++){
        if(prime[i]){
            for(int j = i*i; j<= 10000; j+=i){
                prime[j] = false;
            }
        }
    }
}
int BFS(int s, int t){
    queue<pair<int, int>> q;
    q.push({s,0}); // S la so hien tai, 0 la so thao tac thuc hien
    vector<int> visited(10000, 0);
    visited[s] = 1;
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.first == t) return tmp.second;
        string curr = to_string(tmp.first);
        for(int i = 0; i< 4; i++){
            for(char c = '0'; c <= '9'; c++){
                if(c == curr[i]) continue;
                string next = curr;
                next[i] = c;
                int v = stoi(next);
                if (v >= 1000 && prime[v] && !visited[v]) {
                    visited[v] = 1;
                    q.push({v, tmp.second + 1});
                }
            }
        }
    }
    return -1;
}
int main(){
    sang();
    int t; cin >> t;
    while (t--)
    {
        int s, t; cin >> s >> t;
        cout << BFS(s,t) << endl;
    }
    return 0;
}