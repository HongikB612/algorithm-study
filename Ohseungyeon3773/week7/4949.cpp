/*
2023.05.15
베워야 할 것들
1. auto 사용법
2. std::stack 정규 함수
3. 사용처에 맞는 자료형 할당(ex: isValid vs read) > 가시성
4. ! < 의 적절한 사용
5. 가시성을 고려한 코드

*/

#include<bits/stdc++.h>
#include<string>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(true){
    string a;
    getline(cin, a);
    if(a == ".") break;
    stack<char> s;
    bool isValid = true; 
    for(auto c : a){                        //What is AUTO?
      if(c == '(' || c == '[') s.push(c);
      else if(c == ')'){
        if(s.empty() || s.top() != '('){
          isValid = false;
          break;
        }
        s.pop();
      }
      else if(c == ']'){
        if(s.empty() || s.top() != '['){
          isValid = false;
          break;
        }
        s.pop();
      }
    }
    if(!s.empty()) isValid = false;
    if(isValid) cout << "yes\n";
    else cout << "no\n";
  }
}