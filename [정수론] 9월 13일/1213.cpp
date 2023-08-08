#include <iostream>
#include<vector>
using namespace std;

//입력받은 문자열이 회문을 만들 수 있는지 판별하는 함수
bool cantmakePalin(vector <int>& alphabet) {
    int cnt = 0;
    //문자열에 홀수개인 알파벳이 2개 이상 존재하면 회문을 만들 수 없다
    for (int i = 0; i < 26; i++) {
        //알파벳의 개수가 홀수이면
        if (alphabet[i] % 2 == 1) {
            cnt++;  //카운트
        }
    }
    return cnt > 1;
}

void makePalin(vector <int>& alphabet) {
    string ans;
    //처음 ~ 가운데
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < alphabet[i] / 2; j++)
            ans += i + 'A';
    //+가운데
    for (int i = 0; i < 26; i++)
        if (alphabet[i] % 2)
            ans += i + 'A';
    //+가운데 ~ 마지막
    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < alphabet[i] / 2; j++)
            ans += i + 'A';
    //출력
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력받은 문자열의 알파벳들을 저장할 벡터 
    vector <int> alphabet(26);
    //입력
    string name;
    cin >> name;
    for (int i = 0; i < name.size(); i++) {
        //입력받은 문자열의 알파벳 개수를 벡터에 저장
        alphabet[name[i] - 'A']++;
    }
    //회문을 만들 수 없다면
    if (cantmakePalin(alphabet)) { 
        cout << "I'm Sorry Hansoo";
        return 0;  //종료
    }
    else { //회문을 만들 수 있다면
        makePalin(alphabet);
    }
    return 0;
}