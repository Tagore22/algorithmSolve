#include <iostream>

using namespace std;

int T, P;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> P;
        pair<int, string> answer = make_pair(-1, "");
        pair<int, string> cur;
        for (int i = 0; i < P; ++i)
        {
            cin >> cur.first >> cur.second;
            if (cur.first > answer.first)
                answer = cur;
        }
        cout << answer.second << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}