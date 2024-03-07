#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ù Ǯ���̴�. �ٽ� �ǵ��ƺ��� �ѹ��� ��ȸ�Ҽ� �ִ� ���� 2���� for������ �����µ�
// ��û �����ϰ� �����ߴ�. ���� ��ü�� �������ε� �ܼ��� ����� ��ġ���� ���� ����������
// �ִ� K��ŭ�� ������ ���ʿ������� ���ʴ�� ã�ƺ��� ���̴�.

string str;
bool board[20000];
int N, K;

void MakeAnswer()
{
    memset(board, false, sizeof(board));
    int answer = 0;

    for (int i = 0; i < N; ++i)
        if (str[i] == 'H')
            board[i] = true;

    for (int i = 0; i < N; ++i)
    {
        if (str[i] == 'H')
            continue;
        bool isFind = false;
        for (int j = K; j > 0; --j)
            if (i - j >= 0 && board[i - j])
            {
                board[i - j] = false;
                isFind = true;
                break;
            }
        if (isFind)
        {
            ++answer;
        }
        else
        {
            for (int j = 1; j <= K; ++j)
                if (i + j < N && board[i + j])
                {
                    board[i + j] = false;
                    isFind = true;
                    break;
                }
            if (isFind)
                ++answer;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}