#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ٽ� ������ �ϱ� ���� ������ ������.
// 2���� ���Ϳ� 1���� ������ ���κ��� �°� ���Ƴ��� �͵� ���� ������.
// ���� ��ü�� ����� �ʴ�. ���״�� ����� �̵� ������ �ְ� ����� �̵� ������ �ִ�.
// ���� �� �����ϼ� �ִ� ��� ���� ������ ������ �ִ� ������ȣ�� ������ ���� ū���� ����ϸ� �ȴ�.
// �ٸ� ������ ���� �ʾҴµ� ��� �̰� 60�۸� �Ѵ� ����������� �𸣰ڴ�.

struct fish
{
    int num;
    int dir;
    int y;
    int x;
    bool islive;
};

vector<vector<int>> board;
vector<fish> fishes;
int rot[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} }; // ������ �ݽð� ����.
fish shark;
int answer = 0;

// ������ 0������ �̵��Ѵ�. �׷��⿡ ������ �ʿ��Ѵ�.
bool CompareFish(const fish& lhs, const fish& rhs)
{
    return lhs.num < rhs.num;
}

// �������� �̵��� ����ϴ� �Լ�.
void FishMove(vector<vector<int>>& cur_board, vector<fish>& cur_fishes, fish& cur_shark)
{
    for (int iter = 0; iter < cur_fishes.size(); ++iter)
    {
        if (!cur_fishes[iter].islive)
            continue;

        // ���� ��ǥ�� �� ����.
        int cy = cur_fishes[iter].y;
        int cx = cur_fishes[iter].x;
        int cur_dir = cur_fishes[iter].dir - 1;

        // �ִ� 7���� 45���� �ݽð� �������� ȸ���غ��� �̵��Ҽ� �ִ� ���� ã�´�.
        // ���� �� �� ������ �ٲ�� �Ϳ� ����.
        int dy, dx;
        for (int i = 0; i < 8; ++i)
        {
            dy = cy + rot[cur_dir][0];
            dx = cx + rot[cur_dir][1];

            if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4 || (dy == cur_shark.y && dx == cur_shark.x))
            {
                cur_dir = (cur_dir + 1) % 8;
                continue;
            }

            // �ٲ�� ���� fishes�ȿ� �ִ� ��ǥ���� ������� ���� �����̸� ���� ������ ����Ⱑ ������ �ٲ���ٸ� �װ͸���
            // �����ؾ� �Ѵ�.
            swap(cur_fishes[iter].y, cur_fishes[cur_board[dy][dx] - 1].y);
            swap(cur_fishes[iter].x, cur_fishes[cur_board[dy][dx] - 1].x);
            swap(cur_board[cy][cx], cur_board[dy][dx]);
            swap(cur_fishes[iter].islive, cur_fishes[cur_board[dy][dx] - 1].islive);
            cur_fishes[iter].dir = cur_dir + 1;
            break;
        }
    }
}

// ��Ʈ��ŷ���� ����� �������� ����ϴ� �Լ�. �� �Լ��ʹ� �޸� �����ڸ� �̿��Ͽ� �������� ���ν�Ű�� �ȵȴ�.
void SharkEat(vector<vector<int>> cur_board, vector<fish> cur_fishes, fish cur_shark, int sum)
{
    FishMove(cur_board, cur_fishes, cur_shark);
    vector<vector<int>> new_board;
    vector<fish> new_fishes;
    fish new_shark;
    int idx = 0;

    while (true)
    {
        // ��Ʈ��ŷ ���� �ٽ� �����Ͽ����� ���� �ٲ�������� �ȵǱ⿡ �Ź� �����ؾ��Ѵ�.
        ++idx;
        new_board = cur_board;
        new_fishes = cur_fishes;
        new_shark = cur_shark;

        new_shark.y = new_shark.y + rot[new_shark.dir - 1][0] * idx;
        new_shark.x = new_shark.x + rot[new_shark.dir - 1][1] * idx;

        // ��ǥ���� ����ٸ� ���̻� �����ϼ� ����.
        if (new_shark.y < 0 || new_shark.y >= 4 || new_shark.x < 0 || new_shark.x >= 4)
            break;

        // �̹� ���� ������� ������ ����. ������ ���� ������ �Ѿ���� �ִ�.
        if (!new_fishes[new_board[new_shark.y][new_shark.x] - 1].islive)
            continue;

        new_fishes[new_board[new_shark.y][new_shark.x] - 1].islive = false;
        new_shark = new_fishes[new_board[new_shark.y][new_shark.x] - 1];

        SharkEat(new_board, new_fishes, new_shark, sum + new_shark.num);
    }
    answer = max(answer, sum);
}

void MakeAnswer()
{
    SharkEat(board, fishes, shark, shark.num);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    board.resize(4, vector<int>(4, 0));

    int cur_num, cur_dir;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            cin >> cur_num >> cur_dir;
            fishes.push_back(fish{ cur_num, cur_dir, i, j, true });
        }
    shark = fishes[0];
    fishes[0].islive = false;
    sort(fishes.begin(), fishes.end(), CompareFish);
    for (int i = 0; i < fishes.size(); ++i)
        board[fishes[i].y][fishes[i].x] = fishes[i].num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}