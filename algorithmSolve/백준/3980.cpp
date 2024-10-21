#include <iostream>

using namespace std;

// 풀이.
// 잘 생각해보면 중복이 존재했다. 예를 들어 3번째를 고를때 1번에서 1번을 2번에서 2번을 고를때와, 1번에서 2번을
// 2번에서 1번을 고를때 중복이 발생했다. 따라서 idx번째에서 고를때 앞에서 어떤것들이 골라졌는지 알기 위한
// 비트마스크가 필요했으며 그 비트마스크로 DP를 구현해야했다. 그 이후 한가지 실수를 했는데 문제에서 0은 고를수
// 없다고 제시되어있다. 이말은 현재 고를수 있는것들이 0만 남았다면 이 경우는 아예 불가능하다는 것인데 이걸 걸러
// 낼수 있는 구현이 빠져있었다. 정답은 ans의 초기값을 음수로 하는 것이다. 그러면 아래 for문에서 순회이후 고른것이
// 없을때 엄청 큰 음수를 반환하여 경우에서 제외시킬수 있기 때문이다. 이부분을 헷갈려서 괜힌 기저사례만 건드리고 있었다;
// 어쨌든 잘 풀어내서 다행이다.

// 자세한 설명은 주석으로 남긴다.

// 예전에 봤던 기억이 났다. 배열의 원소수에 비트마스크 연산을 넣을수 있었다.
int board[11][11], dp[11][1 << 11];
int T;

int CalMax(int idx, int mask)
{
    // 마지막까지 전부 골랐다면 더이상 고를수 없기에 0을 반환한다.
    if (idx == 11)
        return 0;

    int& ans = dp[idx][mask];
    if (ans != -1)
        return ans;
    // 상술한 부분. 만약 단 하나도 고를수 없다면 엄청 큰 음수를 반환하여
    // 경우에서 제외시킨다.
    ans = -11000;

    for (int i = 0; i < 11; ++i)
    {
        // 이미 골랐거나, 그 값이 0이라면 고를수 없다.
        if ((1 << i) & mask || board[idx][i] == 0)
            continue;
        ans = max(ans, CalMax(idx + 1, (mask | (1 << i))) + board[idx][i]);
    }
    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < (1 << 11); ++j)
                dp[i][j] = -1;
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < 11; ++j)
                cin >> board[i][j];

        cout << CalMax(0, 0) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}