#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

// 8 hướng di chuyển hợp lệ của quân mã
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Hàm kiểm tra xem vị trí (x, y) có nằm trong bảng NxN hay không
bool isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Hàm BFS để tìm giá trị đường đi nhỏ nhất của quân mã
int bfs(vector<vector<int>>& board, int N, int x1, int y1, int x2, int y2) {
    // Tạo bảng giá trị để lưu tổng giá trị đường đi nhỏ nhất tới mỗi ô
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    dist[x1][y1] = board[x1][y1];

    // Hàng đợi để lưu các trạng thái của quân mã
    queue<pair<int, int>> q;
    q.push({x1, y1});

    // Bắt đầu BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Duyệt qua 8 hướng di chuyển của quân mã
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Nếu vị trí mới hợp lệ và giá trị đường đi nhỏ hơn giá trị đã ghi nhận
            if (isValid(nx, ny, N) && dist[nx][ny] > dist[x][y] + board[nx][ny]) {
                dist[nx][ny] = dist[x][y] + board[nx][ny];
                q.push({nx, ny});
            }
        }
    }

    // Trả về kết quả
    return (dist[x2][y2] == INT_MAX) ? -1 : dist[x2][y2];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> board(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
            }
        }

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Chuyển đổi từ chỉ số 1-based sang 0-based
        x1--; y1--; x2--; y2--;

        // Gọi hàm BFS để tìm đường đi nhỏ nhất
        cout << bfs(board, N, x1, y1, x2, y2) << endl;
    }

    return 0;
}