#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Calc(vector<string> &number, vector<int> &strike, vector<int> &ball){
    int result = 0;
    //모든 경우를 다 탐색
    for(int i= 123 ; i<= 987 ; i++){
        string temp =  to_string(i);
         //숫자가 겹치는 경우
         if(temp[0]==temp[1] || temp[1] == temp[2] || temp[0] == temp[2]){
            continue;
         }
         //숫자 0을 포함한 경우
          if(temp[0]=='0'||temp[1]=='0'||temp[2]=='0'){
            continue;
          }

      bool check = true;
      
      for(int i=0; i<number.size(); i++){
        string num = number[i];
        int s=0, b=0;

        for(int j=0; j<num.size(); j++){
            if(num[j]==temp[j]){    //스트라이크 수 확인
                s++;     
            }
            if(num[j]==temp[(j+1)%3]|| num[j]==temp[(j+2)%3]){ //볼 수 확인
                b++;
            }
        }
       //단 하나라도 맞지 않으면 false
        if(s!=strike[i] || b!=ball[i]){
            check = false;
        }
    }
      if(check)
        result++;      
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //입력
    int n;
    cin >> n;
    //숫자와 스트라이크, 볼 개수 입력
    vector<string> number(n);
    vector<int> strike(n,0), ball(n,0);
    for(int i=0; i<n; i++){
        cin >> number[i] >> strike[i] >> ball[i];
    }
    //연산&출력
    cout << Calc(number,strike,ball);
    return 0;
}