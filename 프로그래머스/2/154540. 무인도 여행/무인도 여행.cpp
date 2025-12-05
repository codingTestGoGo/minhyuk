#include<bits/stdc++.h>

using namespace std;

int forX[4] = {0,1,0,-1};
int forY[4]  = {-1,0,1,0};
int n,m;

vector<vector<int>> visited(101,vector<int> (101,0));


int getBFS(vector<string> &maps,int stY,int stX){
    queue<pair<int,int>> que;
    visited[stY][stX] = 1;
    int answer = 0;
    
    que.push({stY,stX});
    
    while(!que.empty()){
        pair<int,int> pairs = que.front();
        que.pop();
        answer += (maps[pairs.first][pairs.second] -'0');
        
        for(int i =0; i<4;i++){
            int nY = pairs.first + forY[i];
            int nX = pairs.second + forX[i];
        
            
            if(nY <0 || nX <0 || nX >= n || nY >= m){
                continue;
            }
            if(visited[nY][nX] !=0 || maps[nY][nX] == 'X'){
                continue;
            }
            
            visited[nY][nX] = 1;
            que.push({nY,nX});
        }
    }
    return answer;
    
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps[0].size();
    m = maps.size();
    
    for(int i =0;i<m;i++){
        for(int t= 0; t<n;t++){
            
            if(visited[i][t] == 0 && maps[i][t] != 'X'){
                answer.push_back(getBFS(maps,i,t));
            }
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}