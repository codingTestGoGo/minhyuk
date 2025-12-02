#include<bits/stdc++.h>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec;

    int temp;

    for(int i=0;i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }



    int st= 0;
    int en= 0;

    long long int answer = 0;
    // n^2의 형태라서 시간초과가 걸림
    set<int> sets;
    while(st<=en){
        while(en < N){
            if(sets.find(vec[en])==sets.end()){
                sets.insert(vec[en]);
            }else{
                break;
            }
            en ++;
            // if(sets.size() >=2){
            //     answer ++;
            // }
        }
        sets.erase(vec[st]);
        
        answer += (en-st);
        // if(en == N){
        //     //끝에 도달해버린 경우
        //     answer += (en-st);
        // }else{
        //     answer ++;
        // }

        st++;
    }
    // 1개짜리는 따로 더해줌

    cout << answer << "\n";
}