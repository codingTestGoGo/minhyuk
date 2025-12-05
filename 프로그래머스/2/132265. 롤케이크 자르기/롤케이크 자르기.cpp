#include<bits/stdc++.h>


using namespace std;
int dp[10000005];
int solution(vector<int> topping) {
    int answer = 0;
    
    int sizes = topping.size();
    
    set<int> sets;
    map<int,int> mapF;
    map<int,int> mapS;
    
    for(auto it :topping){
        mapS[it]++;
    }
    
    
    for(int i =0; i< sizes;i++){
        int t = topping[i];
        mapF[t]++;
        mapS[t]--;
        if(mapS[t] == 0){
            mapS.erase(t);
        }
        if(mapF.size() == mapS.size())
            answer++;
    }
    
    
//     dp[0] = 1;
//     sets.insert(topping[0]);
//     for(int i =1; i<sizes;i++){
//         if(sets.find(topping[i]) == sets.end()){
//             sets.insert(topping[i]);
//             dp[i] = dp[i-1] +1;
//         }else{
//             dp[i] = dp[i-1];
//         }
//     }
    
    
//     for(int i=0;i<sizes-1;i++){
//         // cout << dp[i] << "\n";
//         if(dp[i] == (dp[sizes-1] - dp[i])){
//             cout << i << "\n";
//             answer++;
//         }
        
//     }
    
    
    return answer;
}