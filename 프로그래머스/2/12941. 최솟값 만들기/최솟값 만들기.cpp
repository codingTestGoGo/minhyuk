#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // 제일 작은 애를 뽑아서 구할 수 있도록 하는 것이다.
    // 일단 sort를 시키고 나서 구하기 시작하는 것이다.
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    
    for(int i =0;i<A.size();i++){
        answer += (A[i] * B[i]);
    }
    
    return answer;
}