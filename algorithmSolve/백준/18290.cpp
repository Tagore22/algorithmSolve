#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������� 30�ۼ�Ʈ�� �ȵǴ¸�ŭ ���� ���� ��������.
// ���� ��ü�� �ִ� 100���� ĭ�߿��� �������� �ʴ� �ִ� 4���� ĭ�� ���� �� �ִ밪�� ����ϴ� ������ ������.
// �� Ǯ�̿����� �Ź� ���� ĭ ���ķ� ��ȸ�ϸ� ���� ĭ�� ���±��� �� ĭ�鿡 �������� �ʴ´ٸ� ��󰡸鼭
// K���� ������� �� �ִ밪�� ����Ͽ���. ������ �ٸ� �� ���� Ǯ�̰� �����ߴ�. �ʹ� ����� ������� �����Ѱ� ����.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> points;
int board[10][10];
int N, M, K;

// ����ĭ y, x�� ���±��� �� ĭ�鿡 �����ϴ��� Ȯ���ϴ� �Լ�.
bool CheckPoints(int y, int x)
{
    for (int i = 0; i < points.size(); ++i)
    {
        if ((points[i].first == y + 1 && points[i].second == x) || (points[i].first == y - 1 && points[i].second == x) ||
            (points[i].first == y && points[i].second == x + 1) || (points[i].first == y && points[i].second == x - 1))
            return false;
    }
    return true;
}

// ��� ��ȸ�� �����ϴ� �Լ�.
int DFS(int y, int x, int num)
{
    // 1���� ���Ҵٸ� ���±��� �� ĭ���� ������ ��� ���ϰ� ���� ĭ�� ���� �߰��� ���� ��ȯ�Ѵ�.
    if (num == 1)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i)
            ans += board[points[i].first][points[i].second];

        return ans + board[y][x];
    }

    // ���� ĭ�� �����Ѵ�.
    points.push_back(make_pair(y, x));
    int ans = -49999;
    // ���� ĭ�� �̹� ������Ƿ� �� �� �ʿ� ���� 1ĭ �����ʿ��� �����Ѵ�.
    int from = x + 1;
    for (int i = y; i < N; ++i)
    {
        for (int j = from; j < M; ++j)
        {
            // ���� ĭ i, j�� ���±��� �� ĭ��� �������� �ʴ´ٸ� �����Ѵ�.
            if (!CheckPoints(i, j))
                continue;

            ans = max(ans, DFS(i, j, num - 1));
        }
        // �̹� ������ ��ȸ�ߴٸ� ó������ ��ȸ�ؾ� �ϱ⿡ from�� 0�� �ȴ�.
        from = 0;
    }
    // ���� ������ ĭ ����.
    points.pop_back();
    return ans;
}

void MakeAnswer()
{
    int answer = -50000;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            answer = max(answer, DFS(i, j, K));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}