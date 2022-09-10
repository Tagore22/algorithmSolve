#include <iostream>

using namespace std;

pair<int, int> board[100000];
int N, K;

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

void ShowAnswer()
{
    cout << "ºñ¿ÍÀÌ" << '\n';
}

int main()
{
    Input();
    ShowAnswer();
    return 0;
}