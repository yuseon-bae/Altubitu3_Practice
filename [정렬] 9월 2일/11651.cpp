#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> cor;

//비교함수
bool compare(const cor& a, const cor& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}

int main() {
	int n; //입력받을 좌표의 개수

	cin >> n;
	vector<cor> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), compare);
	//출력
	for (int i = 0; i < n; i++) {
		cout << arr[i].first <<" " << arr[i].second << "\n";
	}
}
