#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init;
  cin >> init;
  list<char> Lst;

  for (auto c : init) Lst.push_back(c); //입력된 init을 list에 저장

  auto cursor = Lst.end(); //조건: 커서는 처음에 문장 끝부분에 위치한다

  int q;
  cin >> q;

  while (q--) { 
    char op;
    cin >> op;
    if (op == 'P') { //P $: $라는 문자를 커서 왼쪽에 추가
      char add;
      cin >> add;
      Lst.insert(cursor, add);
    }
    else if (op == 'L') { //L: 커서를 왼쪽으로 한 칸 옮김
      if (cursor != Lst.begin()) cursor--;
    }
    else if (op == 'D') { //R: 커서를 오른쪽으로 한 칸 옮김
      if (cursor != Lst.end()) cursor++;
    }
    else { // B: 커서 왼쪽의 문자를 삭제 (궁금한거: 문제에 하위 조건은 왜 달려있을까)
      if (cursor != Lst.begin()) {
        cursor--;
        cursor = Lst.erase(cursor);
      }
    }
  }
  for (auto c : Lst) cout << c; //출력
}
