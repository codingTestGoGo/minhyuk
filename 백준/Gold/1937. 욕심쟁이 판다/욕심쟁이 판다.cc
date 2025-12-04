#include<bits/stdc++.h>

using namespace std;

int forX[4] = {0,1,0,-1};
int forY[4] = {-1,0,1,0};

int d[505][505];
int arr[505][505];
int N;

int getAns(int y, int x){
    if(d[y][x] != -1){
        return d[y][x];
    }

    d[y][x] = 1;
    for(int i = 0;i<4;i++){
        int ny = forY[i] + y;
        int nx = forX[i] + x;


        if(nx < 0 || ny <0 || nx >=N || ny >=N){
            continue;
        }
        if(arr[ny][nx] >= arr[y][x]){
            continue;
        }
        
        d[y][x] = max(d[y][x], getAns(ny,nx) + 1);
    }

    return d[y][x];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int temp;
    for(int i =0 ;i <N;i++){
        for(int t= 0 ;t<N;t++){
            cin >> temp;
            arr[i][t] = temp;
            d[i][t] = -1;
        }
    }

    int answer = 0;

    for(int i =0 ;i <N;i++){
        for(int t= 0 ;t<N;t++){
            answer = max(answer,getAns(i,t));
        }
    }
    cout << answer << "\n";


}