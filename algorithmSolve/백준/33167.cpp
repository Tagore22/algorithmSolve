#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string str1, str2;
    cin >> str1 >> str2;

    int first = 0, second = 0;
    for (int i = 0; i < N; ++i)
    {
        if (str1[i] == 'R')
        {
            if (str2[i] == 'P')
                ++second;
        }
        else
        {
            if (str2[i] == 'R')
                ++second;
            else
                ++first;
        }
    }
    cout << first << ' ' << second;
    return 0;
}