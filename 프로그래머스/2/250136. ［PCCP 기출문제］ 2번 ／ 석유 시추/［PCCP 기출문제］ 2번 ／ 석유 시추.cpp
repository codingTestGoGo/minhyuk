#include<bits/stdc++.h>


using namespace std;


int n,m;
int forX[4] = {0,1,0,-1};
int forY[4] = {-1,0,1,0};

//겹치는게 많으면 좋지만 어떤 애가 겹쳐져서 좋은 애인지는 특정 x

int maxAns= 0;
vector<int> vec(500,0);

vector<vector<int>> visited(500,vector<int> (500,0));

void getBfs(int stX,int stY,vector<vector<int>> &land){
    
    visited[stY][stX] = 1;
    queue<pair<int,int>> que;    
    
    set<int> sets;
    sets.insert(stX);
    que.push({stY,stX});
    int sizes = 0;
    
    while(!que.empty()){
        pair<int,int> temp = que.front();
        que.pop();
        sizes ++;
        
        for(int i =0 ; i< 4;i++){
            int newX = forX[i] + temp.second;
            int newY = forY[i] + temp.first;
            if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
            if(visited[newY][newX] == 1 || land[newY][newX] == 0 ){
                continue;
            }
            visited[newY][newX] = 1;
            sets.insert(newX);
            que.push({newY,newX});
        }
    }
    for(auto it : sets){
        cout << it << "\n";
        vec[it] += sizes;
        maxAns = max(maxAns,vec[it]);
    } 
}


int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    
    
    
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(visited[i][t] == 0 && land[i][t] == 1){
              getBfs(t,i,land);  
            }
        }
    }

    answer = maxAns;
    return answer;
}