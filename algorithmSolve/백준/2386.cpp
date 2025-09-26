#include <iostream>
#include <string>

using namespace std;

int main()
{
    char c;
    string str;
    while (true)
    {
        cin >> c;
        if (c == '#')
            break;
        cin.ignore();
        getline(cin, str);
        int answer = 0;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == c || str[i] == c - 32)
                ++answer;
        cout << c << ' ' << answer << '\n';
    }
    return 0;
}