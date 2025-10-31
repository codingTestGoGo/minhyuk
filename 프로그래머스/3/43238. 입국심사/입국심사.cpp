#include<bits/stdc++.h>


using namespace std;

long long int realAn = 10000000000;
int N;
long long int solv(long long int n ,vector<int> times){
    long long int ans=0;
    long long int temp=0;
    // auto it= upper_bound(times.begin(),times.end(),n);
    for(int i =0;i<times.size();i++){
        if(temp > 1000000009){
            break;
        }
        temp += (n/times[i]);  // 큰놈까지 걸리는데 내가 수행하는 횟수
    }
    // cout << N/temp << "\n";
    // realAn = min(realAn,N/temp);
    return temp;
}

long long solution(int n, vector<int> times) {
    long long answer = 10000000000;
    N = n;
    // 비어있는 칸도 고려하고 10억이니까 10억이라는 상황을 고려해야함
    sort(times.begin(),times.end());
    
    long long int st = 1;
    long long int en = 10000000000005;
    while(st < en){
        long long int mid = (st+en)/2;
    
        long long int temp  = solv(mid,times);
        
        if(temp < n){
            st = mid+1;
        }else{
            en = mid;
        }
    }
    answer = st;
    return answer;
}