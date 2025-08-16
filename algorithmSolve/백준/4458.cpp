#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        getline(cin, str);
        str[0] = str[0] >= 'a' ? str[0] - 32 : str[0];
        cout << str << '\n';
    }
    return 0;
}