#include <iostream>
#include <vector>
using namespace std;

//그룹단어인지 체크하고 맞으면 true, 아니면 false 반환하는 함수
bool checkGroup(string word) {
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); // 단어에서 특정 문자가 나온 적 있는지 확인하는 bool형 배열
    
    //입력받은 문자열의 길이만큼 비교 반복
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == cur) { //연속해서 나타난 문자일 경우
            continue;
        }
        //이전의 문자와 다른 문자가 나타났다면
        if (alphabet[word[i] - 'a']) {  //word[i] - 'a'를 통해 이전의 알파벳과 다른 알파벳인지 비교
                //그룹 단어가 아니므로 false 반환
                return false;
            }
        cur = word[i];
        alphabet[word[i] - 'a'] = true;
        
    }
    //위의 경우에 걸러지지 않았으면 true 반환
    return true;
}


int main() {
    int n, result = 0;

    //입력
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        //그룹 단어인지 확인하는 연산
        if (checkGroup(word)) { 
            result++;
        }
    }

    //출력
    cout << result <<'\n';
    return 0;
}