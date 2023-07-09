#include <iostream>

using namespace std;

// Ǯ��.
// string �迭�� �־������� ���� ���� ��ȸ�ϴ� ���� �ƴ�
// ���� ���� ��ȸ�Ͽ� �� �ະ ���ڰ� ������ Ȯ���ϴ� ����.

// �ڼ��� ������ �ּ����� �����.

int N;
string board[50];

void MakeAnswer()
{
    string answer;
    bool isfind;
    int Ssize = board[0].size();

    // �� ������ ��ȸ�Ѵ�.
    for (int i = 0; i < Ssize; ++i)
    {
        isfind = true;
        char cur = board[0][i];
        // �� �ະ�� ��ȸ�Ͽ� ��� ���ڰ� ���ٸ� �� ���ڸ� �����信 �߰��ϰ� �׷��� �ʴٸ�
        // '?'�� �߰��Ѵ�.
        for (int j = 0; j < N; ++j)
        {
            if (board[j][i] != cur)
            {
                isfind = false;
                break;
            }
        }
        if (isfind)
        {
            answer += cur;
        }
        else
        {
            answer += '?';
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}