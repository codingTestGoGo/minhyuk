#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    
    if(a.second - a.first == b.second - b.first){
        return a.first < b.first;
    }
    return (a.second - a.first ) < (b.second - b.first);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> ans; // 여기에 인덱스들을 담으면 됨
    
    
    // 투포인터 문제
    
    int st = 0;
    int en = 0;
    // 이미 오름차순으로 정렬되어 있음
    
    int sizes = sequence.size();
    int tempK = 0;
    for(st =0;st<sizes; st++){
        while(en <= sizes && tempK <= k ){
            if(tempK == k){
              ans.push_back({st,en-1});
            }
            tempK += sequence[en];
            en ++;
        }
        tempK -= sequence[st];
    }
    if(ans.size() >1){
         sort(ans.begin(),ans.end(),cmp);
    }
    answer.push_back(ans[0].first);
    answer.push_back(ans[0].second);
    return answer;
}