#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
 
using namespace std;
typedef tuple<int, int, int> tp;
vector<int> parent(301, 0);

// Find 연산
int findParent(int x) {
    if (parent[x] == x) { 
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

// union 연산
void unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px > py) {  //새로운 루트 px
        parent[px] = py;
    } else { //새로운 루트 py
        parent[py] = px;
    }
   
}

//kruskal 연산
int kruskal(int n, vector<tp> &edge) {
    int sum= 0;

    for (auto[w, n1, n2]: edge) {
        if (findParent(n1) == findParent(n2)) { //사이클이 생기는 경우
            continue;
        }
        
        unionNodes(n1, n2);
        sum += w;
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, p;
    //입력
    cin >> n;
    vector<tp> edge;
  
    
    for(int i=1; i<=n; i++){
        cin >> w;
        edge.push_back({w, 0, i});
        parent[i] = i;
    }
     
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> p;
            if(i != j){
                edge.push_back({p, i, j});
            }
        }
    }

    sort(edge.begin(), edge.end());

    //연산 & 출력
    cout << kruskal(n, edge);
    return 0;

    // 아이디어 참고 사이트1 : https://conkjh032.tistory.com/386
    // 아이디어 참고 사이트2 : https://barbera.tistory.com/25

}