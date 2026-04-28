#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        int idx = str.size() / 2;
        cout << (str[idx - 1] == str[idx] ? "Do-it" : "Do-it-Not") << '\n';
    }
    return 0;
}