#include <iostream>
#include <deque>

using namespace std;

// 풀이.
// 문제 자체는 엄청 어렵지는 않으나 로직을 잘못짜서 하루종일 푼 문제다.
// 치명적인 실수는 2가지가 있었다.

// 1. 로직을 잘못짬. 문제에서 제시된것은 이동 후 파이어볼을 합치는 것인데 나는 이동전에 합쳐서 로직이 한창 꼬였다.
// 2. 덱을 잘못썼다. 덱을 사용함으로써 용량을 줄이고 불필요한 연산을 없애는 것은 맞으나 기존의 원소가 지워질때
// 참조하고 있던 포인터, 참조자들은 모두 참조가 풀려버린다. 이걸 실수했다.

// 기존의 풀이를 고쳐보려고 했으나 1번의 문제로 인해 결국 다시 푸는게 맞는 상황이 되었다.
// 일단 문제에서 제시된 대로 풀고 덱은 오늘 경험한대로 자료의 삭제시 주의하도록 하자.

// 자세한 설명은 주석으로 남긴다.

struct Fireball
{
    // 질량, 방향, 속력, 움직인 턴;
    int m;
    int s;
    int d;
    int turn;
};

deque<Fireball> board[51][51];
int N, M, K; // 배열의 한쪽 크기, 파이어볼의 개수, 움직이는 횟수;
int rot[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int turn = 1;

// 모든 파이어볼들이 이동하는 함수.
void MoveFireball()
{
    // 각 좌표별로 순회하며 현재 턴에 이동하는 모든 파이어볼들을 이동시킨다.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // 이부분이 중요하다. 덱은 이 이후로 원소가 삭제될 가능성이 농후하다. 따라서 미리 원소의 개수를 저장해놔야한다.
            // 그렇지 않으면 이후에 랜덤액세스가 다 꼬여 버린다.
            int dsize = board[i][j].size();
            for (int iter = 0; iter < dsize; ++iter)
            {
                // 맨 앞의 원소가 현재 턴에서 이미 이동한 원소라면 이 이후로는 모두 이미 이동한 원소들이기 때문에
                // 무시한다.
                if (board[i][j].front().turn != turn)
                    break;

                int m = board[i][j].front().m;
                int s = board[i][j].front().s;
                int d = board[i][j].front().d;
                int turn = board[i][j].front().turn;

                // 1번에서 -로 가면 N번으로, N번에서 +로 가면 1번으로 돌고 도는 배열이기에
                // 모듈러 연산을 이용한다.
                int dy = (i + (rot[d][0] * s)) % N;
                if (dy > 0)
                    dy = dy % N == 0 ? N : dy % N;
                else
                    dy = N + dy % N;
                int dx = (j + (rot[d][1] * s)) % N;
                if (dx > 0)
                    dx = dx % N == 0 ? N : dx % N;
                else
                    dx = N + dx % N;
                // 새로운 위치에 파이어볼을 저장하고 기존 위치의 파이어볼을 제거 한다.
                board[dy][dx].push_back(Fireball{ m, s, d, turn + 1 });
                board[i][j].pop_front();
            }
        }
    }
}

// 한칸에 복수의 파이어볼이 존재할시 합치는 함수.
void FusionFireball()
{
    // 모든 원소를 순회하며 복수가 존재할시 합친다.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // 위 상술한대로 원소가 삭제될시 기존의 board[i][j].size()는 무용지물이 된다.
            int dsize = board[i][j].size();
            if (dsize >= 2)
            {
                // 모든 방향이 같은지 확인하고 모든 원소들의 속력과 질량을 합친다.
                int m = 0, s = 0;
                bool isSame = true, isEven = board[i][j].front().d % 2;
                for (int iter = 0; iter < dsize; ++iter)
                {
                    m += board[i][j].front().m;
                    s += board[i][j].front().s;
                    if (isSame)
                        isSame = isEven == board[i][j].front().d % 2 ? true : false;
                    board[i][j].pop_front();
                }

                m /= 5;
                // 질량의 합을 5로 나누어 0이라면 사라진다.
                if (m == 0)
                    continue;
                s /= dsize;
                int d = isSame ? 0 : 1;
                // 합쳐진 파이어볼들을 4개로 나눈다.
                for (int iter = 0; iter < 4; ++iter)
                {
                    board[i][j].push_front(Fireball{ m, s, d, turn });
                    d += 2;
                }
            }
        }
    }
}

// K번의 이동 이후 남은 질량을 모두 합치는 함수.
void CalMass()
{
    int answer = 0;
    // 모든 원소를 순회하며 남은 질량을 합친다.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            // 사실 여기는 원소들의 변화가 없기에 굳이 이렇게 하지 않고
            // board[i][j].size()로 해도 된다.
            int dsize = board[i][j].size();
            for (int iter = 0; iter < dsize; ++iter)
                answer += board[i][j].front().m;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        MoveFireball();
        ++turn;
        FusionFireball();
    }
    CalMass();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    int r, c, m, d, s;
    for (int i = 0; i < M; ++i)
    {
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back(Fireball{ m, s, d, 1 });
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}