#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;

void findParent(int curr){
    for(int i=0; i<tree[curr].size(); i++){
        //다음 인접 노드로 이동
        int next = tree[curr][i];
        if(parent[next] == 0){
            //다음 노드의 부모 노드는 현재 노드가 됨
            parent[next] = curr;
            findParent(next);  //재귀호출
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, node1, node2;

    //입력
    cin >> n;
    //부모-자식 관계로 주어지지 않았으므로 인접 리스트 그래프로 사용
    tree.assign(n + 1, vector<int>(0));
    parent.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> node1 >> node2;
        tree[node1].push_back(node2);   //양방향 입력
        tree[node2].push_back(node1);
    }

    //연산
    findParent(1);

    //출력
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}