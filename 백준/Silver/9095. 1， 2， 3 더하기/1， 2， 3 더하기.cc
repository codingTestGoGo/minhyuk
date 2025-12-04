#include<bits/stdc++.h>

using namespace std;

int dp[12];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;
    int temp;
    for(int i=4;i<12;i++){
        dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
    }


    for(int i =0;i<T;i++){
        cin >> temp;
        cout << dp[temp] << "\n";

    }
}