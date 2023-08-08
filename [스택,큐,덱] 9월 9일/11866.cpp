#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	queue <int> q;

	//입력
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i); //큐 삽입
	}
	//출력 형식을 맞추기 위해 <...>
	cout << "<";
	while (q.size() != 1) { //큐에 남아있는 원소가 한 개가 될 때까지
		for (int i = 1; i < k; i++) {
			//k번째 순서가 되기전에 앞에 있던 숫자들을 빼서 다시 뒤에 집어넣음
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		//출력
		cout << q.front() << ", ";
		//k번째 숫자를 출력 후 제거
		q.pop();
	}
	//마지막으로 큐 안에 남은 원소를 출력
	cout << q.front() << ">\n";
	return 0;
}