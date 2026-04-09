#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string str;

    cin >> N >> str;
    int answer = 0;
    for (int i = 0; i < N / 2; ++i)
        if (str[N - i - 1] != str[i])
            ++answer;
    cout << answer << '\n';
    return 0;
}