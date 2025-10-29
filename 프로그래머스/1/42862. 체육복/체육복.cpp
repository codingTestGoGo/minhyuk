#include<bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> vec(35,0);
    vector<int> arr(35,0);

    for(int i= 0;i<reserve.size();i++){
        arr[reserve[i]] = 1;
    }
    sort(lost.begin(),lost.end());
    
    int solvL = 0;
    // 모든 경우의 수로 구해야함 -> 어떤 애가 무엇을 고르느냐에 따라 다르게 동작하게 되는 것임
    // 앞에 것을 고르는 경우가 좋을 수도 있고 뒤의 것을 고르는 경우가 좋을 수도 있음
    for(int i =0 ;i<lost.size();i++){
        int it = lost[i];
        for(int t= 0;t<reserve.size();t++){
            if(it == reserve[t]){
                vec[i] = 1;
                arr[reserve[t]] = 0;
            }
        }
    }
    
    for(int i =0 ;i<lost.size();i++){
        int it = lost[i];
        for(int t=0;t<reserve.size();t++){
            if(it-1 == reserve[t] && arr[reserve[t]] ==1){
                arr[reserve[t]] = 0;
                vec[i] = 1;
                break;
            }
        }
        if(vec[i] == 0){
              for(int t=0;t<reserve.size();t++){
            if(it+1 == reserve[t]&& arr[reserve[t]] ==1){
                arr[reserve[t]] = 0;
                vec[i] = 1;
                break;
            }
        }      
        }
        
    }
    int temp =0;
    for(int i=0;i<lost.size();i++){
        if(vec[i] == 1){
            temp ++;
        }
    }
    answer = n- (lost.size()-temp);

    // answer = n - (lost.size() - solvL);
//     solvL=0;
    
//     for(int i =0 ;i<lost.size();i++){
//         int it = lost[i];
//        if(realR2.empty()){
//             continue;
//         }
//         if(realR2.find(it) != realR2.end()){
//             solvL ++;
//             realR2.erase(it);
//         }
//     }
//     for(int i =0 ;i<lost.size();i++){
//         int it = lost[i];
//        if(realR2.empty()){
//             continue;
//         }
//         if(realR2.find(it+1) != realR2.end()){
//             solvL ++;
//             realR2.erase(it+1);
//         }else  if(realR2.find(it-1) != realR2.end()){
//              solvL ++;
//             realR2.erase(it-1);
//         }
//     }
//     int temper = (n - (lost.size() - solvL));
//     answer = max(answer ,  temper);
    return answer;
}