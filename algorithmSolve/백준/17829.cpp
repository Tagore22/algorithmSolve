#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 매번 배열들을 2x2 정사각형으로 나누며 두번째 큰 수들을 모아 다시 반복하는
// 문제다. 처음에 가장 고민이었던 것은 새로이 배열을 만드는 것이었다.
// 벡터 두개를 이용하여 이중 버퍼처럼 구현할까 생각했으나 매번 복사를 해야했기에
// 배열 하나를 써서 인덱스값을 계산하는 것으로 틀었다. 연산량은 정말 최대로 잡아
// 1억이 조금 넘기에 시간내에 충분히 가능했다.

// 자세한 설명은 주석으로 남긴다.

int N;
int board[1024][1024], cur[4];

void Solve()
{
    // 8일 경우 4번, 4일 경우 2번을 반복하게 된다.
    int rep = N / 2;
    for (int iter = 0; iter < rep; ++iter)
    {
        // 각 좌표를 2x2로 나눈 정사각형이란 건 2칸씩 건너뛰는 것과 같다.
        for (int i = 0; i < N; i += 2)
        {
            for (int j = 0; j < N; j += 2)
            {
                // 4칸의 값들을 구해 정렬한 후 2번째 큰 수를
                // 새롭게 덮어쓴다. 앞으로 계산해야할 값을
                // 덮어쓰는 경우는 존재하지 않으며 문제에서 주어지듯
                // 5, 5, 4, 2 같은 경우에도 실제로 2번째 큰 수는 
                // 4지만 값이 같은 경우에도 N번째로 치기 때문에
                // 아래 구현대로 sort() 이후 뒤에서 2번째 값을
                // 대입하면 된다.
                cur[0] = board[i][j];
                cur[1] = board[i][j + 1];
                cur[2] = board[i + 1][j];
                cur[3] = board[i + 1][j + 1];
                sort(cur, cur + 4);
                board[i / 2][j / 2] = cur[2];
            }
        }
        // N을 나누어 배열이 줄었음을 적용한다.
        N /= 2;
    }
    // 마지막 남은 1개의 수를 출력한다.
    cout << board[0][0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}