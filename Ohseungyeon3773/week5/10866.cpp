//백준 10866 덱 구현문제(연습문제)
#include <iostream>
#include <string>
 
using namespace std;
 
const int MX = 1000000;
int deque_arr[2 * MX + 1];
int head = MX, tail = MX;
 
int empty(int dat[]) {
    if (head == tail) return 1; // 덱이 비어 있는 경우
    else return 0; // 덱이 비어 있지 않은 경우
}
 
void push_front(int deque_arr[], int data) {
    deque_arr[--head] = data;
}
 
void push_back(int deque_arr[], int data) {
    deque_arr[tail++] = data;
}
 
int pop_front(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[head++];
}
 
int pop_back(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[--tail];
}
 
int size(int deque_arr[]) {
    return tail - head;
}
 
int front(int deque_arr[]) {
    if (empty(deque_arr)) return - 1;
    return deque_arr[head];
}
 
int back(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[tail - 1];
}
 
int main() {
    int n;
    cin >> n;
    
    string command;
    int command_num;
 
    for (int i = 0; i < n; i++) {
        cin >> command;
 
        if (command == "push_front") {
            cin >> command_num;
            push_front(deque_arr, command_num);
        }
        else if (command == "push_back") {
            cin >> command_num;
            push_back(deque_arr, command_num);
        }
        else if (command == "pop_front") {
            cout << pop_front(deque_arr) << endl;
        }
        else if (command == "pop_back") {
            cout << pop_back(deque_arr) << endl;
        }
        else if (command == "size") {
            cout << size(deque_arr) << endl;
        }
        else if (command == "empty") {
            cout << empty(deque_arr) << endl;
        }
        else if (command == "front") {
            cout << front(deque_arr) << endl;
        }
        else if (command == "back") {
            cout << back(deque_arr) << endl;
        }
    }
    
    return 0;
}
