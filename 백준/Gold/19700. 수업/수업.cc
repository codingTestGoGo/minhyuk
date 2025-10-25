#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> T , pair<int,int> S){
    if(T.first > S.first){
        return true;
    }else if(T.first < S.first){
        return false;
    }else{
        return T.second > S.second;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // vector<multiset<int>> vec;
    int H, K;
  
    vector<pair<int,int>> students;
    for(int i =0; i<N;i++){
        cin >> H >>K;
        students.push_back({H,K});
    }
    // multiset<int> temps;
    // vec.push_back(temps);
    sort(students.begin(),students.end(),compare);
    multiset<int> vec;
    // vec.push_back(0);
    for(auto it : students){
        bool isOk = false;
        if(vec.empty()){
            vec.insert(1);
            continue;
        }
        //Lowerbound보다 하나 작은거에 넣도록 하는거군
        
        auto temps = vec.lower_bound(it.second);
        if(temps == vec.begin()){
            //맨 처음인 1뿐인거잖아
            // 하나 짜리라는 뜻 그리고 더 넣을 것이 없음
            vec.insert(1);
        }else{
            temps --;
            //하나 뺀 애가 딱 알맞는 애
            vec.erase(temps);
            vec.insert(*temps + 1); 
        }
    }

    cout << vec.size() << "\n";

}