#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            answer += str[i] - 96;
        else
            answer += str[i] - 38;
    }
    int sqrtnum = sqrt(answer);
    bool isprime = true;
    for (int i = 2; i <= sqrtnum; ++i)
        if (answer % i == 0)
        {
            isprime = false;
            break;
        }
    cout << (isprime ? "It is a prime word." : "It is not a prime word.") << '\n';
    return 0;
}