#include<bits/stdc++.h>


using namespace std;
pair<int,int> pairs ; // 분과 시간 관리
// 그냥 전부 초로 관리하는게 이득 마지막에만 변환시켜주면 됨
// 그냥 전부 초로 관리해서 푸는 무제 -> 시간을 하나로 통일하기
int currentTime;

void goPrev(){
    // if(pairs.first == 0){
    //     if(pairs.second <= 10){
    //         pairs.second = 0;      
    //     }else{
    //         pairs.second -= 10;
    //     }
    // }else{
    //     if(pairs.second < 10){
    //         pairs.second = pairs.second + 60 - 10;
    //         pairs.first --;
    //     }else{
    //         pairs.second -= 10;
    //     }   
    // }
    
    if(currentTime -10 <=0){
        currentTime = 0;
    }else{
        currentTime -= 10;
    }
}

void goNext(string video_len){
    int lenMinutes = stoi(video_len.substr(0,2));
    int lenSeconds = stoi(video_len.substr(3,2));
    int maxSec = lenMinutes*60 + lenSeconds;
    
    if(currentTime+10 >= maxSec){
        currentTime = maxSec;
    }else{
        currentTime += 10;
    }
    
//     if(pairs.second >= 50){
//         pairs.second = pairs.second + 10 - 60;
//         pairs.first++;
//     }else{
//         if(lenMinutes==pairs.first && lenSeconds <= pairs.second + 10){
//             pairs.second = lenSeconds;
//         }else{
//             pairs.second += 10;   
//         }
//     }
}


void goOpen(string op_start, string op_end){
    int opSMinutes = stoi(op_start.substr(0,2));
    int opSSeconds = stoi(op_start.substr(3,2));
    
    int opEMinutes = stoi(op_end.substr(0,2));
    int opESeconds = stoi(op_end.substr(3,2));
    
    int startSec = opSMinutes*60 + opSSeconds;
    int endSec = opEMinutes*60 + opESeconds;

    // cout << startSec <<" 시작" << endSec << "끝 " << nowTime << "현재\n";
    if(currentTime>=startSec && currentTime <= endSec){
        pairs.first = opEMinutes;
        pairs.second = opESeconds;
        currentTime = endSec;
    }

} 

string makeAns(){
    string temp ="";
    int mins = currentTime / 60;
    int secs = currentTime % 60;
    
    if(mins < 10){
        temp += "0";
        temp += to_string(mins);
    }else{
        temp+= to_string(mins);
    }
    
    temp += ":";
    if(secs < 10){
        temp += "0";
        temp += to_string(secs);
    }else{
        temp+= to_string(secs);
    }
    return temp;
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    // 그냥 구현 문제다.
    int stMinutes = stoi(pos.substr(0,2));
    int stSeconds = stoi(pos.substr(3,2));
    currentTime = stMinutes * 60 + stSeconds;
    
    pairs = {stMinutes,stSeconds};
    
    for(auto it : commands){
        goOpen(op_start,op_end);
        if(it == "next"){
            goNext(video_len);
        }else if(it == "prev"){
            goPrev();
        }    
        // cout << pairs.first << ":" <<pairs.second << "\n";
    }
    goOpen(op_start,op_end);
    
    answer = makeAns();
    
    return answer;
}