#include <iostream>

using namespace std;

// 풀이.
// 주어진 문자열이 패턴과 일치하는지 확인하는 문제다.
// *은 빈문자가 될수도, 어떠한 문자열이 될수도 있다. 따라서 패턴의 현재 문자가 *일때 다음과 같은 경우의 수가 존재한다.

// *일때

// 1. *을 빈칸으로 무시하고 패턴의 다음으로 넘어감.
// 2. *과 str의 다음으로 같이 넘어감.
// 3. *에 str의 현재 문자를 흡수하고 str만 넘어감.

// 따라서 패턴의 현재 문자가 *인지 확인하고 그렇다면 위의 경우의 수를, 그렇지 않다면
// 단순 현재 패턴의 문자와 str의 문자를 비교하며 마지막 문자까지 순회하면 된다.
// 모든 순회중 단 한번이라도 true가 된다면 올바른 패턴이다.

// 자세한 설명은 주석으로 남긴다.

string pat, str;
int N;

// 두 문자열의 모든 경우를 순회하는 함수.
bool ComposePatten(int pat_idx, int str_idx)
{
    // 두 문자열이 모두 끝까지 순회했다면 올바른 패턴이다.
    if (pat_idx >= pat.size() && str_idx >= str.size())
        return true;
    // 두 문자열중 하나만 끝까지 순회했다면 올바른 패턴이 아니다.
    if (pat_idx >= pat.size() || str_idx >= str.size())
        return false;

    bool ans = false;
    // 현재 패턴의 문자가 *일때 상술한 3가지 경우의 수를 모두 순회한다.
    if (pat[pat_idx] == '*')
    {
        // 1. *이 빈문자로 여기고 패턴만 다음 문자로 넘어간다.
        ans |= ComposePatten(pat_idx + 1, str_idx);
        // 2. *이 현재 문자까지만 흡수하고 둘다 다음 문자로 넘어간다.
        ans |= ComposePatten(pat_idx + 1, str_idx + 1);
        // 3. *이 현재 문자도 흡수하고 str만 다음 문자로 넘어간다.
        ans |= ComposePatten(pat_idx, str_idx + 1);
    }
    // 현재 문자가 *이 아닐때
    else
    {
        // 단순히 두 문자가 같을때에만 다음으로 넘어갈수 있다.
        if (pat[pat_idx] == str[str_idx])
            ans |= ComposePatten(pat_idx + 1, str_idx + 1);
    }
    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        cout << (ComposePatten(0, 0) ? "DA" : "NE") << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> pat;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}