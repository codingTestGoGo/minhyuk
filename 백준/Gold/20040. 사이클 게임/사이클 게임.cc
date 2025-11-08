#include<bits/stdc++.h>

using namespace std;

vector<int> arr(500005,-1);

int find(int x){
    if(arr[x] < 0){
        return x;
    }

    return arr[x] = find(arr[x]);
}

bool uni(int u,int v){
    u = find(u);
    v = find(v);

    if(u==v){
        if(u!=-1){
            return false;
        }
    }

    

    if(arr[v] < arr[u]){
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

    int n,m;
    cin >> n >> m;
    int temp1,temp2;
    bool isOk = false;
    for(int i=1;i<=m;i++){
        cin >> temp1 >> temp2;
        if(uni(temp1,temp2) == false && isOk == false){
            cout << i << "\n";
            isOk = true;
        }

    }

    if(!isOk){
        cout << 0 << "\n";
    }

}