#include<bits/stdc++.h>

using namespace std;
map<string,int> maps;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    for(auto it : clothes){
        if(maps.find(it[1]) != maps.end()){
            //존재하는 경우
            maps[it[1]]++;
        }else{
            maps.insert({it[1],1});
        }
        
    }
    int temp = 1;
    for(auto it : maps){
        temp *= (it.second+1);
    }
    answer = temp -1;
    
    return answer;
}