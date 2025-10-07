#include<bits/stdc++.h>

using namespace std;

string answer = "";
int num[18];
int sizes;

int getNumber(int number){
    return number - 4;
}

void getAns(vector<string> survey, vector<int> choices){
    for(int i=0;i<sizes;i++){
        int temp =0;
        if(survey[i].find('R') != string::npos){
            //R이 존재할 경우
            if(survey[i][0] == 'R'){
                // 앞이 R인 경우
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[0] += abs(temp);
                }else{
                    num[1] += abs(temp);
                }
            }else{
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[1] += abs(temp);
                }else{
                    num[0] += abs(temp);
                }
            }
            
        }else if(survey[i].find('C') != string::npos){
           if(survey[i][0] == 'C'){
                // 앞이 C인 경우
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[2] += abs(temp);
                }else{
                    num[3] += abs(temp);
                }
            }else{
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[3] += abs(temp);
                }else{
                    num[2] += abs(temp);
                }
            }
            
        }else if(survey[i].find('J') != string::npos){
           if(survey[i][0] == 'J'){
                // 앞이 R인 경우
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[4] += abs(temp);
                }else{
                    num[5] += abs(temp);
                }
            }else{
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[5] += abs(temp);
                }else{
                    num[4] += abs(temp);
                }
            }
            
        }else if(survey[i].find('A') != string::npos){
           if(survey[i][0] == 'A'){
                // 앞이 R인 경우
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[6] += abs(temp);
                }else{
                    num[7] += abs(temp);
                }
            }else{
                temp = getNumber(choices[i]);
                if(temp < 0){
                    num[7] += abs(temp);
                }else{
                    num[6] += abs(temp);
                }
            }   
        }
    }
}

string getRealAns(){
    string ans = "";
    if(num[0] >= num[1]){
        ans += "R";
    }else{
        ans += "T";
    }
    
    if(num[2] >= num[3]){
        ans += "C";
    }else{
        ans += "F";
    }
    
    if(num[4] >= num[5]){
        ans += "J";
    }else{
        ans += "M";
    }
    
    if(num[6] >= num[7]){
        ans += "A";
    }else{
        ans += "N";
    }
    return ans;      
}


string solution(vector<string> survey, vector<int> choices) {
    sizes = survey.size();
    getAns(survey,choices);
    
    answer = getRealAns();
    
    
    return answer;
}