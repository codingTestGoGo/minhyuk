#include<bits/stdc++.h>

using namespace std;
long long int N,P,Q;
map<long long int,long long int> maps;

long long int getAns(long long int x){
    
    if(maps.find(x) != maps.end()){
        return maps[x];
    }

    if(x ==0 ){
        return 1;
    }
    if(x==1){
        return 2;
    }

    long long int answer=0;
    answer  = getAns(x/P) + getAns(x/Q);
    maps.insert({x,answer});
    return answer ;
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> Q;

    cout << getAns(N) << "\n";
    
}