#include <iostream>
#include <vector>

using namespace std;
//각 행렬의 성분은 1,000,000 이하의 양의 정수이고 최대 도시  수는 10이므로 최댓값을 1e9
const int MAX = 1e9;

vector<bool> check(10); //이미 도시를 방문했는지 검사할 때 사용할 배열
vector<vector<int>> cost_matrix(10, vector<int>(10, 0)); //비용 행렬 선언과 초기화
int n, ans = MAX; //최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int cnt, int visit, int cost){
    //n개의 도시를 다 돌면 종료 
    if(cnt == n){
        //맨 마지막에 여행을 출발했던 도시로 돌아오는 것 가능한 경우
        if(cost_matrix[visit][0] != 0){
            //가장 적은 비용이 드는 ans로 ans값 경신
           ans = min(ans, cost + cost_matrix[visit][0]);
        }
        return;
    }
    //현재 방문한 visit 도시에서 i로 이동하면서
      for (int i = 0; i < n; i++) { 
        if (cost_matrix[visit][i] && !check[i]) { //길이 있는데, 아직 방문하지 않은 도시가 있는 경우
            check[i] = true;
            backtracking(cnt + 1, i, cost + cost_matrix[visit][i]);
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}

int main(){
    //입력
    cin >> n;

    //비용행렬 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost_matrix[i][j];
        }
    }

    //0번 도시에서 시작
    check[0] = true;
    //연산
    backtracking(1, 0, 0);

    //출력
    cout << ans;

    return 0;
}