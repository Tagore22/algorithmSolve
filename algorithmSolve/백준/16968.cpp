#include <iostream>

using namespace std;

// 풀이.
// 여러가지 조합중 어떤 두문자가 중복되지 않는 모든 경우의 수를 구하는 문제다.
// 현재수 * 경우의 수를 해놓고 만약 이전에도 현재와 같은 문자 혹은 숫자였다면
// 이전값을 빼주는 방식이다. 하지만 역으로 답을 구하는 주먹구구식의 풀이라
// 다시 떠올려보라고 하면 못할것 같다. 진짜 내 풀이는 이 다음에 있다.

// 자세한 설명은 주석으로 남긴다.

string str;
const int c = 26, d = 10;

int main()
{
    cin >> str;

    int answer = 1, prev;
    for (int i = 0; i < str.size(); ++i)
    {
        // 1. 현재값 = 이전값 * 현재의 경우의 수.
        // 2. 만약 현재 문자(c or d)가 이전 문자와 같다면 현재값에서 이전값을 제외한다.
        prev = answer;
        answer = str[i] == 'c' ? answer * c : answer * d;
        answer = i != 0 && str[i] == str[i - 1] ? answer - prev : answer;
    }

    cout << answer << '\n';
    return 0;
}