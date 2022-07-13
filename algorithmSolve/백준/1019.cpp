#include <iostream>

using namespace std;

int N, MultiNum;
int board[10];

void TransNum(int num)
{
    while (num > 0)
    {
        board[num % 10] += MultiNum;
        num /= 10;
    }
}

void CheckFirst()
{
    for (int i = 1; i <= N; ++i)
        ++board[i];
    for (int i = 0; i < 10; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Calcul(int from, int to)
{
    while (from % 10 != 0 && from <= to)
    {
        TransNum(from);
        ++from;
    }
    if (from > to) return;

    while (to % 10 != 9 && to >= from)
    {
        TransNum(to);
        --to;
    }

    int ans = to / 10 - from / 10 + 1;
    for (int i = 0; i < 10; ++i)
        board[i] += ans * MultiNum;

    MultiNum *= 10;
    Calcul(from / 10, to / 10);
}

void MakeAnswer()
{
    if (N < 10)
    {
        CheckFirst();
        return;
    }
    Calcul(1, N);
    for (int i = 0; i < 10; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    MultiNum = 1;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}