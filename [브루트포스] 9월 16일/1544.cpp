#include <iostream>
#include <vector>
using namespace std;

vector<string> str; //입력되는 단어들 중 서로 다른 단어들을 담아줄 벡터

int checkCycle(string word) {
    bool same = false;
    if (str.empty()) {
        //벡터에 단어를 추가해 줄 경우
        //1. 벡터에 아무것도 없을 때
        //2. 벡터 안에 있는 단어와 새로 입력되는 단어가 완전히 다른 단어일 때
        str.push_back(word);  //1번 경우
    }
    
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str[i].size(); j++) {
            // 같은 단어가 있다면 search 종료
            if (word == str[i]) {
                same = true;
                break;
            }
            // 단어가 같지 않다면 맨 앞글자를 맨뒤로 보내줘서 다시 확인
            else {
                str[i] = str[i] + str[i].at(0);
                str[i].erase(str[i].begin());
            }
        }
    }
    if (same == false) { //2번 경우
        str.push_back(word);
    }
    //벡터 안에 들어있는 서로 다른 단어들의 갯수를 반환
    return str.size();
}

int main() {
    int n;
    string word;
    int result = 0;

    //입력
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        //연산
        result = checkCycle(word);
    }

    //출력
    cout << result << '\n';
    return 0;
}