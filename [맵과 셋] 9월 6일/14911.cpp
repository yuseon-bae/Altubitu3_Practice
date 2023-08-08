#include<iostream>
#include<vector>
#include<algorithm>
#include <utility>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int num;

	//첫째 줄에서 정수 입력받기
	while (cin >> num) {
		v.push_back(num);
	}
	int sum = v.back();
	v.pop_back();

	sort(v.begin(), v.end());
	//key가 <int, int>인 pair이며 value는 boolean인 맵 선언
	map<pair<int, int>, bool> visited;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			//중복 제거
			if (v[i] + v[j] == sum && !visited.count({ v[i],v[j] })) {
				cout << v[i] << " " << v[j] << "\n";
				visited[{v[i], v[j]}] = true;
				cnt++;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}