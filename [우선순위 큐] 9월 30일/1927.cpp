#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    //입력
    cin >> n;
    //오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;

    while (n--) {
        cin >> x;
        //입력값이 0일때
        if (x == 0) {
            if (pq.empty()) {  //배열이 비어있다면
                cout << "0\n"; //0 출력
            }
            else {   //배열이 비어있지 않다면
                cout << pq.top() << '\n'; // 배열에서 가장 작은 값을 출력 후
                pq.pop(); //그 값 배열에서 제외
            }
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}