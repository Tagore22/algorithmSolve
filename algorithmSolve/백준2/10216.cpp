#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 그룹을 묶는다는 것에서 유니온 파인드임을 알 수 있었다. 단순히
// 모든 정점들을 반복하지 않으며 순회하여 각 정점들끼리 거리와 통신 거리를
// 계산하면 된다. 다만, 3가지 실수를 하였는데 이는 후술한다.

// 자세한 설명은 주석으로 남긴다.

struct point
{
    int x;
    int y;
    int r;
};

int T, N;
point board[3000];
int p[3000];
bool visit[3000];

int Find(int num)
{
    if (p[num] == num)
        return num;
    // 이 부분이 첫번째 실수이다. 종만북에서 봤듯 p[num]을
    // 매번 갱신시켜 최적화하는 부분인데 p[num] = Find(num)으로 했다.
    return p[num] = Find(p[num]);
}

void Merge(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;
    p[a] = b;
}

bool CheckDist(int from, int to)
{
    // 두 좌표 사이의 거리와 반지름의 차이를 계산하는 부분인데 이곳이 두번째 실수이다.
    // 거리 = (두 x좌표의 차이의 제곱 + 두 y좌표의 차이의 제곱)의 루트 << 인데
    // 잠을 덜깼나 이상하게 계산하였다. 따라서 위 점화식의 양변을 제곱해주면 
    // 제곱근을 굳이 사용할 필요가 없어진다.
    int dist = (board[to].x - board[from].x) * (board[to].x - board[from].x) +
        (board[to].y - board[from].y) * (board[to].y - board[from].y);
    return dist <= (board[from].r + board[to].r) * (board[from].r + board[to].r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            p[i] = i;
            cin >> board[i].x >> board[i].y >> board[i].r;
        }
        for (int i = 0; i < N - 1; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (CheckDist(i, j))
                    Merge(i, j);
            }
        }
        int answer = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < N; ++i)
        {
            // 최초로 등장한 원소값인 경우 최종답을 1씩 늘려준다.
            // 이곳이 세번째 실수이다. 처음엔 if(!visit[p[i]])로 했는데
            // 상술한 Find()에서 매번 p[num] = Find(p[num])으로 갱신을
            // 하기 때문에 굳이 Find()를 호출하지 않고 p[i]로 가능할 줄 알았으나
            // 위에서 Merge()를 호출할 때 Find()를 호출하고 난 이후 새롭게 
            // 두 그룹이 묶이기 때문에 결과적으로 p[i]는 가장 최종 루트를 가리키지
            // 않을 수도 있다. 따라서 새로이 Find()를 호출하여 가장 최종 루트를
            // 다시 알아야한다.
            if (!visit[Find(i)])
            {
                ++answer;
                visit[p[i]] = true;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}