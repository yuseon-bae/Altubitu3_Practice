#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001
vector<bool> is_prime(MAX, false);

void findPrime() {
    //2 ~ 제곱근 n까지 검사
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) { //i가 소수라면
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = true;  //i의 배수를 제거 
            }
        }
    }
}

void printout(int n) {
    bool chk = false;

    for (int a = 3; a <= n; a += 2) {
        // int b = n - a;
        if (!is_prime[a] && !is_prime[n - a]) {    //a가
            cout << n << " = " << a << " + " << n - a << "\n";
            chk = true;
            break;
        }
    }
    if (!chk) {
        cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    findPrime();


    while (1) {

        cin >> n;
        if (n == 0) {
            break;
        }
        printout(n);
    }

    return 0;
}