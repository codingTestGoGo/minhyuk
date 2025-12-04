#include<bits/stdc++.h>

using namespace std;

int dp[101][100001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<pair<int,int>> vec;
    int weight ,val;
    for(int i =0;i<N;i++){
        cin >> weight >> val;
        vec.push_back({weight,val});
    }

    sort(vec.begin(),vec.end());


    for(int i=1;i<=N;i++){
        int tempWeight = vec[i-1].first;
        int tempVal = vec[i-1].second;
        for(int w = 0;w<=W;w++){
            if(w-tempWeight >=0){
                dp[i][w] = max(dp[i-1][w],dp[i-1][w-tempWeight] + tempVal);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }


    cout << dp[N][W] << "\n";



}