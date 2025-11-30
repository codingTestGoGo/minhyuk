#include<bits/stdc++.h>

using namespace std;

int forX[4] = {0,1,0,-1};
int forY[4] = {-1,0,1,0};

int arr[110][110];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , M;
    cin >> M >> N;

    char temp;
    for(int i =0; i< N;i++){
        for(int t= 0; t<M;t++){
            cin >> temp;
            arr[i][t] = temp - '0';
        }
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> que;
    que.push({0,0,0});

    vector<vector<int>> vec(110,vector<int>(110,0x3f3f3f3f));
    // 초기화된 2차원 배열

    vec[0][0] = 0;

    int val, x, y;
    while(!que.empty()){
        tie(val,y,x) = que.top();
        que.pop();

        if(vec[y][x] != val) continue;

        for(int i= 0; i<4;i++){
            int newX = forX[i] + x;
            int newY = forY[i] + y;

            if(newX < 0 || newY < 0 || newX >= M || newY >= N) continue;
            int nw = val + arr[newY][newX];
            
            if(vec[newY][newX] > nw){
                vec[newY][newX] = nw;
                que.push({nw,newY,newX});
            }
            
        }
    }

    cout << vec[N-1][M-1] << "\n";


}