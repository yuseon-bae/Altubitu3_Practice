#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//비밀번호를 반환하는 함수
string PrintKey(stack<int>& st, stack<int>& temp) {
	string password;
	//화살표 입력시 temp 스택에 저장시킨 문자들을 다시 모두 st스택에 넣음 
	while (!temp.empty()) {
		st.push(temp.top());
		temp.pop();
	}
	while (!st.empty()) {
		password += st.top();
		st.pop();
	}
	//스택은 LIFO구조이므로 reverse함수를 이용해 거꾸로 출력
	reverse(password.begin(), password.end());
	return password;
}

string KeyLogger() {
	string text;
	//결과를 저장하는 st 스택과 화살표 입력할 때 사용하는 temp 스택
	stack <int> st, temp;
	//문자열 입력
	cin >> text;
	for (int i = 0; i < text.size(); i++) {
		//왼쪽 화살표(<) 입력시 
		if (text[i] == '<') {
			if (st.empty()) continue;
			else {
				//커서의 위치를 왼쪽으로 1만큼 이동 -> 일단 st스택의 top을 temp스택에 저장하고 pop
				temp.push(st.top());
				st.pop();
			}
		}
		//오른쪽 화살표(>) 입력시 
		else if (text[i] == '>') {
			if (temp.empty()) continue;
			else {
				//커서의 위치를 오른쪽으로 1만큼 이동 -> temp 스택에 저장되어 있던 문자를 다시 st스택으로 빼옴
				st.push(temp.top());
				temp.pop();
			}
		}
		//백스페이스(-) 입력시 문자 하나 지움
		else if (text[i] == '-') {
			if (st.empty()) continue;
			else st.pop();
		}
		//알파벳 대문자, 소문자, 숫자 입력 시 st스택에 push
		else
			st.push(text[i]);
	}
	return PrintKey(st, temp);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	//입력
	cin >> n;

	while (n--) {
		//연산 & 출력
		cout << KeyLogger() << '\n';
	}
	return 0;
}