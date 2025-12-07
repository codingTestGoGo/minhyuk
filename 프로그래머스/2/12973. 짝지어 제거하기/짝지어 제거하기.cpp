#include<bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> sta;
    
    
    for(auto it : s){
        if(!sta.empty()){
            char tops = sta.top();
            if(tops == it){
                sta.pop();
            }else{
                sta.push(it);
            }
        }else{
            sta.push(it);
        }
    }
    
    if(sta.empty()){
        answer  = 1;
    }
    
    
    
    
    return answer;
}