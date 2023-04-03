#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;
int stk[MX];
int pos = 0;

void push(int x){
    stk[pos++] = x;
}

void pop(){
    pos--;
}

int checkArr(int x[], int y){
    for(int i = 0; i < y; i++){
        if ((x[i] - x[i + 1] < 0) && (x[i] <= i))
            return 0;
    }
    return 1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[100001];
    int N, i = 1;
    cin >> N;
    
    string ans;
    while (N--) {
        int t;
        cin >> t;
        while (i <= t) {
            push(i++);
            ans += "+\n";
        }
        if (stk[pos-1] != t) {
            cout << "NO\n";
            return 0;
        }
        pop();
        ans += "-\n";
    }
     cout << ans;
}