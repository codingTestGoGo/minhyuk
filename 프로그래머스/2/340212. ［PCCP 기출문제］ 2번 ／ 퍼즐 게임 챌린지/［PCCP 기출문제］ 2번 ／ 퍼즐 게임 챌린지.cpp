#include<bits/stdc++.h>

using namespace std;

bool checking(int mid,vector<int> diffs, vector<int> times, long long limit){
    
    long long totals = times[0];
    
    for(int i =1 ;i<times.size();i++){
        if(diffs[i] > mid){
            totals += (diffs[i] - mid) * (times[i] + times[i-1]);
        }
        totals += times[i];
    }
    
    if(totals <= limit){
        return true;
    }else{
        return false;
    }
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int st = 1;
    int en = 100000;
    
    
    while(st < en){
        int mid = (st+en)/2;
        // cout << mid << "\n";
        
        if(checking(mid,diffs,times,limit)){
            // 만족하는 경우
            en = mid;
        }else{
            st = mid + 1;
        }
    }
    answer = st;

    
//     long long int nowTotalTime = 0;
//     for(auto it : times){
//         nowTotalTime += it;
//     }
//     // 일단 전체 필요시간을 더 함
    
//     // 길이
//     int len = diffs.size();
    
//     long long int forX =0;
//     forX = (2*nowTotalTime - times[0] - times[len-1]);
    
//     long long int extras =0;
//     for(int i=1; i< len ;i++){
//         // cout << extras << "\n";
//         extras += diffs[i] *(times[i] + times[i-1]);
//     }
//     // cout << extras  << ":"<< nowTotalTime << ":" << limit << ":" << forX <<"\n";
    
    
//     if((extras%forX  + nowTotalTime%forX - limit%forX )%forX != 0){
//         answer = (extras/forX + nowTotalTime/forX - limit/forX);
//         answer += 1;
//     }else{
//         answer = (extras/forX + nowTotalTime/forX - limit/forX);
//     }
    
    return answer;
}