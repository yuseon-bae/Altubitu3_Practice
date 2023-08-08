#include <iostream> //c++ 입출력 헤더
#include <vector>  //vector 헤더

using namespace std; //std라이브러리 사용


//단절점, 단절선 파악 함수
string check(int t, int k, vector<vector<int>>& tree) {
	if (t == 2 || tree[k].size() >= 2) { //t가 2일 때 k번째 간선이 단절선이면
		return "yes";  //"yes"반환 후 함수 종료
	}
		
    //그 외의 경우
	return "no";  //"no"반환 후 함수 종료
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() { //main함수

	ios_base::sync_with_stdio(false); //c++입출력 속도 향상 코드
	cin.tie(NULL); //c++입출력 속도 향상 코드

	int n, v, u, test_case; // 트리의 정점개수 n, 간선정보 v, u, 질의 횟수 test_case
	cin >> n; //트리 정점 개수 입력받기

	vector<vector<int>> tree (n + 1, vector<int>(0)); //트리 벡터 선언 및 초기화

	n--; //트리 벡터의 크기가 n+1이므로 n-- 먼저 수행 
	while (n--) { //n의 수만큼 반복문 수행
		cin >> v >> u; // 무방향 그래프
		tree[v].push_back(u); //트리에 간선정보 push
		tree[u].push_back(v); //트리에 간선정보 push
	}

	cin >> test_case; //test_case입력

	int t, k;  //질문 입력받을 변수 선언
	while (test_case--) { //test_case 수만큼 반복문 수행
		cin >> t >> k; //질문 입력
		cout << check(t, k, tree) << '\n';  //연산 & 출력
						
	}
}