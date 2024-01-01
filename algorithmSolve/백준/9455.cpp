#include <iostream>

using namespace std;

// 풀이.
// 각 칸들이 중력에 의해 내려갈때 이동한 칸의 수를 출력하는 문제다.
// 맨 아래부터 위로 올라가며 흰칸(원소값이 0인칸)은 그 위에 검은칸이 있다면 이동하는 칸이므로
// 움직이는 칸이 된다. 이것들을 모두 계산해서 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100][100];
int T, M, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> M >> N;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];

        // 현재 케이스의 최종값.
        int answer = 0;
        // 열부터 계산해서 모든 행까지 계산한다.
        for (int i = 0; i < N; ++i)
        {
            // 현재 열에서 이동하는 칸.
            int num = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                // 현재 칸이 검은색이라면 여태까지 구해왔던 이동가능한 흰칸들의 수만큼 이동한다.
                if (board[j][i] == 1)
                    answer += num;
                // 현재 칸이 흰칸이라면 이동가능한 칸이 된다.
                else
                    ++num;
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

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}