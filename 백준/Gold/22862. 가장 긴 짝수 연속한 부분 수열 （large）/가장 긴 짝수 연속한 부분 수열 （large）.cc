#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;

    vector<int> arr;

    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        arr.push_back(temp);
    }

    int st=0, en=0;
    int answer = 0;


    set<int> sets;
    int oddC = 0;
    queue<int> que;
    int counter = 0;
    // 홀수를 어디에 저장해두면 될까?
    while(st <= en){
        while(en < N){
            if(oddC > K){
                break;
            }
            if(arr[en] % 2 == 1){
                //홀수인 경우
                oddC++;
            }
            que.push(arr[en]);
            if(oddC <= K){
                int temp2 = que.size();
                answer = max(answer,temp2-oddC);
            }
            en++;
            // counter++;  
        }
        if(que.front() % 2 ==1){
            oddC--;
        }
        // counter --;
        if(!que.empty()){
            que.pop();
        }
        st++;
    }

    cout << answer << "\n";

}