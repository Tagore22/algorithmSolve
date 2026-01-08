#include <iostream>

using namespace std;

// 풀이.
// 처음엔 위상 정렬을 생각했다. 하지만 주어지는 원소값이 너무 많고
// 단 하나의 경우만을 도출해야했기에 전혀 불가능한 로직이었다.
// 정답은 엄청 간단했는데 (x, y) 같은 경우 x값은 y값보다 크고,
// y값은 x값보다 작아야하기에 그 상대적인 순서를 +-로 갱신해주면 된다.
// 예를 들면 (1, 2)인 경우 answer[1]은 +1을, answer[2]는 -1을 하는 것이다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int board[100001];
bool visit[100001] = { false, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        board[i] = i;
    for (int i = 0; i < M; ++i)
    {
        // 앞에 값은 상대적으로 커지고, 뒤에 값은 상대적으로 작아진다.
        int plus, minus;
        cin >> plus >> minus;
        ++board[plus];
        --board[minus];
    }
    bool isfind = true;
    for (int i = 1; i <= N; ++i)
    {
        int num = board[i];
        // 어떤 값이 말도 안되게 커지거나, 중복된 값이 존재할 경우
        // 입력이 제대로 된 경우가 아니다.
        if (num > N || visit[num])
        {
            isfind = false;
            break;
        }
        visit[num] = true;
    }
    if (!isfind)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 1; i <= N; ++i)
            cout << board[i] << ' ';
        cout << '\n';
    }
    return 0;
}