#include<bits/stdc++.h>

using namespace std;
map<string,int> maps;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(auto it : participant){
        if(maps.find(it) == maps.end()){
            maps.insert({it,1});
        }else{
            //이미 존재하는 경우
            maps[it] ++;
        }
    }
    
    for(auto it : completion){
        maps[it]--;
    }
    
    for(auto it : maps){    
       // cout << it.second << "\n";
       if(it.second != 0){
            answer = it.first;
        }
    }
    
    return answer;
}