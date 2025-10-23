#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    vector<int> vec;
    int temp;
    for(int i =0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end()); // 일단 정렬 시킴
    // 가장 큰 값 - 가장 작은 값으로 맵핑하면 됨
    int ans =0 ;
    do{
        int temper = 0;
        for(int i =1;i<N;i++){
            temper += abs(vec[i-1] - vec[i]);
        }

        ans = max(temper,ans);
    }while (next_permutation(vec.begin(),vec.end())) ;

    cout << ans << "\n";
}
