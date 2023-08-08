#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int mintime = 1e9, maxheight = -1;

void solve(int n, int m, int b, vector<vector<int>> &map){
    //최소높이 0부터 최대높이 256까지 반복
    for(int h=0; h<=256; h++){
        int inventory = 0, remove = 0, time = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cur_height = map[i][j] - h;
                if(cur_height>0){
                    //양수일 경우 블록을 제거 -> 2초 소요
                    remove += cur_height;
                    time += 2*cur_height;
                } else{
                    //음수일 경우 블록을 채움 -> 1초 소요
                    inventory -= cur_height;
                    time += 1*-cur_height;
                }
            }
        }
        //지울 블록의 수 + 처음에 가지고 있던 인벤토리 블록의 개수 >= 채울 블록 개수
         if(remove+b>=inventory){
            if(mintime >= time){
                mintime = time;
                maxheight = h;
            }
         }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL);

    //입력
    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> map (n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    //연산
    solve(n, m, b, map);
    /*  1. 높이 확인 : 최소 높이 0부터 최대 높이는 256까지 반복
        2. 채워야할 블록개수와 지워야할 블록개수 계산 후 
        3. 높이와 걸린 시간 갱신
        참고 : https://codecollector.tistory.com/678
    */

    //출력
    cout << mintime << " " << maxheight;

    return 0;

}