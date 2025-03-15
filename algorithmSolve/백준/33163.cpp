#include <iostream>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N >> str;
    for (int i = 0; i < N; ++i)
    {
        if (str[i] == 'J')
            str[i] = 'O';
        else if (str[i] == 'O')
            str[i] = 'I';
        else
            str[i] = 'J';
    }
    cout << str << '\n';
    return 0;
}