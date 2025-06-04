#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, a[1005][1005], res;
int x_start, y_start, x_end, y_end;
bool visited[1005][1005]; // Mảng đánh dấu

void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> x_start >> y_start >> x_end >> y_end;
}

void Try(int i, int j, int sum) {
    if(i < 1 || i > n || j < 1 || j > m || visited[i][j]) return; // Ra khỏi biên hoặc đã đi rồi

    sum += a[i][j];

    if(i == x_end && j == y_end) {
        res = min(res, sum);
        return;
    }

    visited[i][j] = true;

    // Di chuyển 4 hướng
    Try(i + 1, j, sum);
    Try(i - 1, j, sum);
    Try(i, j + 1, sum);
    Try(i, j - 1, sum);

    visited[i][j] = false; // Quay lui
}

int main() {
    int t; cin >> t;
    while(t--) {
        init();
        res = INF;
        memset(visited, false, sizeof(visited));
        Try(x_start, y_start, 0);
        if(res == INF) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
