#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
     
    int n, input;
    //입력
    cin >> n;
     
    //오름차순 우선순위큐
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                cin >> input;   //배열 입력

                if(n > pq.size()){ //크기가 n보다 작은 경우
                    pq.push(input);
                }

                if (input > pq.top()) { //top보다 입력값이 큰 경우
                    pq.pop();
                    pq.push(input);
                }
                    
        }
    }
    //출력
    cout << pq.top() << '\n'; 
    return 0;
}