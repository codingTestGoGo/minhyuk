#include<bits/stdc++.h>

using namespace std;




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 문자열에 대한 처리가 귀찮은 문제네 그냥
    set<int> sets;
    int N; 
    cin >> N;

    string temp;
    int nm;
    for(int i=0; i< N;i++){
        cin >> temp;
        if(temp == "add"){
            cin >> nm;
            sets.insert(nm);
        }else if(temp == "remove"){
            cin >> nm;
            sets.erase(nm);
            
        }else if(temp == "check"){
            cin >> nm;
            if(sets.find(nm) == sets.end()){
                cout << 0 << "\n";
            }else {
                cout << 1 <<"\n";
            }
        }else if(temp == "toggle"){
            cin >> nm;
            if(sets.find(nm) == sets.end()){
                sets.insert(nm);
            }else {
                sets.erase(nm);
            }
        }else if(temp == "all"){
            for(int i =1;i<=20;i++){
                sets.insert(i);
            }
        }else if(temp == "empty"){
            sets.clear();
        }

    }


}