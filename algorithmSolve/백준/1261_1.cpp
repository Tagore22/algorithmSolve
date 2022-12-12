#include <iostream>
#include <deque>

using namespace std;

//힌트에 있던 0-1BFS를 찾아서 대입한 풀이.
//기존 BFS와 크게 다르지는 않으나, 정렬을 위해 컨테이너에 앞뒤로 원소를 삽입해야하기에 queue대신 deque가 사용되었다.

//풀이
//기존 풀이와 풀이 자체는 같다. 다만 0-1BFS와 deque의 특성에 따라 다음 정점으로 나아가는 과정에서 가중치가 추가된다면 
//최소 가중치에서 멀어지기에 deque의 앞이 아닌 뒤에 두어 결과적으로 연산량을 줄이기에 최적화되었다.
//그러므로 시간복잡도도 구하기 쉬워졌는데, 앞뒤로 원소를 삽입한 덕분에 가중치가 적은 원소부터 순회가 가능하다.
//이로 인해 오직 모든 정점에서 단 한번씩 갈수 있는 모든 간선을 통해 연산이 일어나기에 시간복잡도는 BFS와 동일한 O(V+E)가 된다.
//(모든 정점에서 이동 가능한 간선을 통해 이동을 시도하나, deque의 앞뒤 삽입(가중치의 정렬)에 의해 각 정점에 도달하는 간선은 오직 하나가 된다)
//그러므로 도달 가능한 모든 정점의 수 V + 모든 간선을 단 한번씩 V

int board[100][100];
int walls[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int M, N;
const int MAX_NUM = 987654321;

void ZeroOne(int y, int x)
{
    deque<pair<int, int>> deq;
    deq.push_back(make_pair(y, x));

    while (!deq.empty())
    {
        int now_y = deq.front().first;
        int now_x = deq.front().second;
        deq.pop_front();

        for (int i = 0; i < 4; ++i)
        {
            int cy = now_y + dy[i];
            int cx = now_x + dx[i];

            if (cy < 0 || cy >= N || cx < 0 || cx >= M)
                continue;

            if (walls[now_y][now_x] + board[cy][cx] < walls[cy][cx])
            {
                walls[cy][cx] = walls[now_y][now_x] + board[cy][cx];

                if (board[cy][cx] == 1)
                    deq.push_back(make_pair(cy, cx));
                else
                    deq.push_front(make_pair(cy, cx));
            }
        }
    }
}

void MakeAnswer()
{
    ZeroOne(0, 0);
    cout << walls[N - 1][M - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            walls[i][j] = MAX_NUM;
    walls[0][0] = 0;

    cin >> M >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}