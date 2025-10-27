#include<bits/stdc++.h>

using namespace std;
int INF = 1e9+10;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin >> N >> M;

    vector<map<int,int>> vec(N+1);

    int c,v,w;

    for(int i=0;i<M;i++){
        cin >> c >> v >> w;
        if(vec[c].find(v) == vec[c].end()){
            vec[c].insert({v,w});
        }else{
            vec[c][v] = min(vec[c][v],w);
        }
    }

    int st,en;
    cin >> st >> en;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> arr(N+5,INF);
    vector<int> pre(N+5,0);

    arr[st] = 0;
    pre[st] = st;
    que.push({0,st});
    for(auto it : vec[st]){
        pre[it.first] = st;
        arr[it.first] = it.second;
        que.push({it.second,it.first});
    }

    while(!que.empty()){
        pair<int,int> temp = que.top();
        que.pop();
        // 왜냐면 이렇게 더 작은 값인 애에 대해서만 선택을 진행할 것이기 때문에
        if(arr[temp.second] != temp.first){
            continue;
        }

        for(auto it : vec[temp.second]){
            if(arr[it.first] > arr[temp.second] + it.second){
                int nows = arr[temp.second] + it.second;
                arr[it.first] = nows;
                que.push({nows,it.first});
                pre[it.first] = temp.second;
            }

        }
    }

    cout << arr[en] << "\n";
    
    queue<int> ques;
    vector<int> ans;
    ans.push_back(en);
    ques.push(pre[en]);
    while(!ques.empty()){
        int nn =ques.front();
        // cout << "nn " << nn << "\n";
        ans.push_back(nn);
        ques.pop();
        if(nn == st){
            break;
        }
        ques.push(pre[nn]);
    }

    reverse(ans.begin(),ans.end());

    cout << ans.size() <<"\n";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
    
}