#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� �ִ� ��� ������ ������������ ����ϴ� �����̴�.
// �������� ��Ʈ��ŷ �����ν� ��� ���յ��� ��ȸ�ϸ� �ȴ�.
// �ٸ� bool �迭�� �ϳ� �ξ �ߺ����� ���Ǵ� ���� ���ƾ� �Ѵ�.
// �ӵ��� ���� �������� ���� �ʾ� �־� �������� Ǯ�̷� Ǯ��� ã�ƺ�������,
// �� �׷��� �ñ⿡ ���� �ӵ� ���̰� �ִ� �� ���Ҵ�. �׳� �Ű澲������.

// �ڼ��� ������ �ּ����� �����.

int board[8];
bool visit[8];
vector<int> ans;
int N, M;

// ��� ������ ��ȸ�غ��� �Լ�.
void BackTrack()
{
    // ���Ϳ� �� ���� ������ M����� ����Ѵ�.
    if (ans.size() == M)
    {
        for (auto n : ans)
            cout << n << ' ';
        cout << '\n';
        return;
    }

    // ���� ���� ������ ��������� �ִ��� Ȯ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // ������ ������ �ʾҴ� ����� ����Ѵ�.
        if (!visit[i])
        {
            ans.push_back(board[i]);
            visit[i] = true;
            BackTrack();
            ans.pop_back();
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    // ���� ���������� ������� ���� ���������� ����ؾ� �ϱ⿡ ������������ �����Ѵ�.
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
    BackTrack();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}