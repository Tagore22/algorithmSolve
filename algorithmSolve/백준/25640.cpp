#include <iostream>

using namespace std;

string jinho;
int N;

void Solve()
{
    string str;
    int answer = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        if (str == jinho)
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> jinho >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}