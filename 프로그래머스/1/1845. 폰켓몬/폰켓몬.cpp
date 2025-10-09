#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    // 1만개이기 때문에 백트랙킹은 아니고 총 종류가 몇가지인지 보고 그게 4개보다 적으면 그걸 쓰면 되고 아니면 반토막하면 되는거 아닌가? 만약에 
    // 어차피 짝수라서 맞네
    map<int,int> maps;

    for(auto it : nums){
        maps.insert({it,0});
    }
    
    if(maps.size() >= nums.size()/2){
        answer = nums.size()/2;
    }else{
        answer = maps.size();
    }
    
    return answer;
}