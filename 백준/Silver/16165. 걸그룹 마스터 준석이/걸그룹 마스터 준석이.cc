#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    map<string,vector<string>> maps;
    map<string,string> maps2;
    string tName;
    string tMem;
    int tSize;
    for(int i= 0; i<N;i++){
        cin >> tName >> tSize;

        vector<string> vec;
        for(int t=0;t<tSize;t++){
            cin >> tMem;
            vec.push_back(tMem);
            maps2.insert({tMem,tName});
        }   
        sort(vec.begin(),vec.end());

        maps.insert({tName,vec});
    }

    for(int i=0;i<M;i++){
        cin >> tName;
        cin >> tSize;
        if(tSize == 1){
            cout << maps2[tName] << "\n";
        }else{
            for(auto it : maps[tName]){
                cout << it << "\n";
            }
        }
    }

}