#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> giveG; //준 선물
map<string,vector<string>> getG; //받은 선물
vector<string> realF;
int answer;
int sizeN;

int answerArr[52];
int giftJ[52][52];
int giftP[52];

int getIndex(string name){
    //인덱스를 리턴하는 함수
    return find(realF.begin(),realF.end(),name) - realF.begin();
}


void giveAndGet(vector<string> gifts){
    
    for(auto it : gifts){
        int index = it.find(" ");
        string first = it.substr(0,index);
        string second = it.substr(index+1,it.size()-1);
        // cout << first << " " << second << "\n";
        
        int firstI  =getIndex(first);
        int secondI = getIndex(second);
        giftJ[firstI][secondI]++;
        // cout << firstI << " " << secondI << "\n";
         // cout << giftJ[firstI][secondI] << "\n";
        // cout << getIndex(first) << "\n";
        // 2차원 배열에 값 집어넣음
        
//         if(giveG.find(first)!=giveG.end()){
//             giveG.second.push_back(second);
//         }else{
//             vector<string> newVec;
//             newVec.push_back(second);
//             giveG.insert({first,newVec});
//         }
        
//         if(getG.find(second)!=giveG.end()){
//             getG.second.push_back(first);
//         }else{
//             vector<string> newVec;
//             newVec.push_back(first);
//             getG.insert({second,newVec});
//         }
        
    }
    
    
}
void giftPoint(){
    for(auto it : realF){
        // cout << it << "\n";
        int index = getIndex(it);
        int temp = 0;
        // cout << "idx " << index << "\n";
        for(int i =0;i<sizeN;i++){
            // cout << giftJ[0][1] << "\n";
            temp += giftJ[index][i];

        }
        
        for(int i =0;i<sizeN;i++){
            temp -= giftJ[i][index];
        }
        giftP[index] = temp;
        // cout << giftP[index] << "\n";
    }
}


void getAnswer(){
    for(auto it : realF){
        int idx = getIndex(it);
        // cout <<"here " << idx  << " " << sizeN<< "\n";
        for(int i=idx+1;i<sizeN;i++){
    
            // if(i == idx) continue;
            if(giftJ[idx][i]!=0 || giftJ[i][idx]){
                // 주고받은 기록이 있는 경우
                  // cout <<"here " << idx  << " " << i<< "\n";
                if(giftJ[idx][i] > giftJ[i][idx]){
                        answerArr[idx]++;
                }else if(giftJ[idx][i] == giftJ[i][idx]){
                        if(giftP[idx] > giftP[i]){
                            answerArr[idx]++;
                        }else if(giftP[idx] < giftP[i]){
                            answerArr[i]++;
                        }
                }else{
                    answerArr[i]++;
                }
                
            }else{
                if(giftP[idx] > giftP[i]){
                    answerArr[idx]++;
                }else if(giftP[idx] < giftP[i]){
                    answerArr[i]++;
                }
            }
        }
        // cout << answerArr[idx] << "\n";
    }
    answer = *max_element(answerArr,answerArr+52);     
}


// 가장 선물을 많이 받을 친구의 선물의 개수가 정답 -> 어떻게 구성하면 될지
// 일단 유저 한 명씩 다 돌면서 처리를 해야겠네, 해당 유저가 어떻게 처리할지
// 일단 들어온 이름 -> 번호로 맵핑하는게 필요하긴 하겠네




int solution(vector<string> friends, vector<string> gifts) {
    realF = friends;
    sizeN = friends.size();
    
    giveAndGet(gifts);
    
    giftPoint();
    
    getAnswer();
    
    return answer;
}