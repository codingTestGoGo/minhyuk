#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100100];
vector<int> ans(100100,0);


// int getAns(vector<int> &parents,int temp){
//     if(ans[temp]){
//         return ans[temp];
//     }
//     int answer = 0;
//     queue<int> que;
//     que.push(temp);
//     answer += 1;

//     while(!que.empty()){
//         int temper = que.front();
//         que.pop();

//         for(auto it : adj[temper]){
//             if(it == parents[temper]) continue;
//             if(ans[temp]!=0){
//                 answer += ans[temp];
//                 continue;
//             }
//             que.push(it);
//             answer++;
//         }
//     }
//     ans[temp] = answer;
//     return answer;
// }

int getAns(vector<int> &parents, int temp){
    if(ans[temp]){
        return ans[temp];
    }
    if((adj[temp].size() == 1 && parents[temp] !=0) || adj[temp].size() == 0){
        return ans[temp] = 1;
    }
    int answer = 1;
    for(auto it : adj[temp]){
        if(parents[temp] == it)continue;
        answer += getAns(parents,it);
    }
    return ans[temp] = answer;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N ,R ,Q;

    cin >> N >> R >> Q;

    int temp1, temp2;

    // 인접리스트 생성
    for(int i=0;i<N-1;i++){
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

    // 먼저 부모 배열에 대한 값을 구함
    vector<int> parents(100100,-1);
    queue<int> que;
    que.push(R);
    parents[R] = 0;
    while(!que.empty()){
        int temp = que.front();
        que.pop();
        for(auto it : adj[temp]){
            if(parents[it]== -1){
                parents[it] = temp;
                que.push(it);
                // cout << it << "\n";
            }
        }
        // cout << "here\n";
    }
    // 모든 부모에 대한 값을 구함

    
    for(int i=0;i<Q;i++){
        cin >> temp1;
        cout << getAns(parents,temp1) << "\n";
    }


}