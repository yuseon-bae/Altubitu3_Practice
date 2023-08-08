#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//입력
	int n;
	cin >> n;
	vector <int> arr(n);
	deque <int> dq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cardnum = 1;  //주어진 원소의 시작을 1로 설정

	//최종 상태와 기술 사용 순서를 가지고 처음 상태를 알아내야 함
	//따라서 주어진 입력과 반대로 거꾸로 순서를 따라가야 함
	for (int i = n-1; i >= 0; i--) {
		//주어진 입력이 1인 경우 원소를 맨 뒤에 넣어줌
		if (arr[i] == 1) {
			dq.push_back(cardnum);
		}
		//주어진 입력이 2인 경우 맨 뒤에서 두 번째에 원소를 넣어줌 
		else if (arr[i] == 2) {
			int tmp = dq.back(); //맨 뒤에 있던 원소를 tmp에 저장한 후
			dq.pop_back(); //맨 뒤 원소를 빼고
			dq.push_back(cardnum); //현재 넣어야 하는 수 뒤에 저장
			dq.push_back(tmp); //빼낸 원소를 다시 맨 뒤에 저장
		}
		//주어진 입력이 3인 경우 맨 앞에 원소를 넣어줌
		else if (arr[i] == 3) {
			dq.push_front(cardnum);
		}
		cardnum++; //연산이 한번씩 수행되고 난 다음 카드 숫자도 하나씩 증가
	}
	//출력
	for (int i = n - 1; i >= 0; i--) {
		cout << dq[i] << ' ';
	}
	return 0;
}