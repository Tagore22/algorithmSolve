#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 1342번의 더 빠른 풀이. next_permutation()을 이용하여 모든 문자열의 조합을
// 더 빠르게 구현할 수 있다.

string str;
int answer;

bool IsLuckyStr()
{
    for (int i = 0; i < str.size() - 1; ++i)
        if (str[i] == str[i + 1])
            return false;
    return true;
}

int main()
{
    cin >> str;
    sort(str.begin(), str.end());
    answer = IsLuckyStr() ? 1 : 0;
    while (next_permutation(str.begin(), str.end()))
    {
        if (IsLuckyStr())
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}