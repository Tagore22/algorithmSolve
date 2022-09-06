#include <iostream>

using namespace std;

int N, M;

void MakeAnswer()
{
    cout << N - 1 + N * (M - 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}