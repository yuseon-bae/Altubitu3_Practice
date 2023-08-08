#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

int n;
//수의 개수가 2<=n<=11이므로 크기가 11인 벡터로 수를 저장
vector <int> num(11);
//연산자는 배열로 저장
int oper[4];
int ma = MAX;
int mi = -MAX;

//연산자를 끼워넣어 수들의 최댓값과 최솟값을 구하는 함수
void calcul(int result, int count) {
	//연산 종료 시점
	if (count == n) {
                         //연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어지므로
		if (mi < result) mi = result;
		if (ma > result) ma = result;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			oper[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
			if (i == 0)  //oper[0]은 덧셈 연산자
				calcul(result + num[count], count + 1);
			else if (i == 1) //oper[1]은 뺄셈 연산자
				calcul(result - num[count], count + 1);
			else if (i == 2) //oper[2]는 곱셈 연산자
				calcul(result * num[count], count + 1);
			else              //oper[3]은 나눗셈 연산자
				calcul(result / num[count], count + 1);
			oper[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> n;
            //숫자 입력
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
            //연산자 입력
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	calcul(num[0], 1);
            
            //출력 
	cout << mi << '\n' << ma;
	return 0;
}