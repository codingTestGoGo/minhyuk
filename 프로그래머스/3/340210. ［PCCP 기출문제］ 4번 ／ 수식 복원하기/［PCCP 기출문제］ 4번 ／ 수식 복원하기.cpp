#include<bits/stdc++.h>


using namespace std;

vector<int> getAns(int num){
    vector<int> temp;
    if(num >= 10){
        temp.push_back(num/10);
    }
    temp.push_back(num%10);
    return temp;
}

string getAnsFinal(int num, int gin){

    if (num == 0) {
            return "0";
        }

    string result = "";

    while (num > 0) {
        int remainder = num % gin;
        char digit_char = '0' + remainder;
        result += digit_char;
        num /= gin;
    }

    reverse(result.begin(), result.end());
    // cout << result << ":" << gin << "\n";
    return result;
}

int tempMachine(int temp,int an){
    int answer =0;
    if(temp>=100){
        answer += (temp/100)*an*an;
        temp %=100;
        answer += (temp/10)*an;
        temp %= 10;
        answer += temp;
    }else if(temp < 100 && temp >=10){
        answer += (temp/10)*an;
        temp %= 10;
        answer += temp;
    }else{
        answer += temp;
    }
    // cout << answer << "\n";
    return answer;
}



vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    // 일단 2-9 진법까지만 가능하고

    int maxs = 1; // 하한
    
    for(auto it : expressions){
        for(auto tt : it){
            // 각각의 숫자가 얼마나 더 큰지 판단
            int nums = tt-'0';
            if( nums<9 && nums >=0){
                maxs = max(maxs,nums);
            }
        }
    }
    // 우선 하한을 구해서 적어도 해당 진법보다는 크다고 판단하여 생각
    queue<int> que;
    vector<int> queVec;
    for(int i=maxs+1;i<=9;i++){
        que.push(i);
        queVec.push_back(i);
        // cout << "first" << i << "\n";
    }
    // 가능한 후보지들 넣어둠
    
    vector<string> lasts; 
    
    for(auto it : expressions){
        // 사칙연산을 기준으로 판단하기?
        int idx=0;
        string oper;
        if(it.find("+") != -1){
            idx = it.find("+");
            oper = "+";
        }else if(it.find("-") != -1){
            idx = it.find("-");
            oper = "-";
        }
        
        int firstNum = stoi(it.substr(0,idx-1));
        
        int idx2 = 0;
        idx2 = it.find("=");
        int secondNum = stoi(it.substr(idx+1,idx2-idx-1));
        
        string third = it.substr(idx2+2);
        
        if(third == "X"){
            // X 인 경우
            // 되는 애들 다 계산하고 마지막에 처리해얗마
            lasts.push_back(it);
        }else{
            // X가 아닌 경우
            // 연산을 진행해서 맞는 값인지 확인하면 됨
            int sizes = que.size();
            for(int pp = 0;pp<sizes;pp++){
                // 해당 값을 넣어서 조건대로 되는지 확인하면 됨
                int an = que.front();
                que.pop();
                // cout << oper << "\n";
                if(oper == "+"){
                    vector<int> vec = getAns(firstNum);
                    vector<int> vec2 = getAns(secondNum);
                    
                    int temp1 =0;
                    int temp2 =0;
                    if(vec.size()==2){
                        temp1 += vec[0]*an;
                        temp1 += vec[1];
                    }else{
                        temp1+=vec[0];
                    }
                    if(vec2.size()==2){
                        temp2 += vec2[0]*an;
                        temp2 += vec2[1];
                    }else{
                        temp2 +=vec2[0];
                    }
                    // cout << third << "\n";
                    int thirdNum = stoi(third);
                    thirdNum = tempMachine(thirdNum,an);
                    // cout << "temp" << temp1 << " : " << temp2 << " : " << thirdNum << "\n";
                    if((temp1 + temp2) == thirdNum){
                        que.push(an);
                    }
                    
                }
                else{
                    vector<int> vec = getAns(firstNum);
                    vector<int> vec2 = getAns(secondNum);
                    
                    int temp1 =0;
                    int temp2 =0;
                    if(vec.size()==2){
                        temp1 += vec[0]*an;
                        temp1 += vec[1];
                    }else{
                        temp1+=vec[0];
                    }
                    if(vec2.size()==2){
                        temp2 += vec2[0]*an;
                        temp2 += vec2[1];
                    }else{
                        temp2 +=vec2[0];
                    }
                    
                    int thirdNum = stoi(third);
                    thirdNum = tempMachine(thirdNum,an);
                    if((temp1 - temp2) == thirdNum){
                        que.push(an);
                    }
                }
            }
        }
    }
    
    
    for(auto it : lasts){
        int idx=0;
        string oper;
        if(it.find("+") != -1){
            idx = it.find("+");
            oper = "+";
        }else if(it.find("-") != -1){
            idx = it.find("-");
            oper = "-";
        }
        
        int firstNum = stoi(it.substr(0,idx-1));
        
        int idx2 = 0;
        idx2 = it.find("=");
        int secondNum = stoi(it.substr(idx+1,idx2-idx-1));
        
        string third = it.substr(idx2+2);
        set<string> answerSet;
        
        for(int pp = 0 ;pp<que.size();pp++){
                // 해당 값을 넣어서 조건대로 되는지 확인하면 됨
                int an = que.front();
                // cout << an <<"\n";
                que.pop();
                if(oper == "+"){
                    vector<int> vec = getAns(firstNum);
                    vector<int> vec2 = getAns(secondNum);
                    
                    int temp1 =0;
                    int temp2 =0;
                    if(vec.size()==2){
                        temp1 += vec[0]*an;
                        temp1 += vec[1];
                    }else{
                        temp1+=vec[0];
                    }
                    if(vec2.size()==2){
                        temp2 += vec2[0]*an;
                        temp2 += vec2[1];
                    }else{
                        temp2 +=vec2[0];
                    }
                    // cout << "temp" << temp1 << " " << temp2 << "\n";
                    answerSet.insert(getAnsFinal(temp1+temp2,an));
                    
                }else{
                    vector<int> vec = getAns(firstNum);
                    vector<int> vec2 = getAns(secondNum);
                    
                    int temp1 =0;
                    int temp2 =0;
                    if(vec.size()==2){
                        temp1 += vec[0]*an;
                        temp1 += vec[1];
                    }else{
                        temp1+=vec[0];
                    }
                    if(vec2.size()==2){
                        temp2 += vec2[0]*an;
                        temp2 += vec2[1];
                    }else{
                        temp2 +=vec2[0];
                    }   
                    
                    // cout << "temp" << temp1 << " " << temp2 << "\n";
                    answerSet.insert(getAnsFinal(temp1-temp2,an));
                }
                que.push(an);
        }
        string temper = it.substr(0,idx2+2);
        // cout << temper << "\n";
        for(auto ss :answerSet){
             // cout << ss <<"\n";
        }
        if(answerSet.size() == 1){
            //공백까지 연결
            string ansNumber;
            for(auto ss :answerSet){
                ansNumber = ss;
            }
            temper += ansNumber;
        }else{
         temper += "?";
        }
        answer.push_back(temper);
    }
    
    
    return answer;
}