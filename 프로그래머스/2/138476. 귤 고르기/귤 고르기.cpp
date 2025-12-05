#include<bits/stdc++.h>


using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> maps;
    
    for(auto it : tangerine){
        if(maps.find(it) != maps.end()){
            maps[it]++;
            // cout << "Here\n";
        }else{
            maps.insert({it,1});
        }
    }
    vector<pair<int,int>> vec;
    
    for(auto it : maps){
        vec.push_back({it.second,it.first});
    }
    
    sort(vec.begin(),vec.end(),greater<pair<int,int>>());
    
    int temper =0;
    for(auto it: vec){
        temper += it.first;
        // cout<<it.first << ":"<< it.second << "\n";
        answer ++;
        if(temper >= k){
            break;
        }
    }
    
    
    
    return answer;
}