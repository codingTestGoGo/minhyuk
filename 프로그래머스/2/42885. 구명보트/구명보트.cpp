#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int> visited(people.size()+1,0);
    
    // 역순으로 정렬
    sort(people.begin(),people.end(),greater<int>());
    int ep = people.size() -1;
    for(int i =0 ;  i < people.size();i++){
        //이제 자기보다 작은 애들에 대해서
        int temp = people[i];
        if(visited[i] == 0){
            visited[i] = 1;
            answer ++;
        }else{
            // 이미 자리를 차지한 애야 -> 그러면 짝을 찾을 필요 없음
            continue;
        }
        for(int t= ep; t> i;t--){
            if(visited[t] == 0){
                if(temp + people[t] <= limit){
                    visited[t] = 1;
                    ep = t;
                }
                break;
            }
        }
    }
    
    
    return answer;
}