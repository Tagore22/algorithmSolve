#include <iostream>
#include <queue>
#include <cstring>

// 주어지는 번호는 12시 방향부터 시작하여 시계 방향이다.
// 시계 방향으로 돌때에는 맨뒤를 맨앞으로 옮기고,
// 반시계 방향은 맨앞을 맨뒤로 옮긴다.

using namespace std;

// 풀이.
// 복잡하다 싶으면 삼성 문제다. 역시나 삼성 문제였다.
// 이 문제는 다음과 같이 크게 2개만 구현하면 된다.

// 1. 원반을 돌리는 함수.
// 2. 원반들의 번호를 순회하며 인접하면서 같은 수가 있는지 확인하는 함수.

// 다만 각각의 구현이 번거롭거나 어려울수 있다.
// 또한, 2번 조건에서 같은 것이 없을때 평균을 구해 모든 수를 평균과 비교하는데
// 이때 소수점을 버리지 않고 그대로 가지고 있는데 이점을 주의해야 한다.
// 처음에는 아예 원소를 double로 받아서도 해봤는데 덧셈 연산이 있다보니
// 값의 오차가 심해져서 불가능했다. int로 덧셈 연산을 끝낸후 나누기 연산을 할때에만
// double로 변환하는 것이 정답이다.

// 자세한 것은 주석을 남긴다.

struct rota
{
    int x;
    int d;
    int k;
};

deque<int> board[51];
bool check[51][51];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하
rota r[50];
int N, M, T;

// 원반을 회전하는 함수. 원반인데 시계라고 잘못 적었다.
void MoveClock(int idx)
{
    int div = r[idx].x;
    int dir = r[idx].d;
    int num = r[idx].k;

    // div의 배수인 원반만 회전시키기 때문에 시작점을 0이 아닌 1로 잡았다.
    for (int i = 1; i <= N; ++i)
        if (i % div == 0)
        {
            // 각각 시계 방향과 반시계 방향일때. 회전은 deque로 구현하여 어렵지 않았다.
            if (dir == 0)
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].back();
                    board[i].pop_back();
                    board[i].push_front(cur);
                }
            else
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].front();
                    board[i].pop_front();
                    board[i].push_back(cur);
                }
        }
}

// 상술한 2번 조건의 함수. 
void EraseNum()
{
    // 값을 먼저 바꾸어버리면 다음 순회때 변경된 값과 비교되어 정확한 답을 구할수 없다.
    // 그렇기에 단순히 체크하는 bool 타입의 배열로 갱신을 해놓고 맨 마지막에 값을 변경해야한다.
    memset(check, false, sizeof(check));

    // 인접하면서 같은 값을 찾았는지를 확인하는 변수.
    bool isfind = false;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            // 현재 0, 즉 지워진 번호라면 무시한다.
            if (board[i][j] == 0)
                continue;

            for (int iter = 0; iter < 4; ++iter)
            {
                int dy = i + rot[iter][0];
                int dx = j + rot[iter][1];

                // 상술하였듯 배수때문에 0번이 아닌 1번부터 시작했기에 y가 0이 되면 안된다.
                if (dy <= 0 || dy > N)
                    continue;

                // x값은 회전되기에 언제나 벗어날일이 없어야 한다.
                if (dx == M)
                    dx = 0;
                else if (dx == -1)
                    dx = M - 1;

                if (board[i][j] == board[dy][dx])
                {
                    isfind = true;
                    check[i][j] = true;
                    check[dy][dx] = true;
                }
            }
        }

    // 인접하면서 같은 값을 찾았다면 해당 값들을 모두 0으로 바꾸어버린다.
    if (isfind)
    {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (check[i][j])
                    board[i][j] = 0;
    }

    // 찾지 못했다면 모든 수의 평균을 구하여 평균보다 크다면 -1을,
    // 작다면 +1을 해준다. 다만 같을시에는 아무런 조치를 취하지 않으며
    // 소수점을 버리지 않기에 double로의 변환을 사용해야 한다.
    // 아예 원소값을 double로 해도 안되며 그 이유는 상술하였다.
    else
    {
        int num = 0;
        int sum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    ++num;
                    sum += board[i][j];
                }

        // 소수점을 버리지 않기에 double로의 변환을 사용해야 한다. + 변수의 승격.
        double div = static_cast<double>(sum) / num;

        // 모든 값들을 갱신한다.
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    if (board[i][j] > div)
                        --board[i][j];
                    else if (board[i][j] < div)
                        ++board[i][j];
                }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        MoveClock(i);
        EraseNum();
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            answer += board[i][j];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int cur;
            cin >> cur;
            board[i].push_back(cur);
        }

    for (int i = 0; i < T; ++i)
        cin >> r[i].x >> r[i].d >> r[i].k;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}