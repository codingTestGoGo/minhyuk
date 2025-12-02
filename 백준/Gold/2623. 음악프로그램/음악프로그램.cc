#include<bits/stdc++.h>

using namespace std;

//indegree
vector<int> indegree(1010,0);
vector<int> adj[1010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> answer;
    queue<int> que;

    int temp;
    int val;
    int val2;

    // 인접리스트를 어떻게 만들 수 있느냐 
    // 인접리스트에 대한 생성

    for(int i =0;i<M;i++){
        cin >> temp;
        vector<int> vecs;
        for(int t= 0; t<temp;t++){
            cin >> val;
            if(t!=0){
                //맨 처음인 경우
                adj[val2].push_back(val);
                //같은 순서인 경우
                indegree[val]++; // 단계가 하나씩 필요한 경우 제외해줌
            }
            val2 = val;
        }
    }


    // 우선 0인 애들 넣어줌
    for(int i=1;i<=N;i++){
        if(indegree[i] == 0){
            // cout << i <<"\n";
            que.push(i);
        }
    }

    //위상 정렬의 구현
    while(!que.empty()){
        int temper = que.front();
        que.pop();
        answer.push_back(temper);
        for(auto it : adj[temper]){
            indegree[it]--;
            if(indegree[it] == 0){
                que.push(it);
            }
        }
    }

    if(answer.size() != N){
        cout << 0 << "\n";
        return 0;
    }
    for(auto it : answer){
        cout << it << "\n";
    }

}