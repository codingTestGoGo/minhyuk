#include<bits/stdc++.h>


using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long int sums = 0; // 모든 합을 구해야함
    //모든 합을 더함
    vector<int> que;
    int sizes = queue1.size();
    for(int i =0;i<sizes;i++){
        sums += queue1[i];
        sums += queue2[i];
    }
    for(auto it : queue1){
        que.push_back(it);
    }
    for(auto it : queue2){
        que.push_back(it);
    }
    
    if(sums % 2 != 0){
        // 홀수인 경우는 애초에 안됨
        return -1;
    }
    long long int temp = 0; // 맨 처음은 넣어줌
    //모든 애들을 하나의 배열에 집어 넣음
    int st =0, en = 0;
    int stCount = 0;
    int enCount = 0;
    for(st = 0;st<que.size();st++){
        while(en < que.size() && temp < sums/2){
            temp += que[en];
            enCount = max(0, en - sizes+1);
            en ++;
        }  
        if(temp == sums/2){
            if(en >= sizes){
                answer = enCount + stCount;
                break;
            }
        }
        temp -= que[st];
        stCount++;
    }
    
    
    return answer;
}