#include<bits/stdc++.h>

using namespace std;


vector<int> arr(220,-1);

int find(int x){
    if(arr[x]< 0){
        //음수인 상태면 자기가 이제 루트이니까 자기자신을 리턴
        return x;
    }
    return arr[x] = find(arr[x]);
}


bool uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v){
        return false;
    }

    if(arr[v] <arr[u]){
        swap(u,v);
    }
    if(arr[u] == arr[v]){
        arr[u] --;
    }
    arr[v] = u;
    return true;    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int a,b,c;
    for(int i=1;i<=N;i++){

        for(int t= 1;t<=N;t++){
            cin >> a;
            if(a==1){
                uni(i,t);
            }
        }
    }
    int temp = 0;
    int prior = 0;
    cin >> a;
    prior = find(a);
    for(int i=1;i<M;i++){
        cin >> a;
        temp = find(a);
        // cout << temp << "\n";
        if(temp != prior){
            cout << "NO" << "\n";
            return 0;
        }
        
    }

    cout << "YES\n";
    return 0;

}