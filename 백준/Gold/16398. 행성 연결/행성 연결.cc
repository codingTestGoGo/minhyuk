#include<bits/stdc++.h>

using namespace std;

vector<int> vec(1010,-1);

int find(int x){
    if(vec[x] < 0){
        return x;
    }
    return vec[x] = find(vec[x]);
}


bool uni(int x , int y){
    x = find(x);
    y = find(y);

    if(x == y){
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


    int N;
    cin >> N;


    int temp;
    vector<tuple<long long int,int,int>> vec;

    for(int i =0;i<N;i++){
        for(int t=  0; t<N;t++){
            cin >> temp;
            if(i != t){
                vec.push_back({temp,i,t});
            }
        }
    }

    sort(vec.begin(),vec.end());

    int cnt = 0;
    long long int answer = 0;
    long long int wei;
    int x, y;
    for(int i =0;i<vec.size();i++){
        tie(wei,x,y) = vec[i];

        if(!uni(x,y)) continue;
        answer += wei;
        cnt ++;
        if(cnt == N-1){
            break;
        }

    }

    cout << answer << "\n";


}