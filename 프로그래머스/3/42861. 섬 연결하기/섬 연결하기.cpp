#include<bits/stdc++.h>

using namespace std;

vector<int> vec(110,-1);


int find(int x){
    if(vec[x]  <0){
        return x ;
    }
    return vec[x] = find(vec[x]);
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y){
        return false;
    }
    
    if(vec[x] > vec[y]){
        swap(x,y);
    }
    if(vec[x] == vec[y]){
        vec[x] --;
    }
    
    vec[y] = x;
    return true;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // 최소 신장 트리 구하기
    
    
    vector<tuple<int,int,int>> vec;
    
    for(auto it : costs){
        vec.push_back({it[2],it[0],it[1]});
    }
    sort(vec.begin(),vec.end());
    
    int cnt = 0;
    int cost,x,y;
    for(int i =0;i<vec.size();i++){
        tie(cost,x,y) = vec[i];
        
        if(!uni(x,y)) continue;
        
        answer += cost;
        cnt ++;
        if(cnt == n-1){
            break;
        }
    }
    
    return answer;
}