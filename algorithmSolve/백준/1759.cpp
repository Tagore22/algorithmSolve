#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��
// ���ĺ� ���� C���� ���� L���� ��ȣ�� ������ �ϴµ�, ��ȣ�� ������ 3�����̴�.
//
// 1. ������ �ּ� 1�� �̻��̴�.
// 2. ������ �ּ� 2�� �̻��̸�.
// 3. ������������ ���ĵǾ��ִ�.
// 
// ��� �Լ��� �ݺ��ϸ� ����� �ִ� ��� ���ڿ��� �� ���ǿ� �����ϴ� ���ڿ����� ���� vector�� ��� ����ϸ� �ȴ�.

vector<string> answer;
string board = "";
int L, C;

// ���� �־��� ���ڿ��� ��ȣ�� ���ǿ� �����ϴ����� Ȯ���ϴ� �Լ�. ������ ������ ������ Ȯ����.
bool CheckStr(string& cur)
{
    int mo = 0, ja = 0;
    for (int i = 0; i < cur.size(); ++i)
    {
        if (cur[i] == 'a' || cur[i] == 'e' || cur[i] == 'i' || cur[i] == 'o' || cur[i] == 'u')
            ++mo;
        else
            ++ja;
    }

    return mo >= 1 && ja >= 2 ? true : false;
}


// ����� �ִ� ��� ���ڿ��� ��ͷ� ������. 
void CalStr(int idx, string cur)
{
    if (idx != -1)
        cur += board[idx];

    if (idx >= C)
        return;

    if (cur.size() == L)
    {
        if (CheckStr(cur))
            answer.push_back(cur);
        return;
    }

    for (int i = idx + 1; i < C; ++i)
        CalStr(i, cur);
}

void MakeAnswer()
{
    sort(board.begin(), board.end());
    CalStr(-1, string(""));
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    char cha;
    for (int i = 0; i < C; ++i)
    {
        cin >> cha;
        board += cha;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}