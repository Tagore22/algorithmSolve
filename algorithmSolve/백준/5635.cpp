#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 구조체를 하나 만들어 생년월일을 기준으로 정렬하여 첫번째와 마지막 순서의 이름을 출력하면 된다.

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