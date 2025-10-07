#include<iostream>
using namespace std;
int main(){
    int a,b,count;
    cin >> count;
    int num[count];
    for(int i = 0;i<count;i++){
    cin >> a >> b;
    num[i]= a+b; 
    }
    for(int i=0;i<count;i++){
        cout << num[i]<<endl;
    }
}