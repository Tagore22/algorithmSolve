#include <iostream>

using namespace std;

int main()
{
    int N;
    string s;
    cin >> N >> s;
    for (int i = 0; i < N; ++i)
        if (s[i + 1] == 'J')
            cout << s[i] << '\n';
    return 0;
}