#include<bits/stdc++.h>

using namespace std;


map<int,int> arr[1010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    int temp1, temp2, temp3;
    for(int i =0;i<M;i++){
        cin >> temp1 >> temp2 >> temp3;
        if(arr[temp1].find(temp2) != arr[temp1].end()){
            arr[temp1][temp2] = min(arr[temp1][temp2], temp3); // 더 적은 비용으로 계산할 수 있도록 같은게 나오는 경우
        }else{
            arr[temp1].insert({temp2,temp3}); // 비용과 도시에 대한 인접리스트
        }

    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> temp(1010,500000000);

    cin >> temp1 >> temp2;

    pq.push({0,temp1});
    temp[temp1] = 0;

    while(!pq.empty()){
        pair<int,int> pairs = pq.top();
        pq.pop();

        if(temp[pairs.second] != pairs.first) continue;

        for(auto it : arr[pairs.second]){
            if(temp[it.first] <= temp[pairs.second] + it.second ){
                continue;
            }
            temp[it.first] = temp[pairs.second] + it.second;
            pq.push({temp[it.first],it.first});
        }
    }
    cout << temp[temp2] << "\n";


}