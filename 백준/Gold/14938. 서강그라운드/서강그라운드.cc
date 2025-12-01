#include<bits/stdc++.h>


#define INF = 0x3f3f3f3f

using namespace std;


vector<vector<int>> vec(110,vector<int>(110,0x3f3f3f3f));

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 인접행렬로서 구하는 것이다.
    int n, m, r;

    cin >> n >> m >> r;


    // 보물의 값어치를 vector에 저장
    vector<int> jewels;
    int temp;
    jewels.push_back(0);
    for(int i =0; i<n;i++) {
        cin >> temp;
        jewels.push_back(temp);
    }

    int temp2, temp3;

    for(int i=0;i<r;i++){
        cin >> temp >> temp2 >> temp3;
        vec[temp][temp2] = temp3;
        vec[temp2][temp] = temp3;
    }

    for(int i=1; i<=n;i++){
        for(int t=1;t<=n;t++){
            for(int p = 1; p<=n;p++){
                if(t == p){
                    vec[t][p] = 0;
                    continue;
                }
                vec[t][p] = min((vec[t][i] + vec[i][p]),vec[t][p]);
            }
        }
    }

    int answer = 0;
    int temper=0;
    for(int i =1 ;i<=n;i++){
        temper = 0;
        for(int t=1;t<=n;t++){
            if(vec[i][t] <= m ){
                // cout << "이때" << i << ": " << jewels[t] << "\n";
                temper += jewels[t];
            }
        }
        answer = max(temper,answer);
    }

    cout << answer << "\n";







}