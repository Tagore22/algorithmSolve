#include <iostream>

using namespace std;

int board[20];
int N;

int Calcul(int who, int cost)
{
    int value = 0;
    for (int i = 0; i < N; ++i)
        value += board[i] / who * cost + cost;
    return value;
}

void MakeAnswer()
{
    int Y = Calcul(30, 10);
    int M = Calcul(60, 15);

    if (Y < M)
        cout << "Y " << Y << '\n';
    else if (Y == M)
        cout << "Y M " << Y << '\n';
    else
        cout << "M " << M << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}