#include<bits/stdc++.h>


using namespace std;
vector<int> dp(4000001,99999);
int solution(int x, int y, int n) {
    int answer = 0;
    
    dp[x] = 0;
    for(int i = x+1;i<=y;i++){
        int temp1 = 99999, temp2 = 99999, temp3= 99999;
        if(i % 3 == 0){
            temp1 = dp[i/3];
        }
        if(i % 2 == 0){
            temp2 = dp[i/2];
        }
        if(i-n >=0){
            temp3 = dp[i-n];
        }
        dp[i] = min({temp1,temp2,temp3})+1;        
    }
    
    answer = dp[y];
    if(answer  >= 99999){
        return -1;
    }
    return answer;
}