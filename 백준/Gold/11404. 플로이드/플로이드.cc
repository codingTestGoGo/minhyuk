#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int a,b,c;

    // 2차원 vector의 초기화
    vector<vector<int>> vec(n+2,vector<int>(n+2,10000050));
    // 자기 자신은 0으로 해둬야하긴해
    for(int i =1 ; i<=n;i++){
        for(int t=1;t<=n;t++){
            if(i == t){
                vec[i][t] = 0;
            }
        }
    }


    for(int i=0; i<m;i++){
        cin >> a >> b >>c;
        vec[a][b] = min(vec[a][b],c);
    }
    // 각 간선에서 이동하는 비용을 갱신
    // 여기서 이제 플로이드 알고리즘을 적용시키면 되는 것이다.

    for(int i=1;i<=n;i++){
        // 하나씩 이제 1부터 자기를 거치는거랑 다른거랑 어떤게 큰지 구하면 되는 것이다.
        for(int t= 1;t<=n;t++){
            if(i == t){
                continue;
            }
            for(int p=1;p<=n;p++){
                vec[t][p] = min( (vec[t][i] + vec[i][p] ),vec[t][p]);
            }
        }
    }



    // 마지막에 INT_MAX를 이제 0으로 변환
    for(int i =1 ; i<=n;i++){
        for(int t=1;t<=n;t++){
            if(vec[i][t] == 10000050){
                vec[i][t] = 0;
            }
        }
    }


    for(int i =1 ; i<=n;i++){
        for(int t=1;t<=n;t++){
            cout << vec[i][t] << " ";
        }
        cout << "\n";
    }
    
}