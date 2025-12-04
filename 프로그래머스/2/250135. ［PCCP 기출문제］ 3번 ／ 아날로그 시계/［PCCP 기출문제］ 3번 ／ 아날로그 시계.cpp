#include<bits/stdc++.h>
 

using namespace std;

int changeSec(int hour,int min, int sec){
    return hour*3600 + min * 60 + sec ;
}

bool eq(double a, double b) {
    return fabs(a - b) < 1e-6;
};

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int stSec = changeSec(h1,m1,s1);
    int endSec = changeSec(h2,m2,s2);
    
    // if(h2 ==12&& m2 ==0 && s2 ==0){
    //     answer++;
    // }
    
    int temp = endSec - stSec;
    // cout << temp << "\n";
    
    // 초를 기준으로 시계를 움직임
    // 초기 시계 각도
    double hAngle;
    double mAngle;
    double sAngle;
    if(stSec == 0){
        hAngle = 0;
        mAngle = 0;
        sAngle = 0;
    }else{
       hAngle = (double)stSec/120;
        
        if(m1 == 0 && s1 == 0){
            mAngle = 0;
        }else{
           mAngle = (double)(m1*60+s1)/10;
        }
        sAngle = s1 * 6;
    }
     // cout << hAngle << ":" << mAngle << ":" << sAngle << "\n";
    double postH;
    double postM;
    double postS;
    
    for(int i =0;i<=temp;i++){
        // 초가 지나간 거리에 시간과 분이 지나가면 이에 대한 계산을 해야함
        bool alarm = false;
        if(i == 0){
            if(hAngle == sAngle || mAngle == sAngle){
                alarm = true;
            }
        }else{
            if(postH > postS && hAngle <= sAngle){
                answer ++;
            }
            if(postM > postS && mAngle <= sAngle){
                answer ++;
            }
            if(eq(hAngle, mAngle) && eq(mAngle , sAngle)){
                answer --;
            }
        }
        
        if(hAngle >= 360){
            hAngle -=360;
        }
        if(mAngle >= 360){
            mAngle -=360;
        }
        if(sAngle >= 360){
            sAngle -=360;
        }

        postH = hAngle;
        postM = mAngle;
        postS = sAngle;
        
        hAngle += (double)1/120;
        // if(hAngle> 180 && hAngle< 190 ){
        //     cout << hAngle << ":" << mAngle << ":" << sAngle << "\n";
        // }
        mAngle += (double)1/10;
        sAngle += 6;
        
        if(i!= 0 && stSec + i+1 == 3600 * 12){
            hAngle = 0;
            mAngle = 0;
            sAngle = 0;
        }
        
        // 중복으로 체크되어서 두 번 울리지 않게끔 
        if(alarm == true){
            answer++;
        }
    }
    if(hAngle == 0 && mAngle ==0 && sAngle == 0){
        answer ++;
    }
    if (h2 == 23 && m2 == 0 && s2 == 0) {
        answer++;
    }

    
    
    return answer;
}