#include<bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

// 끝나는 지점을 기준으로 판단해야함

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    //하나씩 묶어가면서 짧은 끝에 만족하는지 확인
    
    int st = -35000;
    
    sort(routes.begin(),routes.end(),comp);
    // greater<int>()
    
    for(auto it : routes){
        // cout << it[0] << "\n";
        if(st == -35000){
            st = it[1];
            answer ++;
            continue;
        }
        
        
        if(it[0] > st){
            // 변경될 때마다 카메라를 설치
            answer ++;
            st = it[1];
        }
    }
    
//     if(st != -35000){
//         answer ++;
//     }
    return answer;
}