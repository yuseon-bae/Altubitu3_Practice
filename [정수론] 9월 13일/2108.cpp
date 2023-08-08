#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//산술평균 구하고 반환하는 함수
int arithmetic_mean(int n, vector<int> &num) {
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += num[i];
	}
	return round(ans / n);
}
//중앙값 구하고 반환하는 함수
int medain(int n, vector<int>& num) {
	return num[(n - 1) / 2];
}
//최빈값 구하는 함수
int mode(int n, vector<int>& num) {
	int result;
	int count = 0;
	int cnt2[8001] = { 0 };
	for (int i = 0; i < n; i++) {
		cnt2[num[i] + 4000]++;
	}
	int max_mode = *max_element(cnt2, cnt2 + 8001);
	for (int i = 0; i < 8001; i++) {
		if (cnt2[i] == max_mode) {
			count++;
			result = i - 4000;
		}
		if (count == 2) {
			break;
		}
	}
	return result;
}
//범위 반환하는 함수
int range(int n, vector<int>& num) {
	return num[n - 1] - num[0];
}
int mian() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	cout << arithmetic_mean(n, num) << '\n';
	cout << medain(n, num) << '\n';
	cout << mode(n, num) << '\n';
	cout << range(n, num) << '\n';
	return 0;

}