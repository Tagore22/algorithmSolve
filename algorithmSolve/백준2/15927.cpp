#include <iostream>

using namespace std;

// 풀이.
// 처음에는 엄청 복잡하게 느껴졌는데 잘 생각하면 굉장히 단순한 문제이다.
// 총 3가지 경우가 존재하게 된다.

// 1. 모든 글자가 같을때. 모든 부분문자열이 팰린드롬이 되기에 -1을 출력한다.
// 2. 모든 글자가 같지는 않으나 주어지는 문자열이 팰린드롬일 때. 맨 마지막 혹은 맨 처음
// 글자를 제외하면 팰린드롬이 아니게 된다.
// 3. 주어지는 문자열이 팰린드롬이 아닐 때. 그 자체가 가장 긴 부분문자열이 된다.

// 따라서 모든 글자가 같은지, 주어지는 문자열이 팰린드롬인지만 확인하면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    bool issame = true;
    int ssize = str.size();
    // 상술한 1번. 모든 문자가 같은가?
    for (int i = 1; i < ssize; ++i)
    {
        if (str[i] != str[i - 1])
        {
            issame = false;
            break;
        }
    }
    // 모든 부분문자열이 팰린드롬이 되기에 -1을 출력한다.
    if (issame)
    {
        cout << -1 << '\n';
        return 0;
    }
    bool ispal = true;
    // 상술한 2번. 주어진 문자열이 팰린드롬인가?
    for (int i = 0; i < ssize / 2; ++i)
    {
        if (str[i] != str[ssize - 1 - i])
        {
            ispal = false;
            break;
        }
    }
    // 팰린드롬이라면 맨 앞글자 혹은 맨 뒷글자를 제외하면 팰린드롬이 아니게 되기에
    // 문자열의 길이 -1을, 팰린드롬이 아니라면 그 자체로 가장 긴 부분문자열이기 때문에
    // 문자열의 길이를 출력한다.
    cout << (ispal ? ssize - 1 : ssize) << '\n';
    return 0;
}