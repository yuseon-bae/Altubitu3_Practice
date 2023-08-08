#include<iostream>
#include <algorithm>

using namespace std;

char board[51][51];
int ans, n;

void countCandy(){
     //행 계산
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j = 0; j < n; j++){
            if (board[i][j] == board[i][j - 1]){
                count++;
            } else{
                ans = max(ans, count);
                count = 1;
            }
            ans = max(ans, count);
        }
    }
    //열 계산
    for(int j=0; j<n; j++){
        int count = 1;
        for(int i = 0; i < n; i++){
            if (board[i][j] == board[i+1][j]){
                count++;
            } else{
                ans = max(ans, count);
                count = 1;
            }
            ans = max(ans, count);
        }
    }
}

void candyNum(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //양 옆을 바꾸고 제일 길게 먹을 수 있는 사탕의 길이 구하기
            swap(board[i][j], board[i][j+1]);
            countCandy();
            swap(board[i][j], board[i][j+1]);

            //위 아래를 바꾸고 제일 길게 먹을 수 있는 사탕의 길이 구하기
            swap(board[i][j], board[i+1][j]);
            countCandy();
            swap(board[i][j], board[i+1][j]);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    //입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }   
    //연산
    candyNum();
    //출력
    cout << ans;
    return 0;
}