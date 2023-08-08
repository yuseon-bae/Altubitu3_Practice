#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cntChild(int snack_length, vector<int> &snack){
    int num = 0; 
    //가장 긴 과자부터 줄어들면서 계산
    for(int i=snack.size()-1; i>=0; i--){
        if(snack[i] < snack_length){
            break;
        }
        //과자 길이에 따라 몇 명의 어린이에게 나누어 줄 수 있는지 계산
        num += (snack[i]/snack_length);
    }
    return num;
}
int binarySearch(int left, int right, int target, vector<int> &snack){
   int ans = 0;
    while(left <= right){
        int mid = (left + right)/2;  //과자의 길이 mid
        int child = cntChild(mid, snack);

        if(child >= target){
            left = mid + 1;
            ans = mid;
        } else{
            right = mid - 1;
        }
    }  

    return ans;  
}
int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m,n;

    //입력
    cin >> m >> n;
    vector<int> snack(n,0);
    //각 과자의 길이 입력
    for(int i=0; i<n; i++){
        cin >> snack[i];
    }
    
    //정렬
    sort(snack.begin(), snack.end());
    
    //연산&출력
    cout << binarySearch(1, snack[n-1], m, snack);

    return 0;

}