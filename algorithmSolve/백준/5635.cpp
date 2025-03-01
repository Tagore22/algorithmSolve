#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ����ü�� �ϳ� ����� ��������� �������� �����Ͽ� ù��°�� ������ ������ �̸��� ����ϸ� �ȴ�.

struct man
{
    int year;
    int month;
    int day;
    string name;
};

man board[100];
int N;

bool SortMan(const man& lhs, const man& rhs)
{
    if (lhs.year != rhs.year)
        return lhs.year < rhs.year;
    else if (lhs.month != rhs.month)
        return lhs.month < rhs.month;
    else if (lhs.day != rhs.day)
        return lhs.day < rhs.day;
    else
        return false;
}

void MakeAnswer()
{
    sort(board, board + N, SortMan);
    cout << board[N - 1].name << '\n';
    cout << board[0].name << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].name >> board[i].day >> board[i].month >> board[i].year;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}