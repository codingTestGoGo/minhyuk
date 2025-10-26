#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n+2,vector<int> (n+2,100000005));
    vector<vector<int>> nxt(n+2,vector<int> (n+2,0));
    for(int i =1;i<=n;i++){
        for(int t=1;t<=n;t++){
            // nxt[i][t] = t;
            if(i == t){
                vec[i][t] = 0;
                nxt[i][t] = 0;
            }
        }
    }
    int a,b,c;
    for(int i =0; i<m;i++){
        cin >> a >> b >> c;
        vec[a][b] = min(vec[a][b], c);
        nxt[a][b] = b;
    }

    for(int i = 1;i<=n;i++){
        for(int t=1;t<=n;t++){
            for(int p=1;p<=n;p++){
                // vec[t][p] = min(vec[t][i]+vec[i][p],vec[t][p]);
                if(vec[t][i] + vec[i][p] < vec[t][p]){
                    vec[t][p] = vec[t][i]+vec[i][p];
                    nxt[t][p] = nxt[t][i]; //이렇게 인접테이블도 갱신시켜줌
                    // 여기서 주의할 것이 만약에 이미 같은 애가 가리키고 있으면 갱신 안함
                    //  
                }
            }
        }
    }

    for(int i =1;i<=n;i++){
        for(int t=1;t<=n;t++){
            if(vec[i][t] == 100000005){
                vec[i][t] = 0;
            }
        }
    }
    // 여기까지가 기본적인 플로이드에 대한 설정
    for(int i =1;i<=n;i++){
        for(int t=1;t<=n;t++){
            cout << vec[i][t] <<  " ";
        }
        cout << "\n";
    }


    // 이제 인접된 애들에 대한 경로 추적
    for(int i =1;i<=n;i++){
        for(int t=1;t<=n;t++){
            int count = 0;
            vector<int> temp;
            if(i == t){
                cout << 0 <<"\n";
           }else if(vec[i][t] == 0){
                cout << 0 << "\n";
           }else{
                // 이제 실제로 지나갈 수 있는 경우에 대한 값을 구함
                
                int num = i;
                int num2 = t;
                count ++;
                temp.push_back(num);
                while(1){
                    count ++;
                    num = nxt[num][t];
                    temp.push_back(num);
                    if(num == t){
                        break;
                    }
                }
                cout << count << " ";
                for(auto it : temp){
                    cout << it << " ";
                }
                cout << "\n";
           }
        }

    }



}