#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, num;
	string order;
	//입력받는 수의 크기가 1<=x<=20이므로 배열의 크기를 21로 지정
	bool arr[21];
	//수행해야 하는 연산의 수 입력
	cin >> m;
	while(m--){
		//수행해야 하는 연산 입력
		cin >> order;
		if (order == "add") {
			cin >> num;
			arr[num] = true;
		}
		if (order == "remove") {
			cin >> num;
			arr[num] = false;
		}
		if (order == "check") {
			cin >> num;
			if (arr[num]) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		if (order == "toggle") {
			cin >> num;
			if (arr[num]) {
				arr[num] = false;
			}
			else {
				arr[num] = true;
			}
		}
		if (order == "all") {
			fill_n(arr, sizeof(arr), true);
		}
		if (order == "empty") {
			fill_n(arr, sizeof(arr), false);
		}
	}
	return 0;
}