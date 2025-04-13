#include <iostream>

using namespace std;

int N, M, J;

void MakeAnswer()
{
    int from = 1, to = M, answer = 0;
    for (int iter = 0; iter < J; ++iter)
    {
        int num;
        cin >> num;
        if (num > to)
        {
            int plus = num - to;
            answer += plus;
            to += plus;
            from += plus;
        }
        else if (num < from)
        {
            int minus = from - num;
            answer += minus;
            to -= minus;
            from -= minus;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> J;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}