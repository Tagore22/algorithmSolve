#include <iostream>

using namespace std;

// Ǯ��.
// 5���� ���� �Է¹޵�, �־��� ���ڿ� ���� ���� �Է¹��������� ������ answer�� 1�� �����Ѵ�.

int N;

int main()
{
    cin >> N;
    int num, answer = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> num;
        if (num == N)
            ++answer;
    }
    cout << answer << '\n';
}