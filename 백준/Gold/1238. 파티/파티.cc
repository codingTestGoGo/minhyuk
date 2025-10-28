#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> vec(1005);

int getAns(int st, int en){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> arr(1010,10000000);

    que.push({0,st});
    arr[st] = 0;

    while(!que.empty()){
        pair<int,int> temp = que.top();
        que.pop();

        if(temp.first != arr[temp.second]){
            continue;
        }
        for(auto it : vec[temp.second]){
            if(arr[it.second] > it.first + arr[temp.second]){
                int temper = it.first + arr[temp.second];
                arr[it.second] = temper;
                que.push({temper,it.second});
            }
        }

    }
    return arr[en];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,X;

    cin >> n >> m >> X;

    int st,en,t;
    for(int i =0 ; i<m;i++){
        cin >> st >> en >> t;
        vec[st].push_back({t,en});
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, getAns(i,X) + getAns(X,i));
    }

    cout << ans << "\n";
}