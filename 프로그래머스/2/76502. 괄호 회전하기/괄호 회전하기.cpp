#include<bits/stdc++.h>


using namespace std;

bool isOk(deque<char> deq){
    stack<char> sta;
    //하나가 열렸으면 안의 것부터 닫혀야함
    
    for(auto it : deq){
        if(it == '(' || it == '{' || it == '['){
            sta.push(it);
        }else{
            if(sta.empty()){
                return false;
            }
            if(it == ')'){
                if(sta.top() == '('){
                    sta.pop();
                }else{
                    return false;
                }
            }else if(it == '}'){
                if(sta.top() == '{'){
                    sta.pop();
                }else{
                    return false;
                }
            }else if(it == ']'){
                if(sta.top() == '['){
                    sta.pop();
                }else{
                    return false;
                }
            }
        }
    }
    if(!sta.empty()){
        return false;
    }
    return true;
}


int solution(string s) {
    int answer = 0;
    //n^2도 가능 즉 deque과 stack의 활용
    deque<char> deq;
    
    for(auto it : s){
      deq.push_back(it);  
    } 
    
    for(int i=0;i<s.size();i++){
        if(isOk(deq)){
            answer++;
        }
        int temp = deq.front();
        deq.pop_front();
        deq.push_back(temp);
    }
    
    return answer;
}