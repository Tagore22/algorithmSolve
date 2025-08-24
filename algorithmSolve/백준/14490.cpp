#include <iostream>
#include <string>

using namespace std;

int gcd(int first, int second)
{
    if (second == 0)
        return first;
    return gcd(second, first % second);
}

int main()
{
    string str;
    cin >> str;

    int idx;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ':')
        {
            idx = i;
            break;
        }
    }

    int first = stoi(str.substr(0, idx));
    int second = stoi(str.substr(idx + 1));
    int div = gcd(first, second);
    cout << first / div << ':' << second / div << '\n';
    return 0;
}