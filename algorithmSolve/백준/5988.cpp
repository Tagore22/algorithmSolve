#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        int num = str[str.size() - 1] - '0';
        if (num % 2 == 0)
            cout << "even" << '\n';
        else
            cout << "odd" << '\n';
    }
    return 0;
}