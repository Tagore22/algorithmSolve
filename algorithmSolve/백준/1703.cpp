#include <iostream>

using namespace std;

void MakeAnswer()
{
    int num;
    while (true)
    {
        cin >> num;
        if (num == 0)
            break;
        int s, c, answer = 1;
        for (int i = 0; i < num; ++i)
        {
            cin >> s >> c;
            answer *= s;
            answer -= c;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}