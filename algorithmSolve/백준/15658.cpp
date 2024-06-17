#include <iostream>
#include <set>
#include <string>

using namespace std;

// Ǯ��.
// 15658���� ���� �ָԱ����� ���� Ǯ�̴�. ��������� ��Ʈ��ŷ�� �̿��� ��� ����� �����غ��� ���ε�
// �ߺ��� ���� ó���ϱ� ���ؼ� set<>�� ����Ͽ���. ������ �ֽô��� �־��� N�� �ִ� 11�̱� ������
// ������ set�� ����ϴ°��� �� �������� ����� ����. ���� ���ʿ��� ������� �ʹ� ����.
// �������� ��� �����ϴµ� �;��� �װڴ�. ��¥���� -_-
// �׷��� ��� Ǯ������� ���� �Ѱ�� �����ε� ������ Ǯ� �����̴�.

int board[11], oper[4];
int N, min_ans = 1000000001, max_ans = -1000000001;
set<string> check;

void CalMinMax(string cur)
{
    int ans = board[0];
    for (int i = 0; i < cur.size(); ++i)
    {
        if (cur[i] == '0')
            ans += board[i + 1];
        else if (cur[i] == '1')
            ans -= board[i + 1];
        else if (cur[i] == '2')
            ans *= board[i + 1];
        else
            ans /= board[i + 1];
    }
    min_ans = min(min_ans, ans);
    max_ans = max(max_ans, ans);
}

void BackTrack(string cur)
{
    if (cur.size() == N - 1)
    {
        if (check.find(cur) == check.end())
        {
            CalMinMax(cur);
            check.insert(cur);
            return;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (oper[i] > 0)
        {
            --oper[i];
            BackTrack(cur + to_string(i));
            ++oper[i];
        }
    }
}

void MakeAnswer()
{
    BackTrack(string(""));
    cout << max_ans << '\n';
    cout << min_ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    for (int i = 0; i < 4; ++i)
        cin >> oper[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}