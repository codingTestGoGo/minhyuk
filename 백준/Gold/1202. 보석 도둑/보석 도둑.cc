#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multimap<int,int, greater<int>> jew; // 보석
    multiset<int> bags; ///가방
    long long int answer = 0;
    int N, K;
    cin >> N >> K;

    int tempM, tempV;
    for(int i =0;i<N;i++){
        cin >> tempM >> tempV; // 무게가 뒤에 값어치가 앞에 오도록 설정
        jew.insert({tempV,tempM});
    }

    for(int i =0; i<K;i++){
        cin >> tempM;
        bags.insert(tempM);
    }


    for(auto it : jew){
        if(bags.empty()){
            break;
        }
        auto temp = bags.lower_bound(it.second); // 무게가 가능한 제일 작은애 구함
        // 해당 위치를 알아냄
        if(temp == bags.end()){
            continue;
        }
        bags.erase(temp);
        answer += it.first;
    }

    cout << answer << "\n";


}