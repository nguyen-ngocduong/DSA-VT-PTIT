#include<bits/stdc++.h>
using namespace std;

vector<int> validNumbers;

void generateValidNumbers() {
    queue<int> q;
    // Bắt đầu với các số từ 1 đến 5 (vì số 0 không có nghĩa khi đứng đầu)
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        validNumbers.push_back(num);
        if (num > 1e5) continue; // Giới hạn số không vượt quá 1e5
        bool used[6] = {false};
        int temp = num;
        // Đánh dấu các chữ số đã sử dụng
        while (temp > 0) {
            int digit = temp % 10;
            used[digit] = true;
            temp /= 10;
        }
        // Thêm các chữ số từ 0 đến 5 chưa dùng vào sau số hiện tại
        for (int digit = 0; digit <= 5; digit++) {
            if (!used[digit]) {
                int newNum = num * 10 + digit;
                if (newNum <= 1e5) {
                    q.push(newNum);
                }
            }
        }
    }
    // Thêm số 0 nếu cần (nhưng L >= 0)
    validNumbers.push_back(0);
    sort(validNumbers.begin(), validNumbers.end());
}

int countValidNumbers(int L, int R) {
    auto left = lower_bound(validNumbers.begin(), validNumbers.end(), L);
    auto right = upper_bound(validNumbers.begin(), validNumbers.end(), R);
    return right - left;
}

int main() {
    generateValidNumbers();
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    return 0;
}