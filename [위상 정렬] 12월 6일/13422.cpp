#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase, n, m, k;
    cin >> testcase;

    while(testcase--) { // 테스트 케이스 입력받은 만큼 반복문 수행
        cin >> n >> m >> k;

        vector<int> money(n, 0);

        for(int i = 0; i < n; i++) { // 돈의 양 입력
            cin >> money[i];
        }
        
        int cnt = 0, total_money = 0;

        for(int i = 0; i < m; i++) {
            total_money += money[i];
        }
        
        if(total_money < k) { 
            cnt++;
        }
        
        //n != m인 경우
        if(n != m) {
            for(int i = 0; i < n-1; i++) { 
                total_money -= money[i]; //왼쪽 집 도둑질 실패
                //오른쪽 집 도둑질
                if(i+m >= n){
                    total_money += money[((i+m)-n)];
                } else{
                    total_money += money[i+m];
                }
                //자동 방범장치에 걸리지 않는 경우
                if(total_money < k) { 
                cnt++;
                }       
            }  
        }

        //출력
        cout << cnt << '\n';
    }
    return 0;
}

//참고 사이트 : https://katfun.tistory.com/10