#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ó������ ���������� �񿡼� ����� ������� �����ؼ�
// ���� �������� �����Ҽ� �ִ� ���� �� ����� �������� �����ϴ� ������� �Ͽ�����,
// ���� �������� �������� �� ����� ������ ���� ���� ���ư��� �ϴ� ��쵵 �־���.

// 1
// 4
// 2000 0
// 1000 0
// 0 0
// 0 1000
// 0 2000
// 1000 2000

// �̷� ��찡 �׷��ߴ�. �� �׸���δ� Ǯ�� ���� �׷����� ����Ͽ� Ǯ����ߴ�.
// �׷��� �ٲ� ������ ���� �������� �־��� ���������� �����Ҽ� �ִ� �������� �����Ͽ�
// �� ���������� �� �����Ҽ� �ִ��� Ȯ���ϰ� �����Ѵٸ� happy�� ����ϰ�
// �׷��� ���ٸ� �Ǵٽ� �����Ҽ� �ִ� �������鿡 �����ϴ� ���� �ݺ��ϴ� BFS����̴�.

// �ڼ��� ������ �ּ��� ÷����.

// ���������� ��ǥ�� ������, ������.
pair<int, int> board[100];
pair<int, int> cur, goal;
int T, N;
const int DIST = 1000;

// �� ��ǥ�� �Ÿ��� ��ȯ�ϴ� �Լ�.
int CalDist(pair<int, int> lhs, pair<int, int> rhs)
{
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

// ���� �������� ����� �����Ҽ� �ִ°��� ��ȯ�ϴ� �Լ�.
bool BFS()
{
    queue<pair<int, int>> que;
    que.push(cur);
    bool visit[100];
    memset(visit, false, sizeof(visit));

    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        // ������������ ����� �����Ҽ� �ִٸ� true�� ����Ѵ�.
        if (CalDist(now, goal) <= DIST)
            return true;

        // ��� ���������� ���� �湮���� �ʾ����� �����Ҽ� �ִ� �������� �����Ѵ�.
        for (int i = 0; i < N; ++i)
            if (!visit[i] && CalDist(now, board[i]) <= DIST)
            {
                visit[i] = true;
                que.push(board[i]);
            }
    }

    // �ᱹ �� �������� ���ߴٸ� false�� ��ȯ�Ѵ�.
    return false;
}

void MakeAnswer() // �������� �� ���� ��� �� �־����� ������ ���ư����Ҽ��� �ִ�.
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cin >> cur.first >> cur.second;
        for (int j = 0; j < N; ++j)
            cin >> board[j].first >> board[j].second;
        cin >> goal.first >> goal.second;

        bool answer = BFS();

        cout << (answer ? "happy" : "sad") << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}