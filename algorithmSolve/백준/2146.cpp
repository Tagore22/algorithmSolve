#include <iostream>
#include <vector>


//DFS�� ���ؼ� �� n��° ������ ��ǥ���� ��� ���س���, �� ������ ��ǥ�� ���Ͽ� ����� �ִ� ���� ���� �ٸ��� ũ�⸦ ���Ѵ�.
//�ٸ��� ������ �ϴ� ��ǥ�� �������� ���� ��ǥ���� ������ ��ǥ�� �� ���밪�� �ٸ��� ũ���̴�.

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> check;
vector<vector<pair<int, int>>> lands;
vector<pair<int, int>> now_land;
int N;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
const int MAXNUM = 987654321;

//���������� ��ȸ�ϸ� �������� ���غ��� ������� ��ǥ�� �����Ѵ�.

void DFS(int y, int x) 
{
    check[y][x] = true;
    now_land.push_back(make_pair(y, x));
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || N <= cy || cx < 0 || N <= cx || check[cy][cx] || board[cy][cx] == 0)
            continue;

        DFS(cy, cx);
    }
}

//��� ��ǥ�� ��ȸ�ϸ� �������� Ȯ�� �� �� ������ ��ǥ�� �����س��´�.

void MakeLand() 
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 1 && !check[i][j])
            {
                DFS(i, j);
                lands.push_back(now_land);
                now_land.clear();
            }
}

//�� ������ ��ǥ�� ��ȸ�ϸ� �ٸ� ������ ��ǥ�� ���Ͽ� �ٸ��� ũ�⸦ ���Ѵ�.
//�ٸ��� ũ��� ����Ͽ����� ������ - �������� ���������� �ϳ��� ���밪�̴�.

void MakeAnswer()
{
    MakeLand();
    int answer = MAXNUM;
    for (int i = 0; i < lands.size() - 1; ++i)
        for (int j = i + 1; j < lands.size(); ++j)
            for (int k = 0; k < lands[i].size(); ++k)
                for (int v = 0; v < lands[j].size(); ++v)
                {
                    int first_y = lands[i][k].first;
                    int first_x = lands[i][k].second;
                    int second_y = lands[j][v].first;
                    int second_x = lands[j][v].second;

                    for (int idx = 0; idx < 4; ++idx)
                    {
                        int cy = second_y + dy[idx];
                        int cx = second_x + dx[idx];

                        if (cy < 0 || N <= cy || cx < 0 || N <= cx || board[cy][cx] == 1)
                            continue;

                        answer = min(answer, abs(cy - first_y) + abs(cx - first_x));
                    }
                }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N, 0));
    check.resize(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}