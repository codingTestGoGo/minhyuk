#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    int st;
    cin >> st;

    int u,v,w;
    // 정점 2만개 짜리도 인접 리스트? 행렬?
    vector<map<int,int>> vec(20001);

    for(int i = 0; i< E;i++){
        cin >> u >> v >> w;
        if(vec[u].find(v) == vec[u].end()){
            vec[u].insert({v,w});
        }else{
            vec[u][v] =  min(vec[u][v], w);
        }
    }
    // 가중치를 가진 인접리스트 형성 => map을 써서 시간을 줄임
    // 가중치, 어떤 간선인지
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> arr(20001,4000000);

    arr[st] = 0 ;
    que.push({0,st});
    //얘가 처음에 갈 수 있는 애들은 갱신
    for(auto it : vec[st]){
        arr[it.first] = it.second;
        que.push({it.second,it.first});
    }

    while(!que.empty()){
        pair<int,int> temp = que.top();
        que.pop();

        // 얘를 기준이로 이제 거리를 갱신해서 넣어주면서 하나씩 더 작거나 변경된 것이 있는지 확인
        if(arr[temp.second] < temp.first){
            continue;
        }
        arr[temp.second] = temp.first;
        for(auto it : vec[temp.second]){
            if(arr[it.first] > it.second + arr[temp.second]){
                // 더 작게 갱신됨
                que.push({it.second+arr[temp.second], it.first});
                arr[it.first] = it.second+arr[temp.second];
            }
        }
    }  

    for(int i =1;i<=V;i++){
        if(arr[i] ==4000000 ){
            cout << "INF\n";
        }else{
            cout << arr[i] << "\n";
        }
    }

    
}