#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//받을 수 있는 팁의 합계를 계산
long sum(int n, vector <int>& line) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		if (line[i] - i < 0) { //음수가 되면 팁을 받을 수 없기 때문에
			break;
		}
		sum += line[i] - i;
	}
	return sum;
}
int main() {
	int n; //첫째 줄에 서 있는 사람의 수
	cin >> n;
	vector <int> line;
	line.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> line[i];
	}
	sort(line.begin(), line.end(), greater<>());
	cout << sum(n, line);
	return 0;
}
