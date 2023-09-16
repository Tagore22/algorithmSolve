#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

// Ǯ��.
// ������� ������ �ϳ��� ��Ǯ� �� ��� ������.
// �� ������ �߿��� �κ��� �ߺ��� �����ε� �� �ߺ��� 2���� ��찡 �ִ�.

// 1. ���� ���� 2���� 1, 9�� 1, 9 ó�� �ΰ��� ���Ұ� ���� ���� ������ �־ �ߺ��� ����Ű�� ���.
// 2. 9, 9 ó�� ���� ���� ������ ������ �ߺ��� ������ �ʴ� ���.

// �� 2���� ��쿡�� �� ��̴�. �ϳ��� ���� ���� ���Ұ� ���������� �̹��� ����� �ڸ����� �������� �ִٸ� �ȵ�����
// �̹� ���� �Ѱ����� �� ���¿����� ����� ���� ���̴�.
// ���� ���ǹ��� �����ϴٰ� �ᱹ set�� ����ؼ� ����� �ִ� ��� ��츦 ���� �� �ߺ� �Ǵ� ��츦 �Ÿ���� �Ͽ���.

// �ڼ��� ������ �ּ����� �����.

int board[8];
set<string> check;
bool visit[8];
int N, M;

// ���ڿ��� ����ϴ� �Լ�.
void PrintAnswer(const string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            cout << ' ';
            continue;
        }

        cout << str[i] - '0';
    }
    cout << '\n';
}

// ����� �ִ� ��� ��츦 ����� �Լ�.
// ������ �ϳ��� string���� ���� ���� ��Ͷ� �ѱ��.
void BackTrack(int num, const string str)
{
    // M���� ���Ҹ� �������.
    if (num == M)
    {
        // ó�� ����������̶�� ����ϰ� set�� �����Ѵ�.
        if (check.find(str) == check.end())
        {
            PrintAnswer(str);
            check.insert(str);
        }
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!visit[i])
        {
            visit[i] = true;
            BackTrack(num + 1, str + to_string(board[i]) + " ");
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
    BackTrack(0, "");
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