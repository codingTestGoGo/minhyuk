#include<bits/stdc++.h>

using namespace std;
map<pair<string,string>,int> maps;

vector<tuple<int,int,int>> vec;
int pickTotal =0 ;

void insertMaps(){
 maps.insert({{"diamond","iron"},5});
 maps.insert({{"diamond","dia"},1});
 maps.insert({{"diamond","stone"},25});
 maps.insert({{"iron","iron"},1});
 maps.insert({{"iron","dia"},1});
 maps.insert({{"iron","stone"},5});
 maps.insert({{"stone","iron"},1});
 maps.insert({{"stone","dia"},1});
 maps.insert({{"stone","stone"},1}); 
}



int getVal(string mineral, string pick){
    return maps[{mineral,pick}];
}


void makeVec(vector<string> minerals){
    
    int val1 =0 , val2= 0, val3=0;
    for(int i =1;i<=minerals.size();i++){
        if(i > pickTotal * 5){
            break;
        }
        
        val1 += getVal(minerals[i-1],"dia");
        val2 += getVal(minerals[i-1],"iron");
        val3 += getVal(minerals[i-1],"stone");
        if(i %5 ==0){
            // 5의 배수인 경우 vec에 집어넣음
            vec.push_back({val1,val2,val3});
            val1 = 0;
            val2 = 0;
            val3 = 0;
        }
    }
    if(val1 != 0 && pickTotal * 5 >= minerals.size()){
        // 남은게 있으면 넣어줌 이때 
        vec.push_back({val1,val2,val3});        
    }
}

bool comp(tuple<int,int,int> a, tuple<int,int,int> b){
    int val1, val2, val3;
    int temp1, temp2;
    
    tie(val1,val2,val3) = a;
    temp1 = val1 + val2 + val3;
    tie(val1,val2,val3) = b;
    temp2 = val1 + val2 + val3;
    
    return temp1 > temp2; 
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    insertMaps();
    
    for(auto it : picks){
        pickTotal += it;
    }
    
    
    
    // tuple 짜리의 합이 큰 것부터 좋은 곡괭이를 선택할 수 있도록 지정함 vec를 2개를 사용함
    makeVec(minerals);
    if(vec.size() >= 1){
         sort(vec.begin(),vec.end(),comp);   
    }
    //가장 큰 순으로 정렬
    int a,b,c;
    for(auto it : vec){
        tie(a,b,c) = it;
        if(picks[0] > 0){
            picks[0] --;
            answer += a;
        }else{
            if(picks[1] > 0){
                picks[1] --;
                answer += b;
            }else{
                if(picks[2] > 0){
                    picks[2] --;
                    answer += c;   
                }
            }
        }
        cout << answer << "\n";
    }
    
    return answer;
}