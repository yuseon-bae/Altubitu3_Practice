#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int n, vector<int> indegree, vector<vector<int>> graph) {
    vector<int> result; 
    priority_queue<int, vector<int>> pq; 

    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { 
            pq.push(-i); //쉬운 문제부터 풀어야 하므로
        }
    }

    while(!pq.empty()) {
        int node = -pq.top(); 
        pq.pop();
        //출력
        cout << node << ' ';

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            indegree[next]--;
            if(!indegree[next]) { 
                pq.push(-next);
            }
        }
    }

}

int main() {
    int n, m, a, b;

    //입력
    cin >> n >> m;

    vector<int> indegree (n+1, 0);
    vector<vector<int>> graph (n+1, vector<int> (0));

    while(m--) { 
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }

    //topologicalSort함수에서 연산 & 출력
    topologicalSort(n, indegree, graph);
   
    return 0;
}