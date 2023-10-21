#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ ������ �����ϴ� �Լ�����. �������� �־�����
// ù°�� ������ ���ϰ� �� ���� 3���� ���� Ƚ��, 2���� ���� Ƚ���� ���ϸ� �ȴ�.
// ���� 2���� ���� Ƚ������ �����ϴٸ� ���������� �־����� �ʿ������� 1���� ���� Ƚ���� �����ϱ� ������
// �׳� �����ϸ� �ȴ�. �ļ��� ������ �κ��� ��Ծ ��̴�. �Ф�

// �ڼ��� ������ �ּ����� �����.

pair<int, int> point[3];
int board[4][4];
int N;

// �� �ĺ����� ������ ���ϴ� �Լ�.
bool Compose(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    // 1. ���� ���� ������ �ٸ��ٸ� ���Ѵ�.
    if (lhs.first != rhs.first)
        return lhs.first > rhs.first;
    // 2. ������ ���ٸ� 3���� ���� Ƚ���� �ٸ��� Ȯ���� ���Ѵ�.
    else if (board[lhs.second][3] != board[rhs.second][3])
        return board[lhs.second][3] > board[rhs.second][3];
    // 3. 3���� ���� Ƚ������ ���ٸ� 2���� ���� Ƚ���� �ٸ��� Ȯ���� ���Ѵ�.
    else if (board[lhs.second][2] != board[rhs.second][2])
        return board[lhs.second][2] > board[rhs.second][2];
    // 4. 2���� ���� Ƚ������ ���ٸ� �񱳰� �Ұ����ϱ⿡ �����Ѵ�.
    else
        return false;
}

void MakeAnswer()
{
    // �� �ĺ����� ������ ���� Ƚ������ �ʱ�ȭ.
    for (int i = 0; i < 3; ++i)
        point[i] = make_pair(0, i + 1);
    memset(board, 0, sizeof(board));
    int cur;
    for (int iter = 0; iter < N; ++iter)
    {
        // �� �л����� ���� ������ ���� ������ �����ְ� Ƚ���� ������Ų��.
        for (int i = 0; i < 3; ++i)
        {
            cin >> cur;
            point[i].first += cur;
            ++board[i + 1][cur];
        }
    }

    // �� �л����� ������ ���Ѵ�.
    sort(point, point + 3, Compose);
    // 1�� �ĺ��� 2�� �ĺ��� ������ ����, 1���� ���� Ƚ������ ���ٸ� �񱳰� �Ұ����ϹǷ� 0�� ���� ������ ����Ѵ�.
    // �� ���� �Լ��� ������ �� �� 2���� �ĺ��� ���� ������ ũ�� 3���� ���� ���� �ް� 2���� ���� ���� ���� �ĺ����ε�
    // �� �ĺ����� ������ 1���� ���� Ƚ���� ���ٴ°� ���� �������� ���� 2���̻��� �񱳰� �Ұ����ϴٴ� ���̴�.
    // ���⼭ 1���� ���� Ƚ���� ����������, ������ ���ٴ°� ���Ծ�����.
    if (board[point[0].second][1] == board[point[1].second][1] &&
        point[0].first == point[1].first)
        cout << 0 << ' ' << point[0].first;
    // �񱳰� �����ߴٸ� �� �� �ĺ��� ��ȣ�� ���� ������ ����Ѵ�.
    else
        cout << point[0].second << ' ' << point[0].first;
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