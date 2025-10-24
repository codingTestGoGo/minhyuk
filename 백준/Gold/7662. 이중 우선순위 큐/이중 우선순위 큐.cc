#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int k;
    char tempC;
    int tempI;
    for(int i =0; i<T;i++){
        cin >> k;
        multiset<int> sets;
        for(int t= 0;t<k;t++){
            cin >> tempC >> tempI;
            if(tempC == 'I'){
                sets.insert(tempI);
            }else{
                if(sets.empty()){
                    continue;
                }
                if(tempI == 1){
                    auto it = sets.end();
                    it --;
                    sets.erase(it);
                }else{
                    auto it = sets.begin();
                    sets.erase(it);
                }
            }
        }
        if(sets.empty()){
            cout << "EMPTY\n";
        }else{
            auto it = sets.end();
            it --;
            cout << *it  << " "  << *sets.begin() << "\n";
        }

    }


}