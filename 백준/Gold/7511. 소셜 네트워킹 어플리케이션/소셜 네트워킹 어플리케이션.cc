#include<bits/stdc++.h>

using namespace std;

vector<int> arr(1000006,-1);

int find(int x){
    if(arr[x] < 0){
        return x;
    }
    return arr[x] = find(arr[x]);
}


bool uni(int a,int b){
    a = find(a);
    b = find(b);

    if(a==b){
        return false;
    }
    if(arr[a] < arr[b]){
        swap(a,b);
    }

    // 같은 경우에 대한 예외처리
    if(arr[a] == arr[b]){
        arr[a]--;
    }

    arr[b] = a;
    return true;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n,k;
    int a,b;
    int m;
    
    for(int i=0;i<T;i++){
        cin >> n >> k;
        fill(arr.begin(),arr.begin()+n+1,-1);
        for(int t= 0; t<k;t++){
            cin >> a >> b;
            uni(a,b);
        }
        cin >> m;
        cout << "Scenario " << i+1 << ":" << "\n";
        for(int t=0;t<m;t++){
            cin >> a >> b;
            if(find(a) == find(b)){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        } 
        cout << "\n";
    }

}