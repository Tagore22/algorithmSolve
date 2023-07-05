#include <iostream>

using namespace std;

// 풀이.
// 백트래킹 문제이다. 다만 주의해야할것이 몇가지 있다.

// 1. 주사위의 윗면과 아래면의 값에는 전혀 연관성이 없다.
// 2. 다만 A번째 면은 F번째 면과 맞닿아 있는듯의 연관성만 존재한다.
// 3. 위 규칙에 의거하여 중복되는 부분이 없다. 따라서 dp는 의미가 없다.

// 이 부분만 잘 파악하면 문제 자체는 그리 어렵지 않다.
// 각 아랫면 혹은 윗면이 주어졌을때 옆면들의 합의 최대값을 출력하면 된다.
// 나는 백트래킹을 이용하여 풀었는데 다른 방법들도 있을듯 하다.

// 자세한 부분은 주석으로 남긴다.

// 배열로 매핑시킨다.
// 시작부분은 따로 -1시킬 필요없이 prev값만(이전 주사위의 위이자 현재 주사위의 아래)를
// 0 ~ 6으로 해서 돌리면 된다.

int board[10000][6];
// 윗면과 아랫면의 연관성을 배열로 매핑한다.
int map[6] = { 5, 3, 4, 1, 2, 0 };
int N;

// 현재 아랫면이 주어졌을때 옆면들중 가장 큰 수를 찾아내는 함수.
int FindMax(int idx, int cur)
{
    int ans = 0;
    // 6면중 아랫면과 윗면을 제외한 옆면들중 최대값을 반환한다.
    for (int i = 0; i < 6; ++i)
        if (i != cur && i != map[cur])
            ans = max(ans, board[idx][i]);

    return ans;
}

// 아랫면의 값 prev가 주어졌을때 N번째 주사위까지 순회하며 가장 큰 옆면을 구하는 함수.
int BackTrack(int idx, int prev)
{
    if (idx == N)
        return 0;

    int ans = 0;

    int cur;
    // 아랫면의 수가 주어졌을때 몇번째(A ~ F)면인지 찾아낸다.
    for (int i = 0; i < 6; ++i)
        if (board[idx][i] == prev)
        {
            cur = i;
            break;
        }

    // 아랫면과 윗면을 제외한 옆면들중 가장 큰수를 찾아낸다.
    int cur_max = FindMax(idx, cur);
    // 다음 주사위로 넘어간다.
    ans = max(ans, BackTrack(idx + 1, board[idx][map[cur]]) + cur_max);

    return ans;
}

void MakeAnswer()
{
    int answer = 0;

    // 6개의 면을 모두 아랫면으로 했을때 가장 큰 옆면들의 합을 구해낸다.
    for (int i = 1; i <= 6; ++i)
        answer = max(answer, BackTrack(0, i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}