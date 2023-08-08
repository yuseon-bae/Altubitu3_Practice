#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(const string& s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			sum += int(s[i]) - '0';
	}
	return sum;
}

bool cmp(const string& a, const string& b) {

	if (a.size() != b.size()) return a.size() < b.size();

	int asum = sum(a), bsum = sum(b);
	if (asum != bsum) return asum < bsum;

	return a < b;
}

int main() {
	int n; //입력받을 기타 개수
	cin >> n;
	vector <string> serial(n);
	
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(),serial.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << serial[i] << "\n";
	}

}