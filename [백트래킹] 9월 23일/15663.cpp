//백트래킹 N과 M (9)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int SIZE = 8;

//재귀함수 사용 시, 함수를 계속 호출할 때 매개변수도 생성되므로 전역변수로 선언하는 것이 더 효율적
int n, m;
vector<int> num(SIZE);
vector<int> path(SIZE);
vector<bool> check(SIZE + 1);

void backtracking(int cnt){ //cnt는 수열의 인덱스
    //종료조건
    if(cnt == m){
        //출력
        for(int i=0; i<m; i++){
            cout << path[i] <<' ';
        }
        cout << '\n';
        return;
    }
    int pre_num  = 0; //이전에 선택한 값
    for(int i=0; i<n; i++){ //i가 고르려는 수
        //현재 수열에 해당 수가 없는 경우 && 이전에 탐색한 값이 아닌 경우
        if (!check[i] && pre_num != num[i]) { 
            pre_num = num[i]; //이전에 선택한 값 저장
            path[cnt] = num[i]; //수 사용
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            //다시 돌아왔을 때
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}


int main(){
    //입력
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    //입력받은 수열 정렬
    sort(num.begin(), num.begin() + n);
    //sort(num.begin(), num.end())가 일반적이나 num벡터를 전역변수로 생성할 때 0으로 이루어진 크기가 8인 배열로 초기화했으므로 입력받은 수열들을 정렬해주기 위해서는 num.end()가 아니라 num.begin() + n

    //연산&출력
    backtracking(0);
    //보통 출력은 메인에서 해주는 것이 효율적
    //그러나 이 문제는 모든 수열을 재귀함수 호출시 출력하므로 연산과 동시에 출력하는 것이 효율적 
    return 0;
}