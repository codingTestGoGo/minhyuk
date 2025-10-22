#include<bits/stdc++.h>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 그냥 연결그래프로 DFS 문제임

    int N, M;
    cin >> N >> M;

    vector<int> vec[510];
    int fr1, fr2;
    for(int i =0;i<M;i++){
        cin >> fr1 >> fr2;
        vec[fr1].push_back(fr2);
        vec[fr2].push_back(fr1);
    } // 무방향 그래프로 입력이 됨

    int ans = 0;


    queue<int> que;
    que.push(1);
    int visited[510];
    fill(visited, visited+N,0);
    visited[1] = 1;
    while(!que.empty()){
        int temp = que.front();
        que.pop();
        for(auto it : vec[temp]){
            if(visited[it]==0){
                visited[it] = visited[temp] + 1;
                que.push(it);
                if(visited[it] <= 3){
                    ans ++;
                }
            }
        }
    }

    cout << ans <<"\n";
 
    

}