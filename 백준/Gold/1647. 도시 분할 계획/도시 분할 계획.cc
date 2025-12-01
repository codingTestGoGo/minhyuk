#include<bits/stdc++.h>

using namespace std;
vector<int> vec(1000010,-1);

int find(int x ){
    if(vec[x] < 0){
        return x;
    }
    return vec[x] = find(vec[x]);
}

bool uni(int x , int y){
    x = find(x);
    y=  find(y);

    if(x == y){
        return false;
    }

    if(vec[x] > vec[y]){
        swap(x,y);
    }
    if(vec[x] == vec[y]){
        vec[x]--;
    }

    vec[y] = x ;

    return true;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , M;
    cin >> N >> M;

    int temp1, temp2, temp3;
    vector<tuple<int,int,int>> arr;

    for(int i =0;i<M;i++){
        cin >> temp1 >> temp2 >> temp3;
        arr.push_back({temp3, temp1,temp2});
    }

    sort(arr.begin(),arr.end());
    int cnt = 0;
    long long int answer = 0;
    set<int> sets;
    int x,y,weights;
    int tempers=0;

    if ( N == 2){
        cout << 0 << "\n";
        return 0;
    }

    for(int i=0;i<arr.size();i++){
        tie(weights,x,y) = arr[i];

        if(!uni(x,y)) continue;
        sets.insert(x);
        sets.insert(y);
        answer += weights;
        cnt ++;
        if(cnt == N-2){
            tempers = i;
            break;
        }
        // cout << weights << "\n";
    }

    // for(int i=tempers+1;i<arr.size();i++){
    //     tie(weights,x,y) = arr[i];

    //     // if(sets.find(x) != sets.end()) continue;
    //     // if(sets.find(y) != sets.end()) continue;
    //     if(!uni(x,y)) continue;

    //     answer += weights;
    //     // cout << weights << "here"<<  "\n";
    //     cnt ++;
    //     if(cnt == N-2){
    //         break;
    //     }
    // }


    cout << answer << "\n";

}