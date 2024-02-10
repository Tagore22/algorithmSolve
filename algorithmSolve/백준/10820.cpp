#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 문자열의 개수가 주어지지 않았기에 while문을 사용해야했고, 공백을 포함한 문자열을 입력받기에
// getline()을 이용해야했다. 문자열을 입력받은 후에는 각각 대문자, 소문자, 숫자, 공백의 수를 구하여
// 출력한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while (getline(cin, str))
    {
        int upper = 0, lower = 0, dig = 0, space = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
                ++space;
            else if ('0' <= str[i] && str[i] <= '9')
                ++dig;
            else if ('a' <= str[i] && str[i] <= 'z')
                ++lower;
            else if ('A' <= str[i] && str[i] <= 'Z')
                ++upper;
        }
        cout << lower << ' ' << upper << ' ' << dig << ' ' << space << '\n';
    }
    return 0;
}