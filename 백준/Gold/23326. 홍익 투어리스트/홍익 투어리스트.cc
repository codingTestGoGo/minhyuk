#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    set<int> sets;
    long long int temp;
    for(int i =1; i<=N;i++){
        cin >> temp;
        if(temp == 1){
            sets.insert(i);
        }
    }

    int command;
    int loc = 1;
    for(int i =0 ; i<Q;i++){
        cin >> command;
        if(command == 1){
            cin >> temp;
            if(sets.find(temp) == sets.end()){
                sets.insert(temp);
            }else{
                sets.erase(temp);
            }
        }else if(command == 2){
             cin >> temp;
             temp = (temp) % N;
             loc = (loc%N + temp%N) % N; // 얘가 이러면 처음에만 맞고 계속 커질 수 있네 
             if(loc == 0){
                loc = N;
             }
        }else if(command == 3){
            if(sets.empty()){
                cout << -1 << "\n";
            }else if(sets.lower_bound(loc) == sets.end()){
                // 없으면 앞에 있는거니까
                cout << (*sets.begin() + N) - loc  << "\n";
            }else{
                cout << (*sets.lower_bound(loc) - loc) << "\n";
            }
        }
    }
}