#include <iostream>

using namespace std;

// Ǯ��.
// ���� ��û ���ظ� ���ߴٴ��� Ȥ�� ��û ������ ��������. ������ ������ �� ���ذ� ���� �ʴ´�.
// �ٵ� �����ش޶�� ��û�� ���Ҵ� �����ٺ��� ������ �̻��Ѱ͵� ���� ������ ����.
// ��·�� �־��� P�� �ǵ���� 0, 1, 2�� �ݺ��� �Ǿ�� �ϴ� �����̸�, �׷��� ���ؼ� ���������� �־���
// s�� �°� ���ҵ��� ��迭�ؾ� �ߴ�. �� ���� ����Ŭ�� �����Ҽ� �ְ� �Ǵµ� �װ� ���� ���Ҽ� ���ٴ� ���� �Ǿ�
// -1�� ����ؾ� �Ѵ�. ó������ set�� �̿��ؼ� ����Ŭ�� �����ߴµ� ���� �׷� �ʿ���� �� ó������ �˾Ƶξ��ٰ�
// �װͰ� ��ġ�ϴ� �迭�� �ȴٸ� ����Ŭ�� �������� �˼� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int P[48], S[48], board[48], to[48];
int N;

// �������� Ȯ���ϴ� �Լ�. ����Ѵ�� ���� �迭�� ������ 0, 1, 2�� �ݺ��̶�� �����̴�.
bool IsAnswer()
{
    for (int i = 0; i < N; ++i)
        if (P[i] % 3 != i % 3)
            return false;
    return true;
}

// ����Ŭ�� �����ϴ��� �����ϴ� �Լ�. ������ board�� ���� �迭�� ��ġ�Ѵٸ� ����Ŭ�� �Ͼ��.
bool IsCycle()
{
    for (int i = 0; i < N; ++i)
        if (to[i] != board[i])
            return false;
    return true;
}

void MakeAnswer()
{
    int answer = 0;
    // ����Ŭ�� �����ϰų�, ������ ã�������� �ݺ��Ѵ�.
    while (true)
    {
        if (IsAnswer())
        {
            cout << answer << '\n';
            return;
        }
        // ���� �迭���� S�� �°� ��迭�Ͽ� to�� �����Ѵ�.
        for (int i = 0; i < N; ++i)
            to[S[i]] = P[i];
        if (IsCycle())
        {
            cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < N; ++i)
            P[i] = to[i];
        ++answer;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
        board[i] = P[i];
    }
    for (int i = 0; i < N; ++i)
        cin >> S[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}