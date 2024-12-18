#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에는 백트래킹을 사용해서 모든 경우를 찾아봤었다. 역시나 시간초과였다. 그리디 알고리즘을 사용해야 했는데
// 각 문자열들을 입력받으면서 알파벳별 등장한 자리수를 체크한다. 이후 자리수를 정렬하여 가장 큰 수부터 9 ~ 0을
// 곱해주면 된다. 다만, 문자열을 수로 변환했을때 0으로 시작하는 수는 존재하면 안되기에 맨 첫번째로 등장한 알파벳들은
// 0이 되면 안되기에 입력시 체크해두었다가 후에 문자별로 확인해야 한다.

// 자세한 설명은 주석으로 남긴다.

bool isfirst[10] = { false, };
pair<long long, int> alpha[10];
int N;

void MakeAnswer()
{
    sort(alpha, alpha + 10, greater<>());
    // 0이 등장하는 경우는 알파벳 10개가 모두 등장했을때이다.
    // 이때 맨 마지막 9번째 인덱스값은 무조건 0보다 커진다.
    if (alpha[9].first != 0)
    {
        // 가장 작은 수부터 순회하며 첫번째로 등장하지 않은 알파벳을 0으로 변환한다.
        for (int i = 9; i >= 0; --i)
        {
            if (!isfirst[alpha[i].second])
            {
                alpha[i].first = 0;
                break;
            }
        }
    }
    long long answer = 0;
    // 가장 큰 값부터 9 ~ 1을 곱하여 총합을 구한다.
    for (int i = 9; i >= 1; --i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (alpha[j].first == 0)
                continue;
            answer += alpha[j].first * i;
            alpha[j].first = 0;
            break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 10; ++i)
        alpha[i].second = i;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        // 각 문자열의 맨 앞 알파벳은 0이 되면 안되기에 미리 체크해둔다.
        isfirst[str[0] - 'A'] = true;
        long long here = 1;
        for (int j = str.size() - 1; j >= 0; --j)
        {
            alpha[str[j] - 'A'].first += here;
            here *= 10;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}