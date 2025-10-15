#include<bits/stdc++.h>


using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    // 가능한 스킬트리의 개수를 리턴하라고 하는거면 흠 백트랙킹으로 모든 경우의 수를 구하라는것?

    for(auto it : skill_trees){
        queue<char> que;
        vector<char> vec;
        int tempS;
        bool isT = 1;

        for(int i=0;i<skill.size();i++){
            // cout << "hw " << skill[i] << "\n";
            que.push(skill[i]);
            vec.push_back(skill[i]);
        }
        tempS = que.size();
        sort(vec.begin(),vec.end());

        for(char ii : it){
            // cout << "here "<< ii << "\n";
            if(binary_search(vec.begin(),vec.end(),ii)){
                // cout << ii << "\n";
                if(que.front() != ii){
                    isT = 0;
                    break;
                }else if(que.front() == ii){
                    que.pop();
                }
            }
            if(que.empty()){
                break;
            }
            
        }
        if(tempS >= que.size() && isT){
            answer ++;
        }
        
    }
    
    return answer;
}