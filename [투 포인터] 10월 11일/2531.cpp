#include <iostream>
#include <vector>

using namespace std;

//먹을 수 있는 초밥의 최대 가짓수를 반환하는 함수
int eatSushi(int n, int d, int k, int c, vector<int> &belt){
    vector <int> check(d+1, 0);
    int cnt = 0, ans = 0;
    int left = 0, right = k-1;

    //윈도우 초기화
    for(int i=0; i<k; i++){
        check[belt[i]]++;
        if(check[belt[i]] == 1){
            cnt++;
        }
    }

    //쿠폰으로 먹은 초밥
    check[c]++;
    if(check[c] == 1){
        cnt++;
    }

    while(left < n){
        ans = max(ans, cnt);

        //이전에 먹은 초밥은 빼주고
        if(--check[belt[left++]] == 0){
            cnt--;
        }
        
        right = (right+1) % n;
        //새로운 초밥은 추가
        if(++check[belt[right]] == 1){
            cnt++;
        }
    }

    return ans;
}

int main(){
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;

    vector <int> belt(n,0);
    for(int i=0; i<n; i++){
        cin >> belt[i];
    }

    //연산 & 출력
    cout << eatSushi(n,d,k,c,belt);
    return 0;
}

//참고한 사이트: https://imnotabear.tistory.com/472