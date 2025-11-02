#include<bits/stdc++.h>

using namespace std;


// dp는 온전히 파일을 합치는데 사용하는 비용
int getAns(int st , int en, vector<vector<int>>& dp,vector<int>& vec,vector<int>& sum){
    if(dp[st][en] != 0x3f3f3f3f){
        return dp[st][en];
    }
    if(st == en){
        return dp[st][en] = 0;
    }
    if((en - st) == 1){
        dp[st][en] = vec[st] + vec[en];
        return dp[st][en];
    }
    // 재귀인데 계속 구할 수는 없으니까 memorization 해둬야함

    for(int i=st;i<en;i++){
        dp[st][en] = min(getAns(st,i,dp,vec,sum)+getAns(i+1,en,dp,vec,sum),dp[st][en]);
    }
    dp[st][en] += sum[en] - sum[st-1];
    return  dp[st][en];
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int N;
    for(int i =0; i<T;i++){
        cin >> N;
        vector<int> vec(N+2,0);
        int temp;
        for(int t=1;t<=N;t++){
            cin >> temp;
            vec[t] = temp;
        }
        long long int answer = 0;
        vector<vector<int>> dp(N+2,vector<int> (N+2,0x3f3f3f3f));
        vector<int> sum(N+2,0);

        for(int t=1;t<=N;t++){
            sum[t] = sum[t-1]+vec[t];
        }
        cout << getAns(1,N,dp,vec,sum) << "\n";

    }

}