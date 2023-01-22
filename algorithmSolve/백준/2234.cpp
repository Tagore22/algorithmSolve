#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//Ǯ��
//1, 2���� �ٷ� ���ö�����, 3���� �ָ��ϰ� ������ ���� �ʾƼ� �ظ̴� ����. 1���� DFS�� �̿��ؼ� �湮���� ���� ��ǥ�� ã���� ����
//���� ������ 1���� �÷��ָ� �ǰ�, 2���� DFS�� ���鼭 ���� ũ�⸦ 1�� �÷��ֵ�, DFS�� �������� ���� �ִ밪�� ���ϸ� �ȴ�.
//3���� �̹� ��ǥ [y][x]���� ���� ���� ũ��� [y-1][x], [y][x-1]���� ���� ���� ũ�⸦ ���ϸ� �ȴ�.
//�ٸ�, y,x�� 0���� �۰ų� ���� M, N���� Ŭ���, [y][x]�� [y-1][x] Ȥ�� [y][x-1]�� ���� ���� ���� �����Ѵ�.

vector<int> rooms_size;
int board[50][50], room_num[50][50];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool check[50][50];
int N, M;
int max_size = 0, plus_room = 0, cur_size = 0;

void DFS(int y, int x)
{
    ++cur_size;
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        if (!(board[y][x] & (1 << i)))
        {
            int dy = y + tran[i][0];
            int dx = x + tran[i][1];

            if (dy < 0 || dy >= M || dx < 0 || dx >= N || check[dy][dx])
                continue;

            DFS(dy, dx);
        }
    }
    room_num[y][x] = rooms_size.size();
}

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (!check[i][j])
            {
                cur_size = 0;
                DFS(i, j);
                max_size = max(max_size, cur_size);
                rooms_size.push_back(cur_size);
            }
            for (int dir = 0; dir < 2; ++dir)
            {
                int di = i + tran[dir][0];
                int dj = j + tran[dir][1];

                if (di < 0 || di >= M || dj < 0 || dj >= N || room_num[i][j] == room_num[di][dj])
                    continue;

                plus_room = max(plus_room, rooms_size[room_num[i][j]] + rooms_size[room_num[di][dj]]);
            }
        }
    cout << rooms_size.size() << '\n';
    cout << max_size << '\n';
    cout << plus_room << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}