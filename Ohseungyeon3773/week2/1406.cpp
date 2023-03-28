#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init;
  cin >> init;
  list<char> Lst;

  for (auto c : init) Lst.push_back(c); //�Էµ� init�� list�� ����

  auto cursor = Lst.end(); //����: Ŀ���� ó���� ���� ���κп� ��ġ�Ѵ�

  int q;
  cin >> q;

  while (q--) { 
    char op;
    cin >> op;
    if (op == 'P') { //P $: $��� ���ڸ� Ŀ�� ���ʿ� �߰�
      char add;
      cin >> add;
      Lst.insert(cursor, add);
    }
    else if (op == 'L') { //L: Ŀ���� �������� �� ĭ �ű�
      if (cursor != Lst.begin()) cursor--;
    }
    else if (op == 'D') { //R: Ŀ���� ���������� �� ĭ �ű�
      if (cursor != Lst.end()) cursor++;
    }
    else { // B: Ŀ�� ������ ���ڸ� ���� (�ñ��Ѱ�: ������ ���� ������ �� �޷�������)
      if (cursor != Lst.begin()) {
        cursor--;
        cursor = Lst.erase(cursor);
      }
    }
  }
  for (auto c : Lst) cout << c; //���
}
