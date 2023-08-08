#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, one = 0, ans = 0;

    //입력
    cin >> n;
    //pos는 양수 저장, neg는 음수 저장
    vector<int> pos, neg;
    for(int i=0; i<n; i++) {
        cin >> x;
        if (x > 1) { //양수인 경우
            pos.push_back(x);
        } else if (x < 1) { //음수인 경우
            neg.push_back(x);
        } else { //x==1인 경우
            one++; //1 count
        }
    }

    //절댓값이 큰 순으로 정렬
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    int pSize = pos.size(), nSize = neg.size();

    //양수
     if(pSize % 2){
        pos.push_back(1);
    }
    for(int i=0; i<pSize; i+=2){
        ans += pos[i] * pos[i+1];
    }

    //음수
    for(int i=0; i<nSize-1; i+=2){
        ans += neg[i] * neg[i+1];
    }
    if(nSize % 2){
        ans += neg[nSize - 1];
    }

    //출력
    cout << ans + one;
    return 0;

    //참고 사이트: https://suhwanc.tistory.com/18
}