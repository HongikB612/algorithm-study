/*
2023.05.15
런타임 에러 1회 존재: 
stack.pop(), stack.push() 함수는 stack에 값이 존재할 때만 사용 가능
stack.empty() = 1 인 경우 Runtime error(Segment Fault) 발생


*/



#include<bits/stdc++.h>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, count = 0;
    cin >> num;

    for(int i = 0; i < num; i++){
        string a;
        cin >> a;
        stack<char> s;
        for(auto c : a){
            if(s.empty()){
                s.push(c);
            }
            else{
                if(s.top() == c)
                    s.pop();
                else
                    s.push(c);
            }
        }
        if(s.empty())
            count++;
        
    }

    cout << count;

}