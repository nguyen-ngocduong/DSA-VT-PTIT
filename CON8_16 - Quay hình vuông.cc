#include<bits/stdc++.h>
using namespace std;

int dl[] = {1, 5, 2, 4, 6, 3};
int dr[] = {4, 1, 3, 5, 2, 6};

string Drt(string s, int a[], int n) {
    string res = "";
    for (int i = 0; i < n; ++i) 
        res += s[a[i] - 1];
    return res;
}

void BFS(string s, string t) {
    map<string, int> mp;
    queue<string> q;
    q.push(s);
    mp[s] = 1;
    while (!q.empty()) {
        string c = q.front(); 
        q.pop();
        if (c == t) {
            cout << mp[c] - 1 << endl;
            return;
        }
        string a = Drt(c, dl, 6);
        if (mp.find(a) == mp.end()) {
            q.push(a);
            mp[a] = mp[c] + 1;
        }
        string b = Drt(c, dr, 6);
        if (mp.find(b) == mp.end()) {
            q.push(b);
            mp[b] = mp[c] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; 
    cin >> t;
    while (t--) {
        string s = "", t = "";
        for (int i = 0; i < 6; ++i) { 
            char x; 
            cin >> x; 
            s += x;
        }
        for (int i = 0; i < 6; ++i) { 
            char x; 
            cin >> x; 
            t += x;
        }
        BFS(s, t);
    }
    return 0;
}