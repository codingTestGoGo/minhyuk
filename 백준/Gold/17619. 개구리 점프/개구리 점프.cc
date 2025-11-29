#include <bits/stdc++.h>

using namespace std;


vector<int> val(100005,-1);
 

int find(int x){
    if(val[x] < 0 ){
        return x;
    }
    return val[x] = find(val[x]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return false;
    }

    if(val[a] > val[b]){
        swap(a,b);
    }

    if(val[a] == val[b]){
        val[a] --;
    }
    val[b] = a;
    return true;
}

// 
// 어떤 조직에 속하는지를 구해야함
// 그러기 위해서는 합칠 때 어떤 애에 속하는지를 어떻게 구하면 좋을까
// 그러면 그룹에 대한 정보를 수정해야하나? 이렇게 그룹을 맺는게 아니라 하나의 그룹이 어디에 존재하는지를 확인하는 식으로 계속 그룹을 늘리고 이걸 조회?
// 이건 유니온 파인드가 아니라 너무 배열로 문제가 길어지는 형태가 될 것임
// 이제 우두머리가 어디에 속하는지를 판단하는 문제이기 때문에 어떻게 엮이는지 어떻게 묶이는지를 아는게 가장 중요한 문제인데 흠
// 일단 빡센 상황은 그렇게 끝점을 연결하는 식으로 해도 되긴하지만 높이에 대한 제약이 걸릴 수 있다.
// 이러한 높이에 대한 제약을 해결하면서 문제를 풀 수 있는 방법이 어떤 것이 있을까?

vector<pair<pair<int,int>,int>> vecs;

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.first < b.first.first;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N , Q;

    cin >> N >> Q;

    int temp1 , temp2 ,temp3;
    for(int i =1;i<=N;i++){
        vector<int> vec;
        cin >> temp1 >> temp2 >> temp3;
        vec.push_back(temp1);
        vec.push_back(temp2);
        vec.push_back(temp3);
        vecs.push_back({{temp1,temp2},i});        
    }

    sort(vecs.begin(),vecs.end(),comp);

    pair<int,int> temp = vecs[0].first;
    int groupId = vecs[0].second;
    for(int i=1;i<vecs.size();i++){
        if(temp.second >= vecs[i].first.first){
           uni(groupId,vecs[i].second);
           temp.second = max(temp.second, vecs[i].first.second); 
        } else{
            groupId = vecs[i].second;
            temp.first = vecs[i].first.first;
            temp.second = vecs[i].first.second;
        }
    }

for(int i =0; i< Q;i++){
    cin >> temp1 >> temp2;
    if(find(temp1)==find(temp2)){
        cout << 1 << "\n";
    }else{
        cout << 0 <<"\n";
    }
}


}