#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������� �����ֵ� ����� ��������. ó������ �׸����ϰ� Ǯ���� ������ ������ �ʹ� ���Ҵ�.
// ���� ��� ��츦 �ľ����� ���غ��� ���ۿ� ������. ��Ʈ��ŷ�� ����ؾ��ߴµ�
// 4���� �׽�Ʈ���̽��� �����ϹǷ� ��� ��츦 �̸� ���ؼ� ���߿��� �񱳸� �ϴ°����� �� ������ �����ϰ�
// �;����� �׷��⿣ 3�� 15������ŭ�� ��찡 �����Ͽ� �Ұ����ߴ�. ��������δ� �ӵ��� �����ϵ�, �뷮�� �����Ͽ�
// �Ź� ó������ ��� ����� ����ؾ߸� �ߴ�. �ٸ� Ǯ�̸� ���� �ξ� �� ������ �ִµ� �� �𸣰ڴ�.

// �ڼ��� ������ �ּ����� �����.

int board[6][3], cur[6][3];
vector<pair<int, int>> vs;
bool isFind;
int sum;

// ��� ����� ���� �ľ��غ��� ��Ʈ��ŷ �Լ�.
void BackTrack(int num)
{
    // ��� ��츦 �� �ľ��ߴٸ� �迭���� ���غ���.
    if (num == 15)
    {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                // �ٸ��ٸ� �׳� Ż���Ѵ�.
                if (board[i][j] != cur[i][j])
                    return;
        // Ż������ �ʰ� �� �迭�� ��ġ�Ѵٸ� isFind�� �����ϰ� Ż���Ѵ�.
        isFind = true;
        return;
    }

    // ó������ vector�� ������� ������ ������, �׷��� ������ ��Ʈ��ŷ �Լ��� �� ����������.
    // �� 15���� ��⿡�� �ºٴ� �� ���� �̸� ����Ͽ� ��Ʈ��ŷ �Լ������� ������ ��븸�Ѵ�.
    int first = vs[num].first;
    int second = vs[num].second;

    // first�� �̰��� ���.
    ++cur[first][0];
    ++cur[second][2];
    BackTrack(num + 1);
    --cur[first][0];
    --cur[second][2];

    // ����� ���.
    ++cur[first][1];
    ++cur[second][1];
    BackTrack(num + 1);
    --cur[first][1];
    --cur[second][1];

    // second�� �̰��� ���.
    ++cur[first][2];
    ++cur[second][0];
    BackTrack(num + 1);
    --cur[first][2];
    --cur[second][0];
}

void MakeAnswer()
{
    // ����Ѵ�� �� 15���� ��⿡�� �º��� �� ���� �̸� ����صд�.
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            vs.push_back(make_pair(i, j));
    for (int iter = 0; iter < 4; ++iter)
    {
        isFind = false;
        sum = 0;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
            {
                cin >> board[i][j];
                sum += board[i][j];
            }

        // �� ��Ⱑ 15���̹Ƿ� ��� ������ ���� 30�� ���;� �Ѵ�.
        // ����ġ��.
        if (sum != 30)
        {
            cout << 0 << '\n';
            continue;
        }
        BackTrack(0);
        if (isFind)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}