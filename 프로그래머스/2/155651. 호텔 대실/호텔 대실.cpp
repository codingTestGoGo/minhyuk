#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<string> a, vector<string> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
    
}

string timePlus(string st){
    int idx = st.find(":");
    int hours = stoi(st.substr(0,idx));
    int minutes = stoi(st.substr(idx+1,2));
     minutes += 10;
    if(minutes >= 60){
       hours ++;
       minutes -= 60;
    }
    
    string tmp = "";
    if(hours < 10){
        tmp += "0";
        tmp += to_string(hours);
    }else{
        tmp+= to_string(hours);
    }
    
    tmp += ":";
    if(minutes < 10){
        tmp += "0";
        tmp += to_string(minutes);
    }else{
        tmp+= to_string(minutes);
    }
    return tmp;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 방이 몇 개 필요한지 -> DP의 테이블은 몇 개의 방
    // 걍 그리디네
    // 전에 했던 것
    
    sort(book_time.begin(),book_time.end(),cmp);
    priority_queue<string,vector<string>,greater<string>> que;
    
    
    for(auto it : book_time){
        if(que.empty()){
            que.push(timePlus(it[1]));
        }else{
            while(!que.empty()){
                string tops = que.top();
                if(tops > it[0]){
                    que.push(timePlus(it[1]));
                    break;
                    //아니면 여기서 answer ++;
                }else{
                    que.pop();
                }   
            }
        }
        int sizes = que.size();
        answer = max(answer,sizes);
    }
    
    return answer;
}