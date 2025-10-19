#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // 어떤 데이터를 가지고 있게 끔 할려고 하는 것일ㄱ지
    // 그냥 set으로 해서 갖고 있으면 지우고 하면 될 듯?
    set<string> sets;
    vector<string> vec;
    deque<string> deq;
    map<string,int> maps;
    // 순서 정보를 어떻게 갖고 유지하고 있어야 할까?

    int K , L;
    cin >> K >> L;

    string temp;
    for(int i =0; i < L;i++){
        cin >> temp;
        // 이 find의 속도가 생각보다 오래 걸리는 건가?
        // auto it = find(deq.begin(),deq.end(),temp);
        if(maps.find(temp)!=maps.end()){
            maps[temp] = i;
        }else{
            maps.insert({temp,i});
        }
    }

    map<int, string> mapO;


    for(auto it: maps){
        mapO.insert({it.second,it.first});
    }

    int count = 0;

    for(auto it : mapO){
        if(count == K){
            break;
        }
        // cout << it.first << "\n";
        cout << it.second << "\n";
        count++;

    }
}