#include<bits/stdc++.h>


using namespace std;

int currentHealth =0;
int maxHealth;
int currentSuccess =0;

void heal(vector<int> bandage){
    
    currentHealth += bandage[1];
    currentSuccess++;
    if(currentSuccess == bandage[0]){
        currentHealth += bandage[2];
        currentSuccess = 0;
    }
    if(currentHealth >= maxHealth){
        currentHealth = maxHealth;    
    }  
}

void attack(int damage){
    currentHealth -= damage;
    currentSuccess = 0;
    if(currentHealth <=0){
        currentHealth = -999999;
    }
}



int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = -1;
    maxHealth = health;
    currentHealth = health;
    
    int maxTime = 0;
    map<int,int> maps; // 공격을 map으로 지정
    // 마지막 공격 시간 파악
    for(auto it : attacks){
        maxTime = max(maxTime , it[0]);
        maps.insert({it[0],it[1]});
    }
    
    for(int i=1;i<=maxTime;i++){
        if(maps.find(i) != maps.end()){
            attack(maps[i]);
        }else{
            heal(bandage);
        }
    }
    
    answer = currentHealth;
    
    if(currentHealth <=0){
        answer = -1;
    }
    return answer;
}