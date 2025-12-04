#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int N, K;
vector<pair<int,int>> vec;
ll dp[100010];
int visited[102][100010];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    vec.push_back({0,0});
    for(int i =0; i<N;i++){
        pair<int,int> newPair;
        cin >> newPair.first >> newPair.second;
        vec.push_back(newPair);
    }

    sort(vec.begin(),vec.end());
    
    for(int i =1; i<=N;i++){
        // for(int t=0;t<N;t++){
        //     if(i - vec[t].first >=0){
        //         if(visited[i-vec[t].first][t] == 1){
        //             visited[i][t] = 1;
        //         }
        //     }
        // }
        for(int t=0;t<=K;t++){
            if(vec[i].first > t){
                visited[i][t] = visited[i-1][t];
            }else{
                visited[i][t] = max(visited[i-1][t], visited[i-1][t-vec[i].first]+vec[i].second);
            }
    }
    // for(int i=0;i<=K;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    //다시는 냅색을 헷갈리지 말고 틀리지 말자... 이건 아니다.
    }
    cout << visited[N][K] << "\n";
}