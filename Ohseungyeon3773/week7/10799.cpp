/*
2023.5.15
변수 선언 위치 오류 1회(반복문 내로 잘못 위치시킴)

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num = 0;
    bool PrevClosed = false;
    stack<char> s;
    string a;
    cin >> a;
    for(auto c:a){
        if(s.empty() ||  c == 40){
            PrevClosed = false;
            s.push(c);
        }
        else{
            if(PrevClosed == false){
                PrevClosed = true;
                num = num + (s.size() - 1);
                s.pop();
            }
            else{
                PrevClosed = true;
                num += 1;
                s.pop();
            }
        }
    }

    cout << num;

}