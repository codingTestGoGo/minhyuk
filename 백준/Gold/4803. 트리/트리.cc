#include<bits/stdc++.h>

using namespace std;

bool getTreee(vector<set<int>> &arr,int n,int st,vector<int> &visited){

    queue<pair<int,int>> que;
    
    que.push({st,0});
    while(!que.empty()){
        pair<int,int> temp = que.front();
        que.pop();
        visited[temp.first]++;
 
        if(visited[temp.first] > 1){
            return false;
        }

        for(auto it : arr[temp.first]){
            // 전의 것을 선택안하고 싶은건데
            if(temp.second != it){
                que.push({it,temp.first});
            }
        }
    }

    return true;
}

string getAns(vector<set<int>> &arr,int n){
    //만약에 방문했던 애면 X
    vector<int> visited(n+2,0); 
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(getTreee(arr,n,i,visited)){
                answer ++;
            }
        }
    }
    if(answer == 0){
        return "No trees.";
    }else if(answer == 1){
        return "There is one tree.";
    }else{
        return "A forest of " + to_string(answer) + " trees.";
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m;
    int caseC = 1;
    while(1){
        cin >> n >> m;
        if( n==0 && m ==0){
            break;
        }

        vector<set<int>> vec(n+2);
        int temp1, temp2;
        for(int i=0;i<m;i++){
            cin >> temp1 >> temp2;
            vec[temp1].insert(temp2);
            vec[temp2].insert(temp1);
        }

        cout << "Case " << caseC << ": " << getAns(vec,n) << "\n";
        caseC++;
    }
}