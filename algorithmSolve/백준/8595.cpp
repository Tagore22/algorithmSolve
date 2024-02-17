#include <iostream>

using namespace std;

// 풀이.
// 문자열을 순회하며 숫자들을 찾는 문제다. 각 숫자는 문자로 나뉘어져 있기 때문에 숫자 다음 문자를
// 만났을때 기존의 구해놓은 숫자들을 더하면 된다.

string str;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> str;
    long long answer = 0, cur = 0;
    for (int i = 0; i < N; ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            cur *= 10;
            cur += str[i] - '0';
        }
        else
        {
            answer += cur;
            cur = 0;
        }
    }
    answer += cur;
    cout << answer << '\n';
    return 0;
}