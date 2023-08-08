#include <iostream>
#include <string>
using namespace std;

int main() {
	//수가 너무 크기 때문에 문자열로 입력받기 위한 문자열 변수 a,b
	// 더한 결과값을 저장하기 위한 컨테이너 res
	string a, b, res;
	cin >> a >> b;
	int digit = 0; //덧셈할 때 올림을 관리할 변수
	int aSize = a.length(); //첫번째 입력받은 수의 자릿수
	int bSize = b.length(); //두번째 입력받은 수의 자릿수
	while (aSize > 0 || bSize > 0) {
		int num1 = 0; //첫번째 수의 자릿수 중 하나 (일의 자리부터)
		if (aSize > 0) {  //일의 자리부터 덧셈을 하기 위해 입력받은 문자열 a의 끝에서 부터 숫자로 변환
			num1 = a[--aSize] - '0'; //문자 0을 빼줌으로 문자를 숫자로 변환
		}
		int num2 = 0; //두번째 수의 자릿수 중 하나(일의 자리부터)
		if (bSize > 0) {
			num2 = b[--bSize] - '0';
		}
		int sum = num1 + num2 + digit;
		digit = sum / 10; //올림수 변경
		sum %= 10; //한 자릿수 덧셈 값
		char cur = sum + '0'; //숫자를 다시 문자로 변환
		res += cur; //더한 값 저장
	}
	if (digit > 0) { //제일 높은 자릿수까지 덧셈을 마쳤을 때 올림수가 남아있다면
		res += digit + '0'; //자릿수를 하나 더해줌
	}
	for(int i = (int)res.length() - 1; i >= 0; --i) {
		cout <<  res[i];
	}
	return 0;
}