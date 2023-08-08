#include <iostream>
#include <deque>

using namespace std;

typedef deque<int> de;

deque<int> dodo, suyeon;

//종을 쳤을 떄 그라운드에 나와 있는 카드 더미를 합치는 함수
void cardCombi(de& winner_card, de& winner_ground, de& loser_ground){
    //패자의 그라운드가 비워질 때 까지
    while(!loser_ground.empty()){
        //승자의 카드에 아래에 집어 넣어줌
        winner_card.push_back(loser_ground.back());
        loser_ground.pop_back();
    }
    //자신의 그라운드에 있는 카드 더미 역시 뒤집어 자신의 덱 아래로 그대로 가져와 합친다.
    while(!winner_ground.empty()){
        winner_card.push_back(winner_ground.back());
        winner_ground.pop_back();
    }
}

void checkCard(de& do_ground, de& su_ground){
    //도도가 종을 치는 경우: 그라운드에 나와 있는 각각의 카드 더미에서 가장 위에 위치한 카드의 숫자가 5가 나오는 순간
    if(!do_ground.empty() && do_ground.front() == 5){
        cardCombi(dodo, do_ground, su_ground);
    }
    if(!su_ground.empty() && su_ground.front() == 5){
        cardCombi(dodo, do_ground, su_ground);
    }
    //수연이가 종을 치는 경우: 그라운드에 나와 있는 각각의 카드 더미에서 가장 위에 위치한 카드의 숫자 합이 5가 되는 순간
    if(!do_ground.empty() && !su_ground.empty() && do_ground.front() + su_ground.front() == 5){
        cardCombi(suyeon, su_ground, do_ground);
    }
}

string palyGame(int m, deque<int> &dodo, deque<int> &suyeon){
    deque<int> do_ground, su_ground; // 각각 도도와 수연의 그라운드
    int turn = 0;
    //도도나 수연이의 카드가 비워질 때 까지
    while(!dodo.empty() && !suyeon.empty()){
        //도도의 카드 하나 내려놓기
        do_ground.push_front(dodo.front());
        dodo.pop_front();
        //도도의 카드가 비어있는 경우라면 
        if(dodo.empty()) {
            return "su";  //수연 승리
        }
        checkCard(do_ground, su_ground);
        //도도가 카드를 내려놓으면 한 턴 지나감
        if(++turn == m) break;  //게임 진행 횟수가 m이 되면 종료

        //수연이의 카드 하나 내려놓기
        su_ground.push_front(suyeon.front());
        suyeon.pop_front();
        //수연이의 카드가 비어있는 경우라면
        if(suyeon.empty()){
            return "do";  //도도 승리 
        }
        checkCard(do_ground, su_ground);
        //수연이가 카드를 내려놓으면 한 턴 지나감
        if(++turn == m) break; //게임 진행 횟수가 m이 되면 종료
    }

    if(dodo.size() > suyeon.size()){
        return "do";     //도도가 이기는 경우
    }
    if(dodo.size() < suyeon.size()){
        return "su";     //수연이가 이기는 경우
    }
    else return "dosu";  //비기는 경우

}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m, do_num, su_num;
    //입력
    cin >> n >> m;

    //도도와 수연이의 카드에 적힌 수 입력받기
    while (n--){
        cin >> do_num >> su_num;
        dodo.push_front(do_num);
        suyeon.push_front(su_num);
    }

    //연산 & 출력
    cout << palyGame(m, dodo, suyeon);

    return 0;
}