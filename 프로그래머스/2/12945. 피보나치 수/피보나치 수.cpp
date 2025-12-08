#include<bits/stdc++.h>

using namespace std;
int dp[100002];



int solution(int n) {
    int answer = 0;
    
    dp[0] = 0;
    dp[1] =  1;
    for(int i=2;i<=n;i++){
      dp[i] = (dp[i-1]%1234567 + dp[i-2]%1234567)%1234567;   
    }
    answer = dp[n];
    return answer;
}