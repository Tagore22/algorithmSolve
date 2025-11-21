#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음엔 DP로 풀려고 했으나 그러려면 각 원소에 도달했을 때
// 선택한 것들 역시 DP로 표현해야했고 비트마스크를 쓰자니
// 치킨의 종류가 최대 30개라 용량이 너무 커졌다. 진짜 정답은
// 그냥 4중 for문을 이용하는 것이었다. 아이러니하게도 치킨의 종류가 최대
// 30개라 너무 작아서 말 그대로 완전탐색을 사용해도 무관했다.

int N, M;
int board[30][30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    int answer = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = i + 1; j < M; ++j)
        {
            for (int k = j + 1; k < M; ++k)
            {
                int sum = 0;
                for (int y = 0; y < N; ++y)
                    sum += max({ board[y][i], board[y][j], board[y][k] });
                answer = max(answer, sum);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}