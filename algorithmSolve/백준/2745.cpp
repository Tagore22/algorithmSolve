#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 진법 변환의 과정을 그대로 구현하면 된다. 10진법 수 5를 2진법으로 변환하면
// 101이 된다. 어떻게 변환하였는가? 2로 나누며 나머지를 모아두면 된다.
// 따라서 이걸 역으로 사용하여 B진법을 만들면 된다. 0의 자리부터 주어진 수와
// B의 i제곱을 곱하여 그 수들을 모두 더하면 된다.

// 자세한 설명은 주석으로 남긴다.

string str;
int B;

void MakeAnswer()
{
    // 현재 자리수, string에서 int로 변환하기 위해 빼야할 수, 최종답.
    int idx = 0, minus, answer = 0;
    // 0의 자리인 맨뒤부터 0번째 원소까지 순회한다.
    for (int i = str.size() - 1; i >= 0; --i)
    {
        // 현재 수가 숫자라면 48을 빼서 수로 만들면 된다.
        if ('0' <= str[i] && str[i] <= '9')
            minus = 48;
        // 알파벳 대문자라면 55를 빼서 'A'가 10으로 시작하게 하면 된다.
        else
            minus = 55;

        // B의 현재 자리수 제곱 * 현재 수를 곱하여 최종답에 더하면 된다.
        answer += pow(B, idx) * (str[i] - minus);
        // 자리수 증가.
        ++idx;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}