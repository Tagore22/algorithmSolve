#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    string str;
    cin >> N >> str;
    for (int i = N - 5; i < N; ++i)
        cout << str[i];
    cout << '\n';
    return 0;
}