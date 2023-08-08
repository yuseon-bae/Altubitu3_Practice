#include<iostream>
#include<map>
using namespace std;

int N, M, res =0;
map <string, bool> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> input;
		m[input] = true;
	}

	for (int i = 0; i < M; i++){
		cin >> input;
		if (m[input]) {
			res++;
		}
	}

	cout << res << '\n';

}