#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<int> L(N), J(N);  
    for (int i = 0; i < N; ++i) cin >> L[i];
    for (int i = 0; i < N; ++i) cin >> J[i];

    vector<int> dp(100, 0);

    for (int i = 0; i < N; ++i) {
        for (int h = 99; h >= L[i]; --h) { 
            dp[h] = max(dp[h], dp[h - L[i]] + J[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
