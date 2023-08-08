#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;   //선물상자와 아이들 수 
    
    priority_queue<int> gift;
      
    //입력
    cin >> n >> m;
    while(n--){
        int input;
        cin >> input;
        //선물의 개수 gift에 집어넣기
        gift.push(input);
    }

    while(m--){
        int want;
        //아이들이 원하는 선물 개수 입력받기
        cin >> want;

        //상자에 아이가 원하는 것보다 적은 양의 선물이 들어있으면
        if(gift.top() < want){
            cout << 0;  //아이가 실망하므로 0을 출력하고
            return 0;   //종료
        }

        //상자에 아이가 원하는 것 이상의 선물이 들어있으면 
        else if(gift.top() >= want){
            gift.push(gift.top() - want); //남은 선물을 다른 사람도 가져갈 수 있게
            gift.pop();
        }
    }
    //출력
    cout << 1;
    return 0;
}