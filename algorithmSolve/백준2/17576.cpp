#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int N, from = 0, to = 0;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int a, b;
        cin >> a >> b;
        from += a;
        to = b;
    }
    cout << str.substr(from, to) << '\n';
    return 0;
}