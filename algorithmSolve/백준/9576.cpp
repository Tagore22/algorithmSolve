#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��
// ��û���� �����Ͽ� �ټ� �ִ� ���� ���� å�� ���� ���ϴ� �����̴�.
// ó������ ��û���� ������ �������� ��Ƽ� ������ ���Ͽ���, �����غ��� ������ �տ��� �ֱ� ������
// ��û���� ������ ���� ������ ������ �Ͽ��� �տ������� �ִ��� ���� ���� å�� �ټ� �ֱ� ������
// �ٽ� ����, ���� ���� �ƴ� ��û���� ������ �������� �����ؾ��ߴ�. ���� ������ ���ٸ� ���۰��� ���������� �����Ѵ�.
// ���� ��û���� ���۰����� �������� ��ȸ�Ͽ� �ټ� �ִ� å�� ���� üũ�Ͽ� �� �׽�Ʈ ���̽����� ����ϸ� �ȴ�.

// P.S �� �ڽ��� ���ظ� ���� ��� �ϱ� ���� �߰��Ѵ�.
// �⺻������ ������ ���� ��û���� �л����� �켱������ å�� �־�� �ϴµ�, ������ ��û���� ���� - ���۰��̶�� �����Ҽ� ������
// �����δ� �׷��� �ʴ�. �տ�������(1��å����) å�� �ֱ� ������ ���� ��ü�� ������ �ȴ�. �׷��� ���۰��� ������� ��������
// �������� �Ͽ� �����ϸ� �ȴ�.

vector<pair<int, int>> board;
int T, N, M;

bool CompareFunc(pair<int, int> lhs, pair<int, int> rhs)
{
    if (lhs.second != rhs.second)
        return lhs.second < rhs.second;
    else
        return lhs.first < rhs.first; // ���۰��� ������⿡ ���� �Ű澲�� �ʾƵ� �ȴ�.
}

void CalAnswer()
{
    sort(board.begin(), board.end(), CompareFunc);
    vector<bool> check(N + 1, true);
    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = board[i].first; j <= board[i].second; ++j)
            if (check[j])
            {
                ++answer;
                check[j] = false;
                break;
            }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        int from, to;
        board.clear();
        for (int j = 0; j < M; ++j)
        {
            cin >> from >> to;
            board.push_back(make_pair(from, to));
        }
        CalAnswer();
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