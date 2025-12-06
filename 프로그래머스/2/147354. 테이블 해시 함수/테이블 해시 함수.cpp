#include<bits/stdc++.h>


using namespace std;

int colG;

bool comp(vector<int> a, vector<int> b){
    if(a[colG-1] == b[colG-1]){
        return a[0] > b[0];
    }
    
    return a[colG-1] < b[colG-1];
}

int getAns(vector<int> vec,int i){
    int temp = 0;
    for(auto it : vec){
        // cout << it << "\n";
        temp += (it%i);
    }
    return temp;
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    colG = col;
    sort(data.begin(),data.end(),comp);
    
    vector<int> ans;
    for(int i=row_begin; i<=row_end;i++){
        ans.push_back(getAns(data[i-1],i));
    }
    
    answer = ans[0];
    // cout << answer << "\n";
    for(int i=1;i<ans.size();i++){
        // cout << ans[i] << "\n";
        answer ^= ans[i];
    }
    
    return answer;
}