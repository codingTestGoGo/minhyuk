#include<bits/stdc++.h>

using namespace std;

int games(int st, int en, int turn,vector<vector<int>> &dp,vector<int> &arr){
    if(st> en){
        return 0;
    }
    if(dp[st][en]){
        // 이게 메모라이제이션
        return dp[st][en]; 
    }

    if(turn %2 == 1){
        //근우 차례
        dp[st][en] = max(( arr[st]+games(st+1,en,turn+1,dp,arr)),(arr[en]+games(st,en-1,turn+1,dp,arr)));
    }else{
        dp[st][en] = min(games(st+1,en,turn+1,dp,arr),games(st,en-1,turn+1,dp,arr));
    }

    return dp[st][en];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int temp;
    // 홀 수 일때는 어떻게 고려할까
    // 짝수일 때는 큰게 답
    int tempC;
    for(int i=0;i<T;i++){
        cin >> tempC;
        
        vector<int> deq;
        for(int t= 0;t<tempC;t++){
            cin >> temp;
            deq.push_back(temp);
        }
        int answer = 0;
        int counter = 1;
        vector<vector<int>> dp(tempC +1, vector<int> (tempC+1, 0));

        games(0,tempC-1,1,dp,deq);
        cout << dp[0][tempC-1] << "\n";
    }
}