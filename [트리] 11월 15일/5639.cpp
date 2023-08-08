#include<iostream> //c++ 입출력 헤더
#include<vector>  //vector 헤더

using namespace std; //std라이브러리 사용

/*
전위 순회로 입력된 노드 값을 후위 순위로 출력
전위 순회 (root->left->right)가 재귀적으로 반복
후위 순회 (left->right->root)이 재귀적으로 반복
 temp가 기준
 temp를 기준으로 작은 값이 있으면 해당 원소를 기준으로 왼쪽,오른쪽 나누어 다시 postOrder진행
*/

//전위순회로 입력받은 트리를 후위순회 한 값을 출력하는 함수
void postOrder(int left, int right, vector<int> &tree) {
	if (left > right) { //왼쪽 값이 오른쪽 값보다 크다면
		return; //함수 종료
	}
	int temp = left + 1; //기준점인 temp의 값을 left+1로 설정

	for (int i = left + 1; i < right + 1; i++) { //모든 트리의 노드를 방문하면서
		if (tree[left] < tree[i]) { //left < i인 경우에
			temp = i;  //기준이 되는 temp값 i로 갱신 
                       // -> left+1 ~ i-1 왼쪽 서브트리의 범위
                       //-> temp ~ right 오르쪽 서브트리의 범위
			break;     //반복문 종료
		}
	}
	postOrder(left + 1, temp-1,tree); //재귀호출로 왼쪽 서브트리 탐색
	postOrder(temp, right, tree);    //재귀호출로 오른쪽 서브트리 탐색
	
	cout << tree[left] << '\n';   //출력
}

int main() { //main 함수
	int input; //입력값 받을 변수 선언
	vector<int> tree; //전위순회한 결과를 저장할 벡터 선언
	//tree에 원소 입력(전위순회)
	while (cin >> input) {  //입력값을 받는 동안
		tree.push_back(input);  //값들을 tree에 push
	}
	postOrder(0, tree.size()-1,tree); //연산 & 출력
}