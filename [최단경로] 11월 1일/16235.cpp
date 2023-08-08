//16235 추가제출
#include <iostream>  //c++ 입출력 헤더 
#include <deque>     //deque 헤더
#include <vector>    //vector 헤더

using namespace std; //std라이브러리 사용
// vector<vector<int>> 자료형을 matrix 별칭으로 사용할 것임을 정의
typedef vector<vector<int>> matrix;

//살아있는 나무의 수를 반환하는 함수
int countTrees(int n, vector<deque<int>>& trees) {
	int answer = 0; //살아있는 나무 수 answer
	for (int i = 0; i < n; i++){ //x좌표 : i
		for (int j = 0; j < n; j++){ //y좌표: j
            //i행 j열에 있는 나무의 수만큼 살아있는 나무 수에 추가
			answer += trees[i * 10 + j].size();
		}
	}
	return answer; //살아있는 나무 수 반환
}

//가을에 번식하는 나무 추가하는 함수
void reproduceTree(int n, int x, int y, vector<deque<int>>& trees){
	for (int i = x - 1; i <= x + 1; i++){ //인접한 8개의 칸의 x좌표
		for (int j = y - 1; j <= y + 1; j++){ //인접한 8개의 칸의 y좌표
			if ((i == x) && (j == y)) { //가운데 칸인 경우
				continue; // 나무가 생기지 않는다
			}
			if (i >= 0 && j >= 0 && i < n && j < n){ //인접한 8개의 칸 중 범위 내의 칸에서
                //나이가 1인 나무 추가  
				trees[i * 10 + j].push_front(1);
			}
		}
	}
}

//계절별 연산을 진행할 함수
void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& a, vector<pair<int, int>>& breeding_tree){
	for (int i = 0; i < n; i++){ //x좌표의 범위: 0 ~ n-1
		for (int j = 0; j < n; j++){ //y좌표의 범위: 0 ~ n-1
			int leftover = 0; //남은 양분 양
			deque<int> dq; //정보 갱신할 deque
			for (auto age : trees[i * 10 + j]){ //각 트리에 대해
				if (food[i][j] < age) { //양분을 먹을 수 없다면 나무는 죽는다
					leftover += age / 2; //각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가
					continue; //연산 계속 진행
				}
				food[i][j] -= age; //죽지 않으면 양분을 나이만큼 먹는다
				dq.push_back(age + 1); //나이를 1 증가시킨다
				if ((age + 1) % 5 == 0){// 번식 가능(나이가 5의 배수인 경우만) 하다
					breeding_tree.push_back({ i, j }); //나무 번식
				}
			}
			trees[i * 10 + j] = dq; //나무 정보 갱신
			food[i][j] += (a[i][j] + leftover); //S2D2가 겨울에 주는 양분의 양 + 죽은 나무가 남긴 양분의 양
		}
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main(){  //main함수
	int n, m, k;  // 땅 크기 n, 나무 수 m, 년도 k 변수 선언
	//입력
	cin >> n >> m >> k;
    //S2D2가 겨울에 주는 양분의 양 저장할 배열 선언 & 초기화
	matrix a(n, vector<int>(n, 0));
    //땅의 양분 저장할 배열 선언 & 초기화
	matrix food(n, vector<int>(n, 5));
    //나무의 정보를 나타내는 세 정수 x, y, z (x,y: 나무 위치, z: 나무 나이)를 저장할 덱 벡터 선언 & 초기화
	vector<deque<int>> trees(n * 10 + n);

	for (int i = 0; i < n; i++){  //i번째 줄의
		for (int j = 0; j < n; j++){ //j번째 값인
			cin >> a[i][j]; //a[i][j] 입력 받기
		}
	}
	for (int i = 0, x, y, z; i < m; i++){ //m개의 줄에는 상도가 심은
		cin >> x >> y >> z; //나무 정보 입력
		x--; y--; //0부터 시작하기 때문에 배열 삽입을 위해 -1
		trees[x * 10 + y].push_front(z); //(x,y)에 위치한 나이가 z인 나무 배열에 추가
	}
	while (k--) { //k년동안 수행
        //나이가 5의 배수인 번식할 트리 정보를 저장할 배열
		vector<pair<int, int>> breeding_tree;
        //계절별 연산을 진행할 함수 호출
		solution(n, trees, food, a, breeding_tree);
		for (auto [i, j] : breeding_tree){ //번식할 나무에 대해
            //reproduceTree (새로 생기는 나무 계산) 호출
			reproduceTree(n, i, j, trees);
		}
	}
    //출력
	cout << countTrees(n, trees); 
	return 0;  //함수 종료
}