#include <iostream>
#include <algorithm>

using namespace std;

    //30의 배수 조건
    //1. 마지막 수가 0이어야 함 
    //2.각 자리수들을 더한값이 3의 배수이어야 함

string Calc(string &num){
    //마지막 수가 0이 아닌 경우 30의 배수가 아니므로
    if(num[num.size() - 1] != '0'){
        return "-1";     //"-1"반환
    }
  
    int sum = 0;
    //각 자리수들을 더한값 sum
    for(int i=0; i<num.size(); i++){
        sum+=num[i]-'0';
    }
    //각 자리수를 더한 값이 3의 배수인 경우
    if(sum % 3 == 0){  
        return num;
    }
    else return "-1";
  
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   //string으로 숫자 입력받기
    string num;
    cin >> num;
    
    //만들 수 있는 가장 큰 수를 만들기 위해 입력받은 숫자 역순으로 정렬
    sort(num.begin(), num.end(), greater<>());
    
    //연산 & 출력
    cout << Calc(num);
    return 0;

}