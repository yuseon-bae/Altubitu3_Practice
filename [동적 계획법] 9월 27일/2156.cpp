#include <iostream>
#include <vector>

using namespace std;

// 최대로 마실 수 있는 포도주의 양을 반환하는 함수
int maxWine(int n, vector<int> &wine) { 
    //마실 수 있는 최대 포도주 양
    vector<int> vec (n+1);

    //3잔을 연속해서 마실 수 없다
    vec[1] = wine[1];
    vec[2] = wine[1] + wine[2];
    
    //  N번째 잔을 마실 때 최대양을 만들 수 있는 방법
    // 1. N-3번째 잔 까지의 최댓값 + N-1번째 잔 + N번째 잔
    // 2. N-2번째 잔 까지의 최댓값 + N번째 잔
    // 3. N-1번째 잔 까지의 최댓값
    //위 아이디어의 출처: https://luv-n-interest.tistory.com/920
    
    for(int i = 3; i <= n; i++) {
        vec[i] = max(max(wine[i] + wine[i-1] + vec[i-3], wine[i] + vec[i-2]), vec[i-1]);
    }
    return vec[n];
}

int main() {
    int n;
    //입력
    cin >> n;

   //마실 수 있는 포도주 양을 벡터로 선언하고 입력받기 
    vector<int> wine(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    //연산& 출력
    cout << maxWine(n, wine);
    return 0;
}
