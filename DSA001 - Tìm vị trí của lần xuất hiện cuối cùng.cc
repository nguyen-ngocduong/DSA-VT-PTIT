#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;     // Ghi nhận vị trí
            low = mid + 1;    // Tìm tiếp bên phải
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, target;
        cin >> n >> target;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << solve(arr, target) << endl;
    }

    return 0;
}
