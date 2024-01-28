#include <iostream>

using namespace std;

// 풀이.
// 본래 string의 정렬 기준에는 대소문자의 여부도 포함되는데 이 문제에는 대소문자의 구별이 없어야 하기 때문에
// 모든 문자를 대문자 혹은 소문자로 바꿔주어야 했다. 그 이후 각 문자열들을 비교하여 가장 사전순으로 앞의 문자열을
// 출력하면 된다. 한가지 새로 안것도 있는데 아스키 코드에서 대문자가 더 뒤에 있는줄 알았는데 오히려 소문자가 더 뒤에
// 있었다.

// 자세한 설명은 주석으로 남긴다.

int N;

void MakeAnswer()
{
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        string prev = "z", answer = prev;
        for (int i = 0; i < N; ++i)
        {
            string cur;
            cin >> cur;
            // 가장 앞서는 문자열을 변환 이전 상태로 출력해야 하기 때문에 복사해둔다.
            string now = cur;
            // 현재 문자열을 모두 소문자로 치환하여 비교한다.
            for (int j = 0; j < cur.size(); ++j)
                if ('A' <= cur[j] && cur[j] <= 'Z')
                    cur[j] += 32;
            if (cur < prev)
            {
                prev = cur;
                answer = now;
            }
        }
        cout << answer << '\n';
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