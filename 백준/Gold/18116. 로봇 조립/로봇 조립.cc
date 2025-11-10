#include<bits/stdc++.h>

using namespace std;

vector<int> arr(10000000,-1);


int find(int x ){
    if(arr[x] < 0){
        return x;
    }
    return arr[x] = find(arr[x]);
}

bool uni(int u, int v){

    u = find(u);
    v = find(v);

    if( u==v){
        return false;
    }
    if(arr[u] > arr[v]){
        swap(u,v);
    }
    
    arr[u] += arr[v];
    arr[v] = u;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    char temp;
    int a, b;
    for(int i = 0; i<K;i++){
        cin >> temp >> a;
        if(temp == 'I'){
            cin >> b;
            uni(a,b);
        }else{
            if(find(a) == -1){
                cout << 1 << "\n";
            }else{
                int temper = find(a);
                // cout << temper <<"\n";
                cout << abs(arr[temper]) << "\n";
            }
        }

    }
}