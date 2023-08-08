#include <iostream>
#include <stack>
#include <map>
using namespace std;
//괄호 쌍이 짝이 맞기 위해 몇 번의 연산이 필요한지 계산하는 함수
int isBalanced(string& s) {
	int res = 0;
	stack <char> st;
	map <char, char> m; //괄호 짝 저장
	m['}'] = '{';
	//입력받은 괄호의 개수만큼 연산진행
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '{':  //열린 괄호는 스택에 push
			st.push(s[i]);
			break;
		case '}':  //닫힌 괄호는
			if (st.empty() || st.top() != m[s[i]]) { //스택이 비어있거나 스택의 top이 열린 괄호가 아니면
				st.push(s[i]);  //스택에 push
			}
			else {  //스택의 top이 열린 괄호면 즉 괄호의 쌍이 맞으면 
				st.pop(); //스택에서 pop 해준다
			}
			break;
			st.pop();
			break;
		}
	}
	//스택이 비워질 때까지
	while (!st.empty()) {
		char t = st.top();
		st.pop();
		// 괄호의 형태가 같지 않다면 즉 }{ 이런 형태이므로 2개 모두 방향을 바꿔줘야 한다
		if (st.top() != t) {
			res += 2; //즉 연산을 2번 수행
		}
		//괄호의 형태가 같다면 하나만 방향을 바꿔주면 된다
		else {
			res += 1; //연산 1번 수행
		}
		st.pop();
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	//테스트 케이스 번호
	int num = 1;
	while (1) {
		cin >> s;
		//-을 만나면 반복문 종료
		if (s[0] == '-') break;
		else {
			cout << num << ". " << isBalanced(s) << '\n';
			num++;  
		}
	}
	return 0;
}