#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {0};
    int A, B, C = 0;
    cin >> A;

    while (A>0) //A�� �� �ڸ����� �ִ� ���� ī��Ʈ
    {
        arr[A%10]++;
        A/=10;
    }

    B = (arr[6] + arr[9] + 1)/2; //6�� 9�� ���� ���� ���
    arr[6] = 0;
    arr[9] = B;


    for(int i = 0; i <10; i++) //���� ���� ī��Ʈ�� Ƚ�� ���
    {
        if (arr[i] > C) 
            C = arr[i];
    }

    cout << C; 

    return 0;
}