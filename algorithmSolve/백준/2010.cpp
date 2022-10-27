#include <iostream>

using namespace std;

int N;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        int a;
        cin >> a;
        answer += a - 1;
    }

    int a;
    cin >> a;
    answer += a;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}