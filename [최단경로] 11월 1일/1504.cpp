#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e8 * 2;

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v+1, INF);  //각 정점까지의 최단 경로 저장
    //first: 시작점으로부터 거리, second: 정점
    priority_queue<ci, vector<ci>, greater<>> pq;

    //시작 정점 초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
          
        if (weight > dist[node]) {
            continue;
        }

        for (int i=0; i<graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            
            //최단 경로 값이 갱신된 경우
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main(){
    int n, e, a, b, c, v1, v2;

    //입력
    cin >> n >> e;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));

    while(e--){
        cin >> a >> b >> c;
        //양방향
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin >> v1 >> v2;
    //연산
    vector<int> dist_from_1 = dijkstra(1, n, graph); //1에서 시작한 다익스트라 결과 
    vector<int> dist_from_v1 = dijkstra(v1, n, graph); //v1에서 시작한 다익스트라 결과 
    vector<int> dist_from_v2 = dijkstra(v2, n, graph); //v2에서 시작한 다익스트라 결과 

    //1.1->v1->v2->n의 경우와 2.1->v2->v1->n의 경우 중 최솟값 구하기
    int ans = min(dist_from_1[v1]+dist_from_v1[v2]+dist_from_v2[n], dist_from_1[v2]+dist_from_v2[v1]+dist_from_v1[n]);

    //출력
    if(ans >= INF){
        cout << -1;
    } else{
        cout << ans;
    }

    return 0;

}