#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;

//플로이드-워셜 함수
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                //i->k->j가 i->j보다 짧은 경우
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    //중간 지점인 k로 경로 이동
                    graph[i][j] = graph[i][k] + graph[k][j];
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

int main(){
    int n, m, u, v, w;

    //입력
    cin >> n >> m;
    vector<vector <int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector <int>> table(n+1, vector<int>(n+1, 0));

    while(m--){
        cin >> u >> v >> w;

        //무방향 그래프 간선 정보 설정
        graph[u][v] = graph[v][u] = w;

        //경로 정보 설정
        table[u][v] = v;
        table[v][u] = u;
    }

    for(int i=1; i<=n; i++){
        graph[i][i] = 0;
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j){
                cout << "- ";
            } else{
                cout << table[i][j] << ' ';
            } 
        }
        cout << '\n';
    }
    return 0;
}