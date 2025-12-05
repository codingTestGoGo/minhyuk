#include<bits/stdc++.h>

using namespace std;

int forX[4] = {0,1,0,-1};
int forY[4] = {-1,0,1,0};

int n,m;

int getBFS(int stX, int stY, int enX, int enY, vector<string> &maps){
    int visited[110][110];
    
    for(int i= 0;i<n;i++){
       for(int t= 0; t<m;t++){
           visited[i][t] = -1;
       }
    }
    // 0으로 전부 초기화
    
    queue<pair<int,int>> que;
    que.push({stY,stX});
    visited[stY][stX]  = 0;
    
    while(!que.empty()){
        pair<int,int> pairs = que.front();
        que.pop();
        
        
        for(int i =0 ; i< 4;i++){
            int ny = pairs.first + forY[i];
            int nx = pairs.second + forX[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m){
              continue;  
            } 
            if(maps[ny][nx] == 'X' || visited[ny][nx] != -1){
                continue;
            }
            visited[ny][nx] = visited[pairs.first][pairs.second] + 1;
            que.push({ny,nx});
            if(ny == enY && nx == enX){
                return visited[ny][nx];
            }
        }
    }
    return -1;
}


int solution(vector<string> maps) {
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    
    //BFS 2번 돌리기
    int stX, stY, enX, enY, lX, lY;
    for(int i =0;i<n;i++){
        for(int t= 0; t<m;t++){
            if(maps[i][t] == 'S'){
                stX = t;
                stY = i;
            }else if(maps[i][t] == 'E'){
                enX = t;
                enY = i;
            }else if(maps[i][t] == 'L'){
                lX = t;
                lY = i;
            }
        }
    }
    
    
    answer += getBFS(stX,stY,lX,lY,maps);
    // cout << answer << "\n";
    if(answer <= 0){
        return -1;
    }
    int tempA;
    tempA =  getBFS(lX,lY,enX,enY,maps);
    // cout << answer << "\n";
    if(tempA <= 0){
        return -1;
    }
    answer += tempA;
    return answer;
}