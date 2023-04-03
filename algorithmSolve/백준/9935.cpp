#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ������ ����� �������� Ǯ�� �ȴ�.
// �տ������� ���ĺ��� �ϳ��� ���Ϳ� �����ϴٰ� ������ ũ�Ⱑ ��ź�� ũ�⸸ŭ
// Ŀ���� ���� ����� ���ĺ��� ��ź�� ���Ͽ� ���ٸ� ��ź��ŭ ����� ������
// �����ϰ� ���� �ʴٸ� �����Ѵ�. �̰��� �־����� ���ĺ��� ���̸�ŭ �ݺ��ϸ� �ȴ�.

string board, bomb;
vector<char> answer;
int bsize;

void CheckBomb()
{
    int asize = answer.size();
    for (int i = 0; i < bsize; ++i)
    {
        if (answer[asize - bsize + i] != bomb[i])
            return;
    }

    for (int i = 0; i < bsize; ++i)
        answer.pop_back();
}

void MakeAnswer()
{
    bsize = bomb.size();

    for (int i = 0; i < board.size(); ++i)
    {
        answer.push_back(board[i]);
        if (answer.size() >= bsize)
            CheckBomb();
    }

    if (answer.empty())
        cout << "FRULA";
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i];

    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> board >> bomb;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}