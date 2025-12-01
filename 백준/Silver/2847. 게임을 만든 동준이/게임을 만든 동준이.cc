#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N ;
    cin >> N;

    vector<int> vec;

    int temp;
    for(int i =0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    int answer = 0;
    for(int i=1;i<N;i++){
        for(int t=i; t>0;t--){
            if(vec[t-1] >= vec[t]){
                answer += (vec[t-1]-vec[t]+1);
                vec[t-1] = vec[t] -1;
            }
        }
    }

    // 재귀로 풀어야하는건가?
    // 이에 대한 처리를 뒤에 어떻게
    
    cout << answer << "\n";


}