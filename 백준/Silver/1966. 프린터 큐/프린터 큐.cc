#include<bits/stdc++.h>

using namespace std;

bool compares(pair<int,int> s, pair<int,int> q){
    if(s>= q){
        return true;
    }else{
        return false;
    }
}

int getAns(int N, int M){
    vector<int> maxV;
    queue<pair<int,int>> que;
    int temp; 
    for(int i =0 ;i< N;i++){
        cin >> temp;
        que.push({temp,i});
        maxV.push_back(temp);
    }

    sort(maxV.begin(),maxV.end(),greater<int>());
    int cnt = 0;
    int outer = 0;
    while(!que.empty()){
        pair<int,int> tops = que.front();
        que.pop();
        int maxs = maxV[outer];
        if(maxs > tops.first){
            que.push(tops);
        }else{
            maxV[outer] = 0;
            outer ++ ;
            if(tops.second == M){
                return outer;
            }
        }
    }
    return cnt;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int temp1, temp2;
    for(int i= 0; i< T; i++){
        cin >> temp1 >> temp2;
        cout << getAns(temp1,temp2) << "\n";
    }

}