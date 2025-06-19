#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        getline(cin, str);
        cout << str;
        if (str[str.size() - 1] != '.')
            cout << '.' << '\n';
        else
            cout << '\n';
    }
    return 0;
}