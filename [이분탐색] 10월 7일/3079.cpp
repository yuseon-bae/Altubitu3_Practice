#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntPeople(ll to_time, vector<ll> &enter_time){
    //주어진 시간 안에서 심사 받을 수 있는 사람 수
    ll num = 0;
    for(int i=0; i<enter_time.size();i++){
        num += (to_time/enter_time[i]);
    }

    return num;
}

ll binarySearch(ll left, ll right, int target, vector<ll> &enter_time){
    while(left<=right){
        ll mid = (left+right)/2;  //심사 받을 때 걸리는 시간 mid
        ll customer = cntPeople(mid, enter_time);

        if(customer >= target){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    
    return left;
}

int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    //입력
    cin >> n >> m;
    vector <ll> enter_time(n,0);

    for(int i=0; i<n; i++){
        cin >> enter_time[i];
    }
    //정렬
    sort(enter_time.begin(), enter_time.end());
    
    //연산&출력
    cout << binarySearch(enter_time[0], enter_time[0]*m,m,enter_time);
    
    return 0;
}