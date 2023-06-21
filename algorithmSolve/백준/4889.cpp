#include <iostream>

using namespace std;

// 풀이.
// 이 문제는 조건식이 중요하다. 현재값이 { 일때와 } 일때의 조건식이다.
// 문자열 str을 순회하며, 여태까지 }이 나왔던 값을 end라고 할때

// 1. 현재값이 { 일때 end를 1 감소시킨다.
// 1-1. end가 음수일때 {이 }보다 더 먼저 나온 경우이므로, 현재값을 }로 바꾸고 end를 2 증가시켜 }이 한개 나온상황으로 바꾼고 최종값을
// 1 증가시킨다.
// 1-2. 그렇지 않은 경우 무시한다.
// 2. 현재값이 } 일때 end를 1 증가시킨다.
// 3. 순회의 끝에서 end값이 0보다 크다면 }이 더 많이 나온 경우이므로 이것들의 절반을 {로 바꾸어 짝을 맞춰주어야 하기에
// end값을 2로 나누어 그 값을 최종값에 더한다.

string str;

int Check()
{
    int end = 0, ans = 0;

    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == '{')
        {
            --end;
            if (end < 0)
            {
                ++ans;
                end += 2;
            }
        }
        else
        {
            ++end;
        }
    }

    if (end > 0)
        ans += end / 2;

    return ans;
}

void MakeAnswer()
{
    int idx = 0, answer;
    while (true)
    {
        ++idx;
        cin >> str;
        if (str[0] == '-')
            break;
        // 여기서 검사.
        answer = Check();
        cout << idx << ". " << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}