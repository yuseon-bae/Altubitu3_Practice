#include <iostream>
#include <cmath>

using namespace std;

 //기초대사량 변화하는 경우 처리하는 함수
pair<int, int> diet(int D, int W0, int In, int A, int I0, int T) {
    //다이어트 전 일일 기초 대사량(=b) = 일일 에너지 섭취량
    int b = I0;
    int weight = W0;
    //다이어트 기간동안
    while (D--) {
        int Out = b + A;
        weight += (In - Out);
        //|일일 에너지 섭취량 - 일일 에너지 소비량| > 기초 대사량 변화 역치(T)이면
        if (abs(In - Out) > T) { 
            //일일 기초 대사량 = [(일일 에너지 섭취량 - 일일 에너지 소비량) / 2] + 일일 기초 대사량
            b += floor((double)(In - Out) / 2); //음수를 나누는 경우 -> 소수점은 버려지므로 내림함수 floor 사용
        }
        //몸무게와 일일기초 대사량이 0보다 작으면 데시의 사망이 예상
        if (weight <= 0 || b <= 0) {
            return make_pair(0, 0);
        }
    }
    return make_pair(weight, b);
}

int main() {
    int W0, I0, T, D, In, A;

    //다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량 I0, 기초 대사량 변화 역치 T 입력
    cin >> W0 >> I0 >> T;
    // 다이어트 기간, 다이어트 기간 일일 에너지 섭취량 I, 다이어트 기간 일일 활동 대사량 A
    cin >> D >> In >> A;

    //일일 기초 대사량의 변화를 고려하지 않는 경우
    int weight = W0 + (In - (I0 + A)) * D;
    if (weight <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight << ' ' << I0 << '\n';
    }

    //일일 기초 대사량의 변화를 고려하는 경우
    pair <int,int> result = diet(D, W0, In, A, I0, T);
    if (!result.first || !result.second) {
        cout << "Danger Diet\n";
    }
    else {
        string ans = "NO";
        if (I0 - result.second > 0) {
            ans = "YOYO";
        }
        //다이어트 후 예상 체중과 일일 기초 대사량을 출력
        cout << result.first << ' ' << result.second << ' ' << ans << '\n';
    }
    return 0;
}