#include<bits/stdc++.h>

using namespace std;


vector<int> vec(10010,-1);

int find(int x){
    if(vec[x] < 0){
        return x;
    }
    return vec[x] = find(vec[x]);
}

bool uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x==y){
        return false;
    }

    if(vec[x] > vec[y]){
        swap(x,y);
    }
    if(vec[x] == vec[y]){
        vec[x]--;
    }
    vec[y] = x;
    return true;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V,E;
    cin >> V >> E;


    vector<tuple<long long,int,int>> arr;

    int temp1, temp2 ,temp3;
    for(int i =0; i< E;i++){
        cin >> temp1 >> temp2 >> temp3;
        arr.push_back({temp3,temp1,temp2});
    }

    sort(arr.begin(),arr.end());

    int w,st,en;
    int answer = 0;
    int cnt = 0;
    for(int i =0;i<arr.size();i++){
        tie(w,st,en) = arr[i];

        if(!uni(st,en)) continue;

        answer += w;
        cnt ++;
        if(cnt == V-1){
            break;
        }        
    }

    cout << answer << "\n";
    
}