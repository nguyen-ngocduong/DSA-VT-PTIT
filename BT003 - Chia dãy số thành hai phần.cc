#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxProductOfSubsetSums(vector<int>& A) {
    int N = A.size();
    int total = accumulate(A.begin(), A.end(), 0);
    int target = total / 2; 
    bitset<100001> dp;
    dp[0] = 1; // Có thể đạt được tổng 0
    for (int num : A) {
        dp |= dp << num;
    }
    int best = 0;
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            best = i;
            break;
        }
    }
    ll sum1 = best;
    ll sum2 = total - best;
    return sum1 * sum2;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        cout << maxProductOfSubsetSums(A) << endl;
    }
    return 0;
}