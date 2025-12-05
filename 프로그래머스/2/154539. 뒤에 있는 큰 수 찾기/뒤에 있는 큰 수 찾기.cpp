#include<bits/stdc++.h>


using namespace std;

vector<int> solution(vector<int> numbers) {
    int sizes = numbers.size();
    vector<int> answer(sizes,-1);
    
    // 배열을 뒤집어줌
    // reverse(numbers.begin(),numbers.end());
    
    stack<pair<int,int>> sta;
    
    for(int i =0;i<numbers.size();i++){
        if(sta.empty()){
            sta.push({numbers[i],i});
            continue;
        }
        pair<int,int> tops = sta.top();
        if(numbers[i] > tops.first){
            //스택보다 크면 이전의 것들은 전부 저장
            while(!sta.empty()){
                if(sta.top().first >= numbers[i]){
                    break;
                }
                answer[sta.top().second]= (numbers[i]);
                sta.pop();
            }
            sta.push({numbers[i],i});
        }else{
            sta.push({numbers[i],i});
        }
    }
    while(!sta.empty()){
        pair<int,int> tops =sta.top();
        answer[tops.second] = -1;
        sta.pop();
    }
    
    return answer;
}