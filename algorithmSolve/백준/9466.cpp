#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Ǯ��
// ���Ϸ� ȸ�ο� ����� DFS�����̴�.
// 1������ N������ ��ȸ�ϸ� ����Ŭ�� �����ϴ����� Ȯ���Ѵ�. �ٸ� �ļ��ϵ��� �̹� Ȯ���غ� �л��� if������ ���ܵȴ�.

// 2���� bool �迭�� ����ߴµ� visit�� ���� DFS ��ȸ�� �湮�Ͽ������� �����̰�, check�� �ش� �л��� DFS ��ȸ�� ���������� ���� �����̴�.
// ��, visit�� �̹� DFS ��ȸ�� ���� �л����� �����ϸ�, check�� ��ȸ�� ����� �л����� �����Ѵ�.
// ����Ŭ�� ���δ� ���� DFS ��ȸ�� ������� ���� �л��� �̹� ��ȸ���� �ٽ� ������ ����̴�. ���ø� ����

// 1���� 2����, 2���� 3����, 3���� 4����, 4���� 2���� ����Ų�ٰ� ġ��. 1���� ������ 2 ~ 4���� ����Ŭ�� �̷�� �ִ�.
// 1�� �л����� DFS��ȸ�� �����Ͽ� 1 -> 2 -> 3 -> 4���� ��ȸ�ϰ� 4������ �ٽ� 2���� �湮�ϰ� �Ǵµ�
// 2���� �̹� �湮�� �л��̴�. ������ 2���� DFS ��ȸ�� ������� �ʾҴ�. �׷��⿡ 2 ~ 4���� ����Ŭ�� �̷��
// 4���� ���� ~ 4�������� �л����� ����Ŭ�� �̷��(2, 3, 4). 
// �ռ� ã�Ƴ� ����Ŭ�� �̷�� �л����� ����ŭ�� N���� �����ϰ�, 1 ~ 4���� �л��� ���̻� �湮�� ���ʿ�������
// check�� false�� �������ش�. �� ������ ���ݴ� �ڼ��� �������ڸ� �翬�ϰ�����, 1 ~ 4���� �л��鿡�� �ٸ� �л���� ���� ����
// ���� �����̴�. ���� ���� �ִ� ���� �־��ٸ� DFS ��ȸ�� ���� �湮�Ͽ��� ���̴�. �׷��⿡ 1 ~ 4���� �л����� DFS��ȸ�� �ʿ��������.
// �ݴ�� � �л� K�κ��� 1 ~ 4���� �ƹ� �л����Ե� ���±��� �ִٰ� �ϴ��� 1 ~ 4������ K�� ���� ���� �����ٴ� ���̱⿡ ����Ŭ�� 
// �����Ҽ��� ���⿡ �����ص� �ȴ�.

int board[100001];
bool check[100001], visit[100001];
int T, N, answer;

void DFS(int start, vector<int>& path)
{
    if (board[path.back()] == start)
    {
        answer -= path.size();
        for (auto n : path)
            visit[n] = true;
        return;
    }

    if (check[path.back()])
        return;

    check[path.back()] = true;
    path.push_back(board[path.back()]);
    DFS(start, path);
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        answer = N;
        memset(visit, false, sizeof(visit));
        for (int j = 1; j <= N; ++j)
            cin >> board[j];
        for (int j = 1; j <= N; ++j)
            if (!visit[j])
            {
                memset(check, false, sizeof(check));
                vector<int> path(1, j);
                DFS(j, path);
            }
        cout << answer << '\n';
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