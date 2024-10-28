#include <iostream>

using namespace std;

// 풀이.
// 괴상한 문제였다. 아니 정확히 말하자면 지문이 괴상한 문제였다. 푸는 방식은 범위를 가지고 있으면 된다.
// N개의 범위가 입력되는데 기존의 범위와 비교를 하여 갱신해나가면 된다. 이때 앞의 값은 무조건 뒤로 갈수록
// 커진다고 문제에서 주어졌기에 신경쓰지 않아도 되며, 기존 범위의 뒷값 to와 현재 범위값의 앞값 l을 잘 비교해야한다.
// l이 to보다 커졌다는 것은 새로운 범위가 등장했다는 것이기 때문에 기존 범위의 값을 answer에 더해주고 현재 범위로
// 갱신해야한다는 것이기 때문이다. 그렇지 않다면 to만 to와 r중 큰값으로 갱신하면 된다. 처음에는 어려워보였으나
// 생각하면 전혀 어려운 문제가 아니었다. 잘풀어냈다!

// 자세한 설명은 주석으로 남긴다.

// 기존 범위 from ~ to.
int N, from, to;

void MakeAnswer()
{
    // 현재 입력받은 범위 l ~ r.
    int l, r, answer = 0;
    // 맨처음에 from ~ to로 한번 입력받았기 때문에 N - 1까지만 입력받으면 된다.
    for (int iter = 0; iter < N - 1; ++iter)
    {
        cin >> l >> r;
        // l > to 라는 것은 현재 범위과 새로운 범위임을 뜻하므로 기존 범위값을 answer에
        // 더하고 기존 범위를 갱신한다.
        if (l > to)
        {
            answer += to - from;
            from = l;
            to = r;
        }
        // 그렇지 않다면 기존 범위가 늘어났을 뿐이므로 to를 to와 r중 큰값으로 갱신한다.
        // from은 입력 순서가 나중에 나올수록 수가 커진다고 문제에 나왔으므로 신경쓰지 않아도 된다.
        else
        {
            to = max(to, r);
        }
    }
    // 마지막 범위값을 answer에 추가해준다.
    answer += to - from;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}