#include <iostream>
#include <deque>

using namespace std;
int dp[1000001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int input;
    cin >> input;
    //N값을 입력받는다.
    for(int i = 4 ; i<= input ; i++){
        if(dp[i-1])
            dp[i] = dp[i-1]+1;
        if((dp[i/2])&&(i%2==0))
            dp[i] = min(dp[i/2],dp[i-1])+1;
        if((dp[i/3])&&(i%3==0))
            dp[i] = min(dp[i/3]+1,dp[i]);
    }
    cout << dp[input] <<"\n";
}