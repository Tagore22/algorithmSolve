#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int DDAY = 90;
    int N, answer = 0;
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        string trans = str.substr(2, str.size() - 2);
        if (stoi(trans) <= DDAY)
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}