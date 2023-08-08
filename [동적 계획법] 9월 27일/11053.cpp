#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findIncreList(int n, vector<int> &arr) {
    //수열의 최솟값은 1이므로 1로 초기화
    vector<int> vec(n, 1);
    int result = 1;
    //수열의 길이만큼 돌아보면서
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { 
                //증가하는 부분이면
                vec[i] = max(vec[i], vec[j] + 1);
            }
        }
        //증가하는 수열의 최장 길이 저장
        result = max(result, vec[i]); 
    }
    return result;
}


int main() {
    int n;

    //입력
    cin >> n;
    //수열 입력받기
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << findIncreList(n, arr);
    return 0;
}