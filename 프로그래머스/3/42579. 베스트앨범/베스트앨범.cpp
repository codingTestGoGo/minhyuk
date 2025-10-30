#include<bits/stdc++.h>

using namespace std;

bool compares(pair<int,int> A, pair<int,int> B){
    if(A.first == B.first){
        return A.second < B.second;
    }
    
    return A.first > B.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 2개씩만 베스트 앨범
    map<string,pair<int,vector<pair<int,int>>>> maps;
    
    // vector<vector<pair<int,int>>> vecs;
    for(int i=0;i<genres.size();i++){
        if(maps.find(genres[i]) == maps.end()){
            pair<int,vector<pair<int,int>>> temp;
            temp.first = plays[i];
            vector<pair<int,int>> newV;
            newV.push_back({plays[i],i});
            // int nums = vecs.size();
            // vecs.push_back(newV);
            temp.second = newV;
            maps.insert({genres[i],temp});
        }else{
            maps[genres[i]].first += plays[i];
            maps[genres[i]].second.push_back({plays[i],i});
        }
    }
    map<int,string,greater<int>> newMap;
    for(auto it : maps){
        newMap.insert({it.second.first,it.first});
    }
    
    // 정렬된 문자열들을 바탕으로 처리
    for(auto it : newMap){
        // cout << it.second << "\n";
        // cout << it.first << "\n";
        pair<int,vector<pair<int,int>>> tempers = maps[it.second];
        sort(tempers.second.begin(),tempers.second.end(),compares);
        if(tempers.second.size() == 1){
            answer.push_back(tempers.second[0].second);
        }else{
            answer.push_back(tempers.second[0].second);
            answer.push_back(tempers.second[1].second);
        }
    }
    
    return answer;
}