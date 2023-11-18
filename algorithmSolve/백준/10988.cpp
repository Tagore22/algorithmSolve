#include <iostream>

using namespace std;

// 풀이.
// 주어진 문자열이 팰린드롬인지 확인하는 문제다. 즉 문자열의 가장 중간부분까지 맨 앞과 맨 뒤를 확인
// 하면 되는데 그 중간부분은 문자열의 길이 / 2로 구할수 있다.

// 자세한 설명은 주석으로 남긴다.

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    int sSize = str.size();
    bool isFind = true;
    // 문자열의 중간부분(문자열의 길이 / 2)전까지 순회하며 확인한다.
    for (int i = 0; i < sSize / 2; ++i)
    {
        // 중간을 기준으로 앞뒤를 확인할때 다른 부분이 존재한다면 팰린드롬이 아니다.
        if (str[i] != str[sSize - 1 - i])
        {
            isFind = false;
            break;
        }
    }

    cout << isFind ? 1 : 0 << '\n';
    return 0;
}