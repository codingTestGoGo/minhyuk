#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> dp(1000,vector<int> (1000,0));

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    vector<pair<int,int>> vec;
    
    for(auto it : info){
        vec.push_back({it[0],it[1]});
    }
    
    sort(vec.begin(),vec.end());
    
    int sizes = vec.size();
    
    for(int i=1;i<=vec.size();i++){
        int forA = vec[i-1].first;
        int forB = vec[i-1].second;
        
        for(int w = 0; w<=m; w++){
            if(w - forB >= 0){
                dp[i][w] = min(dp[i-1][w]+forA, dp[i-1][w-forB]);
            }else{
                dp[i][w] = dp[i-1][w]+forA;
            }
            // cout << dp[i][w] <<" ";
        }
        // cout <<"\n";
    }    
    
    if(dp[sizes][m-1] >= n){
        answer = -1;
    }else{
        answer = dp[sizes][m-1];
    }
    
    return answer;
}