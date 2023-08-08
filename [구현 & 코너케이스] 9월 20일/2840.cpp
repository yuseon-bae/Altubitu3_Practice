#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//룰렛의 칸을 '?'로 초기화 한 벡터 생성
	vector<char> roulette(25, '?');

	int n, k;
	//첫번째 입력 (바퀴의 칸의 수와 바퀴를 돌리는 횟수)
	cin >> n >> k;

	int index = 0;

	for (int i = 0; i < k; i++) {
		int count;
		char temp;
		//두번째 입력(바퀴를 회전시켰을 때 화살표가 가리키는 글자가 몇 번 바뀌었는지, 회전을 멈추었을 때 가리키던 글자)
		cin >> count >> temp;

		count %= n;
		if (index - count < 0) {
			index = index - count + n;
		}
		else index -= count;

		if (roulette[index] != '?' && roulette[index] != temp) {
			cout << "!";
			return 0;
		}
		else {
			roulette[index] = temp;
		}
	}

	//중복체크
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (roulette[i] != '?' && roulette[i] == roulette[j]) {
				cout << "!";
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << roulette[(index + i) % n];
	}


	return 0;
}