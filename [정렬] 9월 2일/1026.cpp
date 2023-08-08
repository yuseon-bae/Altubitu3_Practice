#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	//입력받을 배열 벡터로 선언
	vector <int> a;
	vector <int> b;
        //a배열 입력
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	//b배열 입력
	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push_back(num);
	}
	//a배열은 오름차순 정렬, b배열은 내림차순 정렬
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
	int sum = 0;
	//배열을 정렬 한 후 곱해서 최솟값 구하기
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	//출력
	cout << sum;
	return 0;
}
