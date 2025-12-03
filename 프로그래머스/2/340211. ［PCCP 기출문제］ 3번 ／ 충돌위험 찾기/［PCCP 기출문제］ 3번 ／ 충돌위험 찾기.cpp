#include<bits/stdc++.h>


using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<pair<int,int>>>vec;
    int biggests = 0;
    int count = 0;
    for(auto it : routes){
        vector<pair<int,int>> temp;
        int y = points[it[0]-1][0];
        int x = points[it[0]-1][1];
        temp.push_back({y,x});
        
        for(int t =1;t<it.size();t++){
            int nx = points[it[t]-1][1];
            int ny = points[it[t]-1][0];
            
            while(y != ny){
                if(y > ny){
                    y--;
                }else{
                    y++;
                }    
                temp.push_back({y,x});
            }
            
            while(x != nx){
                if(x > nx){
                    x--;
                }else{
                    x++;
                }    
                temp.push_back({y,x});
            }
            
        }
        int sizes = temp.size();
        biggests = max(biggests,sizes);
        vec.push_back(temp); // 모든 경로 저장
    }
    
    // 모든 점들의 이동경로의 길이가 같지 않다.
    vector<set<pair<int,int>>> arr(biggests+1);
    vector<set<pair<int,int>>> answerCheck(biggests+1);
    for(long long int i = 0;i<vec.size();i++){
        for(long long int t = 0;t<vec[i].size();t++){
        //         cout << i << "\n";
        //         cout << t << "\n";
        //         cout << vec[i][t].first << ":"  << vec[i][t].second << "\n";
        //         cout << "\n";   
            if(arr[t].find(vec[i][t]) == arr[t].end()){
                arr[t].insert(vec[i][t]);
            }else{
                // 다른 경로에서의 위험인 경우에는 더해줄 수 있음
                answerCheck[t].insert(vec[i][t]);
            }
        }
    }
    
    
    for(int i=0;i<biggests;i++){
        answer += answerCheck[i].size();   
    }
    
    
    return answer;
}