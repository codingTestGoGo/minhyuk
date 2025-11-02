#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t, N;
    cin >> N;
    int f1,f2,f3;
    int timer =1;
    while(N != 0){
        vector<vector<int>> vec;
        for(int i=0;i<N;i++){
            vector<int> temp;
            cin >> f1 >> f2 >> f3;
            temp.push_back(f1);
            temp.push_back(f2);
            temp.push_back(f3);
            vec.push_back(temp);
        }
        vector<vector<int>> visited(N,vector<int> (3,0));
        // 방문했던 vector에 대한 초기화
        // 어차피 입력받는 것도 N이기에 N 풀이로 진행
        // 비용이 정수라는 말을 고려

        visited[0][0] = 100001;
        visited[0][1] = vec[0][1];
        visited[0][2] = vec[0][1] + vec[0][2];
        for(int i =1;i<N;i++){
            visited[i][0] = vec[i][0] + min(visited[i-1][0],visited[i-1][1]);
            visited[i][1] = vec[i][1] + min({visited[i-1][0],visited[i-1][1],visited[i-1][2],visited[i][0]});
            visited[i][2] = vec[i][2] + min({visited[i-1][1],visited[i-1][2],visited[i][1]});
        }
        cout << timer << ". ";
        cout << visited[N-1][1] << "\n";
        timer++;
        cin >> N;
    }

}