#include <iostream>

using namespace std;

//유클리드 호제법으로 두 수의 최대공약수를 구하는 함수
int gcdRecursion(int a, int b) {
    // a > b일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);  //재귀호출
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //x와 y는 1,000,000,000 이하의 자연수 
    // -> gcd 최댓값 역시 1,000,000,000
    long long int x, y, gcd;
    //입력
    cin >> x >> y;

    //가로 길이가 x, 세로 길이가 y인 직사각형에 대각선을 그려보면
    //대각선이 꼭지점을 지나가지 않는 직사각형은 대각선이 그려져 있는 타일의 개수가 (x + y -1)개이고,
    //대각선이 꼭지점을 지나가는 직사각형은 대각선이 그려져 있는 타일의 개수가 (x + y -1 - (점의 개수))이다.
    //이 때 꼭지점의 개수는 x, y의 최대공약수이다
    //x,y가 서로소이면 점의 개수는 1개가 되므로 대각선이 그려져 있는 타일의 개수는 x + y - gcd(x,y)
    gcd = gcdRecursion(x, y);
    
    //출력
    cout << x + y - gcd;
    return 0;
}