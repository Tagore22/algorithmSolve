#include <iostream>

using namespace std;

// 풀이.
// 어렵기보다 좌표를 헷갈리지 않아야 하는 손많이 가는 문제였다.
// 관건은 토네이도의 회전인 것 같은데 그 부분만 잘 알아채면 쉽게 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[500][500];
int rot[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} }; // 좌, 하, 우, 상
int N, answer = 0;


// 문제에서 주어진 토네이도의 이동시 모래의 변화를 구현하는 함수. 좌표 때문에 고생했다.
void MoveTornado(int y, int x, int dir)
{
    int ten = board[y][x] / 10;
    int seven = board[y][x] * 7 / 100;
    int five = board[y][x] / 20;
    int two = board[y][x] / 50;
    int one = board[y][x] / 100;

    if (dir == 0)
    {
        // 5%.
        if (x - 2 <= 0)
            answer += five;
        else
            board[y][x - 2] += five;
        board[y][x] -= five;

        // 10% 위.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += ten;
        else
            board[y - 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% 아래.
        if (y + 1 > N || x - 1 <= 0)
            answer += ten;
        else
            board[y + 1][x - 1] += ten;
        board[y][x] -= ten;

        // 2% 위쪽.
        if (y - 2 <= 0)
            answer += two;
        else
            board[y - 2][x] += two;
        board[y][x] -= two;

        // 2% 아래.
        if (y + 2 > N)
            answer += two;
        else
            board[y + 2][x] += two;
        board[y][x] -= two;

        // 1% 위쪽.
        if (y - 1 <= 0 || x + 1 > N)
            answer += one;
        else
            board[y - 1][x + 1] += one;
        board[y][x] -= one;

        // 1% 아래.
        if (y + 1 > N || x + 1 > N)
            answer += one;
        else
            board[y + 1][x + 1] += one;
        board[y][x] -= one;

        // 7% 위.
        if (y - 1 <= 0)
            answer += seven;
        else
            board[y - 1][x] += seven;
        board[y][x] -= seven;

        // 7% 아래.
        if (y + 1 > N)
            answer += seven;
        else
            board[y + 1][x] += seven;
        board[y][x] -= seven;

        // 나머지
        if (x - 1 <= 0)
            answer += board[y][x];
        else
            board[y][x - 1] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 1)
    {
        // 5%.
        if (y + 2 > N)
            answer += five;
        else
            board[y + 2][x] += five;
        board[y][x] -= five;

        // 10% 위.
        if (y + 1 > N || x - 1 <= 0)
            answer += ten;
        else
            board[y + 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% 아래.
        if (y + 1 > N || x + 1 > N)
            answer += ten;
        else
            board[y + 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% 위쪽.
        if (x - 2 <= 0)
            answer += two;
        else
            board[y][x - 2] += two;
        board[y][x] -= two;

        // 2% 아래.
        if (x + 2 > N)
            answer += two;
        else
            board[y][x + 2] += two;
        board[y][x] -= two;

        // 1% 위쪽.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += one;
        else
            board[y - 1][x - 1] += one;
        board[y][x] -= one;

        // 1% 아래.
        if (y - 1 <= 0 || x + 1 > N)
            answer += one;
        else
            board[y - 1][x + 1] += one;
        board[y][x] -= one;

        // 7% 위.
        if (x - 1 <= 0)
            answer += seven;
        else
            board[y][x - 1] += seven;
        board[y][x] -= seven;

        // 7% 아래.
        if (x + 1 > N)
            answer += seven;
        else
            board[y][x + 1] += seven;
        board[y][x] -= seven;

        // 나머지
        if (y + 1 > N)
            answer += board[y][x];
        else
            board[y + 1][x] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 2)
    {
        // 5%.
        if (x + 2 > N)
            answer += five;
        else
            board[y][x + 2] += five;
        board[y][x] -= five;

        // 10% 위.
        if (y - 1 <= 0 || x + 1 > N)
            answer += ten;
        else
            board[y - 1][x + 1] += ten;
        board[y][x] -= ten;

        // 10% 아래.
        if (y + 1 > N || x + 1 > N)
            answer += ten;
        else
            board[y + 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% 위쪽.
        if (y - 2 <= 0)
            answer += two;
        else
            board[y - 2][x] += two;
        board[y][x] -= two;

        // 2% 아래.
        if (y + 2 > N)
            answer += two;
        else
            board[y + 2][x] += two;
        board[y][x] -= two;

        // 1% 위쪽.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += one;
        else
            board[y - 1][x - 1] += one;
        board[y][x] -= one;

        // 1% 아래.
        if (y + 1 > N || x - 1 <= 0)
            answer += one;
        else
            board[y + 1][x - 1] += one;
        board[y][x] -= one;

        // 7% 위.
        if (y - 1 <= 0)
            answer += seven;
        else
            board[y - 1][x] += seven;
        board[y][x] -= seven;

        // 7% 아래.
        if (y + 1 > N)
            answer += seven;
        else
            board[y + 1][x] += seven;
        board[y][x] -= seven;

        // 나머지
        if (x + 1 > N)
            answer += board[y][x];
        else
            board[y][x + 1] += board[y][x];
        board[y][x] = 0;
    }

    if (dir == 3)
    {
        // 5%.
        if (y - 2 <= 0)
            answer += five;
        else
            board[y - 2][x] += five;
        board[y][x] -= five;

        // 10% 위.
        if (y - 1 <= 0 || x - 1 <= 0)
            answer += ten;
        else
            board[y - 1][x - 1] += ten;
        board[y][x] -= ten;

        // 10% 아래.
        if (y - 1 <= 0 || x + 1 > N)
            answer += ten;
        else
            board[y - 1][x + 1] += ten;
        board[y][x] -= ten;

        // 2% 위쪽.
        if (x - 2 <= 0)
            answer += two;
        else
            board[y][x - 2] += two;
        board[y][x] -= two;

        // 2% 아래.
        if (x + 2 > N)
            answer += two;
        else
            board[y][x + 2] += two;
        board[y][x] -= two;

        // 1% 위쪽.
        if (y + 1 > N || x - 1 <= 0)
            answer += one;
        else
            board[y + 1][x - 1] += one;
        board[y][x] -= one;

        // 1% 아래.
        if (y + 1 > N || x + 1 > N)
            answer += one;
        else
            board[y + 1][x + 1] += one;
        board[y][x] -= one;

        // 7% 위.
        if (x - 1 <= 0)
            answer += seven;
        else
            board[y][x - 1] += seven;
        board[y][x] -= seven;

        // 7% 아래.
        if (x + 1 > N)
            answer += seven;
        else
            board[y][x + 1] += seven;
        board[y][x] -= seven;

        // 나머지
        if (y - 1 <= 0)
            answer += board[y][x];
        else
            board[y - 1][x] += board[y][x];
        board[y][x] = 0;
    }
}

void MakeAnswer()
{
    // 주어진 원리에 의해 토네이도는 계속 이동하고 이동 후 현재 좌표가 1, 1이라면 최종값을 출력한다.
    pair<int, int> cur = make_pair(N / 2 + 1, N / 2 + 1);
    int idx = -1, dir, mul;

    // 토네이도는 좌, 하, 우, 상 순서대로 움직이기에 그 순서대로 이동 좌표를 짜면 되고,
    // 2로 나눈 것 + 1만큼 이동한다. 이것을 이용하면 된다.
    while (true)
    {
        ++idx;
        dir = idx % 4;
        mul = idx / 2 + 1;
        for (int i = 0; i < mul; ++i)
        {
            int y = cur.first + rot[dir][0];
            int x = cur.second + rot[dir][1];

            MoveTornado(y, x, dir);

            cur = make_pair(y, x);
            if (cur == make_pair(1, 1))
            {
                cout << answer << '\n';
                return;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}