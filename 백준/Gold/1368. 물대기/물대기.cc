#include<bits/stdc++.h>

using namespace std;

vector<int> arr(400,-1);

int find(int x){
    if(arr[x] < 0){
        return x;
    }
    return arr[x] = find(arr[x]);
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);


    if( x== y){
        return false;
    }

    if(arr[x] > arr[y]){
        swap(x,y);
    }

    if(arr[x] == arr[y]){
        arr[x] --;
    }

    arr[y] = x;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int temp;
    vector<int> we;
    vector<tuple<int,int,int>> vec;

    for(int i =0 ; i<N;i++){
        cin >> temp;
        vec.push_back({temp,i,N});
    }   



    for(int i =0;i<N;i++){
        for(int t=0;t<N;t++){
            cin >> temp;
            if(i != t){
                vec.push_back({temp,i,t});
            }
        }
    }


    sort(vec.begin(),vec.end());
    int cnt = 0;
    int answer = 0;
    int tempWeight = 4000000;
    int lines, weights ,x ,y;
    for(int i =0; i<vec.size();i++){
        tie(lines,x,y) = vec[i];
        // if( lines-weights >= tempWeight) continue;
        if(!uni(x,y)) continue;

        cnt ++;
        answer += lines;
        if(cnt == N){
            break;
        }
    }

    cout << answer << "\n";
    // cout << answer << "\n";
    // cout << tempWeight << "\n";


}