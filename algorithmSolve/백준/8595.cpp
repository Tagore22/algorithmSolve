#include <iostream>

using namespace std;

// Ǯ��.
// ���ڿ��� ��ȸ�ϸ� ���ڵ��� ã�� ������. �� ���ڴ� ���ڷ� �������� �ֱ� ������ ���� ���� ���ڸ�
// �������� ������ ���س��� ���ڵ��� ���ϸ� �ȴ�.

string str;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> str;
    long long answer = 0, cur = 0;
    for (int i = 0; i < N; ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            cur *= 10;
            cur += str[i] - '0';
        }
        else
        {
            answer += cur;
            cur = 0;
        }
    }
    answer += cur;
    cout << answer << '\n';
    return 0;
}