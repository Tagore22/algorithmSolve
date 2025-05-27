#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ����� ���� ���������� ������ ������ �߸� �����ؼ� ������ ���� Ʋ�� ���� ���� ã�Ҵ�.
// ���� ���� ������ ��ȸ�ϸ� ���ڿ��� �ٲ��� pair<>�� �־� ������ �ϰ�
// 10������ ��� ����ϸ� �ȴ�.

const int MAX = 100;
pair<string, int> board[MAX];
string alpha[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int M, N;

void CheckStr(int num)
{
    string str = "";
    int idx = num;
    while (num >= 0)
    {
        int cur = num >= 10 ? num / 10 : num;
        str += alpha[cur];
        num = num >= 10 ? num % 10 : -1;
    }
    board[idx] = { str, idx };
}

void Solve()
{
    for (int i = M; i <= N; ++i)
        CheckStr(i);
    sort(board + M, board + N + 1);
    int jump = 0;
    for (int i = M; i <= N; ++i)
    {
        cout << board[i].second << ' ';
        ++jump;
        if (jump == 10)
        {
            cout << '\n';
            jump = 0;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}