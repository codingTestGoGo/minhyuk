#include<bits/stdc++.h>

using namespace std;

long long int solution(vector<vector<int>> jobs) {
    long long int answer = 0;
    // 반환 시간을 구하기 위한 배열
    vector<pair<int,int>> ans;
    
    int currentTime =0;
    
    // 우선순위 큐
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> que;
    // 작업소요시간이 짧은 것, 작업의 요청시간, 작업의 번호
    
    // 얘는 작업의 요청시간, 작업의 소요 시간, 작업의 번호
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> que2;
    // 하나씩 que2에서 꺼내서 넣으면 됨
    
    
    // 모든 값에 대한 큐에 집어넣음
    int cnt = 1;
    for(auto it : jobs){
       
        // que.push({temp,it[0],cnt});
        que2.push({it[0],it[1],cnt});
        cnt ++;        
    }
    
    int spTime, st, num;
  
    
    tie(st,spTime,num) = que2.top();
    que2.pop();
    que.push({spTime,st,num});
    int nowTime = st;
    
    // 일단 시작을 위한 첫번째 것은 넣어줌
    while(!que.empty()){
        tie(spTime,st,num) = que.top();
        que.pop();
        nowTime += spTime; 
        ans.push_back({st,nowTime});
        while(!que2.empty()){
            tie(st,spTime,num) = que2.top();
           
            // 만약에 시간이 더 이르면 넣어주기
            if(st <= nowTime){
                que.push({spTime,st,num});
                que2.pop();
            }else if (st > nowTime){
                if(que.empty()){
                    que.push({spTime,st,num});
                    que2.pop();
                    nowTime = st;
                }
                break;
            }   
        }
    }

    for(auto it : ans){
        cout << it.second  << ":" << it.first << "\n";
        answer += (it.second-it.first);
    }
    
    answer /= jobs.size();
    
    return answer;
}