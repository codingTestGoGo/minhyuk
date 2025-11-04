#include<bits/stdc++.h>

using namespace std;

vector<int> arr(1000006,-1);

int find(int a){
    if(arr[a]<0){
        return a;
    }
    return arr[a] = find(arr[a]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b){
        return false;
    }

    if(arr[b] < arr[a]){
        swap(a,b);
    }
    if(arr[a] == arr[b])
        arr[a] --;
    arr[b] = a;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    int temp1,temp2,temp3;
    for(int i=0;i<m;i++){
        cin >> temp1 >> temp2 >> temp3;

        if(temp1 == 1){
            if(find(temp2) == find(temp3)){
                cout << "yes\n";
                continue;
            }else{
                cout << "no\n";
                continue;
            }
        }else{
            uni(temp2,temp3);
        }
    }


}