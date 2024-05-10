#include <iostream>
#include <map>

using namespace std;

// Ǯ��.
// �����̿� ������ ������ �� ������ ������ ������� ���� ����ϴ� ������.
// �� Ǯ�̿����� map�� �̿��� �� ������� ���¸� �����Ͽ����� ������ �׷��� ���� �����̳ʴ� ������.
// ���� �� Ǯ�̺��ٴ� ���²� ������ ������� vector���� �迭�� �����Ͽ� �Ѵ� �迭�� �������� �ʴ´ٸ� �����ϰ�
// ���߿� �ϳ��� �����Ѵٸ� �ٸ� �ϳ��� �����ϴ� ������ �ص� �ɰ� ����.

int N;

void MakeAnswer()
{
    map<string, bool> board;
    board["ChongChong"] = true;
    string str1, str2;
    int answer = 1;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str1 >> str2;
        if (!board[str1] && board[str2])
        {
            board[str1] = true;
            ++answer;
        }
        else if (!board[str2] && board[str1])
        {
            board[str2] = true;
            ++answer;
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
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}