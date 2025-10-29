#include<bits/stdc++.h>

using namespace std;

int realSt, realEn;
vector<vector<pair<int,int>>> vec(810); 
int getAns(int st, int en){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    que.push({0,st});
    vector<int> arr(810,3000000);
    arr[st] = 0;

    while(!que.empty()){
        pair<int,int> temp = que.top();
        que.pop();

        if(temp.first != arr[temp.second]){
            continue;
        }

        for(auto it : vec[temp.second]){
            if(it.first + arr[temp.second] < arr[it.second]){
                int temper = it.first + arr[temp.second];
                arr[it.second] = temper;
                que.push({temper,it.second});
            }
        }        
    }
    if(arr[en] ==3000000 ){
        return -1;
    }
    return arr[en];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , E;
    cin >> N >> E;

    int a,b,c;
    for(int i =0 ; i <E;i++){
        cin >> a >> b >> c;
        vec[a].push_back({c,b});
        vec[b].push_back({c,a});
    } // 인접리스트 생성
    cin >> realSt >> realEn;
    int answer = -1;
    
    int temp = getAns(1,realSt);
    int temp2 = getAns(realSt,realEn);
    int temp3 = getAns(realEn,N);
    int temp4 = getAns(1,realEn);
    int temp5 = getAns(realSt,N);
    int temp6 = getAns(realEn,realSt);

    // cout << min(temp+temp2+temp3, temp4+temp5+temp6) << "\n";
    // cout << temp + temp2 + temp3 << "\n";
    // int temp2 = getAns(en,st);
    int temper = temp+temp2+temp3;
    if(temp == -1 || temp2 == -1 || temp3 == -1){
        temper = -1;
    }
    int temper2 = temp4+temp5+temp6;
    if(temp4 == -1 || temp5 == -1 || temp6 == -1){
        temper2 = -1;
    }

    // 하나라도 -1이 있으면 -1
    
    if(temper != temper2 && temper == -1 ){
        cout << temper2 << "\n";
    }else if(temper2 == -1){
        cout << temper << "\n";
    }else{
        cout << min(temper,temper2) << "\n";
    }

    //1에서 N까지의 이동인데 반드시 v1과 v2 를 이동해야하는것이다.


}