#include<bits/stdc++.h>

using namespace std;

// 소수의 배열
vector<long long int> arr;


// 에라토스 테네스의 체 구분


void getSo(){
    // 10만까지를 구함
    vector<bool> arr2(100000,true);
    for(long long int i =2; i * i <= 100000;i++){
        if(arr2[i]){
            for(long long int k = i*i; k <= 100000; k +=i){
                    // 소수가 아닌 애
                    arr2[k] = false;
            }
        }
    }
    // 연속한 두 소수의 곱으로 이루어진 애들을 구해라 
    long long int temp =2;
    for(long long int i =3 ; i<=arr2.size();i++){
        if(arr2[i] == true){
            // cout << temp << "\n";
            arr.push_back(temp * i);
            temp = i;
        }
    }

    sort(arr.begin(),arr.end());

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 만까지의 소수를 배열에 구해놓고 그걸로 비교해서 꺼내기


    getSo();

    int N;
    cin >> N;

    for(auto it : arr){
        if(it > N){
            cout << it << "\n";
            break;
        }
    }


}