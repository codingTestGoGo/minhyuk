#include<bits/stdc++.h>
using namespace std;
map<pair<pair<int,int>,pair<int,int>>,int> maps;

int getVisited(pair<int,int> temp, pair<int,int> prev){
    if(temp.first < 0 || temp.second < 0 || temp.first > 10 || temp.second > 10 ){
        return -1;
    }else{
        if(maps.empty() || maps.find({temp,prev})== maps.end()){
            maps.insert({{temp,prev},1});
            maps.insert({{prev,temp},1});
            return 1;
        }else{
            return 0;
        }
    }
}

int solution(string dirs) {
    int answer = 0;
    pair<int,int> temp = {5,5};
    pair<int,int> prev;
    int rT;
    for(auto it : dirs){
        if(it == 'U'){
            prev= temp;
            temp.first--;
            rT = getVisited(temp,prev);
            
            if(rT == -1){
                temp.first++;
            }else{
                answer += rT;
            }
        }else if(it == 'D'){
              prev= temp;
            temp.first++;
            rT = getVisited(temp,prev);
            if(rT == -1){
                temp.first--;
            }else{
                answer += rT;
            }
        }else if(it == 'R'){
            prev= temp;
            temp.second++;
            rT = getVisited(temp,prev);
            
            if(rT == -1){
                temp.second--;
            }else{
                answer += rT;
            }
        }else if(it == 'L'){
                  prev= temp;
            temp.second--;
            rT = getVisited(temp,prev);
            
            if(rT == -1){
                temp.second++;
            }else{
                answer += rT;
            }
        }
    }    

    return answer;
}