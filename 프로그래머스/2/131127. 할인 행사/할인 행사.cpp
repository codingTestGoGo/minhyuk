#include<bits/stdc++.h>


using namespace std;

map<string,int> ans;
map<string,int> users;
bool checkOk(){
    
    for(auto it :ans){
        if(users[it.first] != it.second){
            return false;
        }
    }
    return true;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    
    int slidingSize = 0;
    for(auto it :number){
        slidingSize += it;
    }
    
    int st = 0;
    int en = st + slidingSize;
    
    
    
    // 하나의 Map으로 만들어서 관리함
    for(int i =0; i<want.size();i++){
        ans.insert({want[i],number[i]});
    }
    

    // 일단 초기 배열 넣고 확인
    for(int i =0;i<slidingSize;i++){
        users[discount[i]]++;
    }
    
//     for(auto it : ans){
//         cout << it.first << ":" << it.second << "\n";
//     }
    
//     for(auto it :users){
//         cout << it.first << ":" << it.second << "\n";
//     }
    
    if(checkOk()){
        answer++;
    }
    
    // 그 뒤에는 앞에 하나 빼고 뒤에 하나 추가하면 됨
    for(int i=slidingSize;i<discount.size();i++){
        users[discount[st]] --;
        if(users[discount[st]] == 0){
            users.erase(discount[st]);
        }
        users[discount[i]] ++;
        // 하나만 변경된 것을 어떻게 확인할까
        if(checkOk()){
            answer++;
        }
        st++;
    }
    
    return answer;
}