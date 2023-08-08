#include <iostream>
using namespace std;

//기숙사 바닥의 l(높이), w(너비) 구해서 리턴하는 함수
pair<int, int> length(int r, int b) {
    //빨간색 타일 + 갈색 타일 = 방의 크기(L*W)
    int area = r + b;
    for (int l = area; l > 0; l--) {
        //l(높이)의 값이 방의크기에서 0이 될때까지 하나씩 감소하면서 테두리 타일개수와 빨간색 타일의 개수를 비교
        if (area % l != 0) { //w 가 정수가 아니라면 넘어감
            continue;
        }
        int w = area / l;   // w=방의 넓이/높이
        //테두리 타일 개수= (l + w) * 2 - 4(겹치는 부분)
        if (r == ((l + w) * 2 - 4)) {  //테두리 타일의 개수가 빨간 타일의 개수와 같을떄
            return make_pair(l, w);  //방의 크기를 표현하는 l과 w을 pair로 만들어 반환 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, b;  //r은 빨간색 타일, b는 갈색 타일
    //입력
    cin >> r >> b;
    //연산
    pair<int, int> result = length(r, b);

    //출력은 되도록 메인에서
    cout << result.first << ' ' << result.second << '\n'; //l 과 w 출력
    return 0;

}