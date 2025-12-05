#include<bits/stdc++.h>

using namespace std;
vector<bool> era(900000000,1);

bool isPrime(long long int x){
    if(x < 2){
        return false;
    }
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    
    for(long long int i=3;i*i<=x;i+=2){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

bool isEra(long long int  x){
    if(x > 900000000){
        return isPrime(x);
    } 
    return era[x];
}

string changeNum(int n,int k){
    if(k == 10){
        return to_string(n);
    }
    string temp = "";
    while(n>=1){
        int t1 = n%k;
        temp += to_string(t1);
        n /= k;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

void makeEra(){
        era[0] = 0;
        era[1] = 0;
        for(long long int i =2; i*i<=900000000;i++){
        if(era[i]){
            for(long long int t = i*i;t<=900000000;t+=i){
                era[t] = 0;
            }
        }
    }
}

int solution(int n, int k) {
    int answer = 0;
    string numbers  = changeNum(n,k);
    makeEra();
    string temp = "";
    for(auto it : numbers){
        if(it == '0'){
            if(temp.size() ==0){
                continue;
            }else{
                if(isEra(stoll(temp))){
                    answer ++;
                }
            }
            temp = "";
        }else{
            temp+= it;
        }
    }
    
    if(temp.size()!=0){
        if(isEra(stoll(temp))){
            answer ++;
        }
    }
    
    return answer;
}