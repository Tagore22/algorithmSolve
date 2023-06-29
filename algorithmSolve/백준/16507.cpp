#include <iostream>

using namespace std;

// 풀이.
// 주어진 두 꼭지점 범위내의 값들의 평균을 출력하는 문제다.
// 주어지는 배열의 값은 1000 * 1000이고, 테스트 케이스 Q가 10000인데 1000으로 잘못봐서
// 처음에는 10억이니까 되겠지 하고는 마구잡이로 풀었더니 당연히 시간초과가 나왔다.
// 정답은 누적합을 이용하는것이었는데 언젠가 종만북에서 봤던 범위값을 이용하는 것이었다.
// 범위는 늘 직사각형이기 때문에 그림을 그려가며 풀면 이해하기가 쉽다. 누적합을 구하는건 다음과 같다.

// 1. 현재 구해야 하는 값 x, y과 누적합 배열 sum이 있다고 한다.
// 2. x - 1이 0보다 클때(주어진 좌표의 시작이 1, 1부터임) sum[x - 1][y]값을 더한다.
// 3. y - 1이 0보다 클때 sum[x][y - 1]을 더한다.
// 4. sum[x - 1][y - 1]은 두번 제거되었기 때문에 다시 sum[x - 1][y - 1]을 더해준다.
// 5. 마지막으로 board[x][y]값을 더해준다.

// 이것이 바로 좌표 x, y의 직사각형 누적합을 구하는 방식이다.
// 전처리로 모든 좌표값의 누적합을 더해준후 겹치지 않는 부분들을 빼주고 앞서 마찬가지로
// 두번 제거된곳들을 다시 더해줘서 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1001][1001], sum[1001][1001];
int R, C, Q;
pair<int, int> from, to;

// 상술한 각 좌표의 직사각형 모양 누적합을 구하는 함수.
void CalSum()
{
    int ans;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
        {
            ans = 0;
            if (i - 1 > 0)
                ans += sum[i - 1][j];
            if (j - 1 > 0)
                ans += sum[i][j - 1];
            if (i - 1 > 0 && j - 1 > 0)
                ans -= sum[i - 1][j - 1];
            ans += board[i][j];
            sum[i][j] = ans;
        }
}

// 각 누적합을 미리 구해준후, 시작값과 끝값을 받아 그 평균을 출력한다.
void MakeAnswer()
{
    CalSum();
    int answer;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> from.first >> from.second >> to.first >> to.second;

        // 끝값으로 시작한다.
        answer = sum[to.first][to.second];
        // 결과값에 포함되지 않는 곳들을 제거한다. 다만 조건문을 걸어 배열밖으로 나가는것을 방지해야한다.
        if (from.first - 1 > 0)
            answer -= sum[from.first - 1][to.second];
        // 위와 같음.
        if (from.second - 1 > 0)
            answer -= sum[to.first][from.second - 1];
        // 누적합을 구할때와 같이, 두번 제거된 부분들이 존재하므로 다시 채워넣어주어야 한다.
        if (from.first - 1 > 0 && from.second - 1 > 0)
            answer += sum[from.first - 1][from.second - 1];
        // 좌표들의 개수로 나누어 출력한다.
        answer /= (to.first - from.first + 1) * (to.second - from.second + 1);
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> Q;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}