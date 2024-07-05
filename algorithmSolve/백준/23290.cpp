#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Ǯ��.
// ��� 1�̴�. �Ｚ�̴�. �����ɷȴ�. ���� ����� ������... 7�� ���̴�. ��..
// �� �׷��� ����� ������ ���������� �����ϰ� ������ �ִ� ������. �������� �Ǽ��� �ߴµ� �� �ּ����� ó���ϰ��� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

// P.S ������ ��...ģ������ ���� ��������. Ư���� �� �̵��Ҷ��� ������ �ſ� �����ߴµ� ��������� ���� ĭ��
// ����Ⱑ �����Ҽ��� �ֱ� �����̴�. �� ��쿡 �԰� ����ϴ��� �׷��� �������� ���� ������ �ƿ� ������.
// ���� ���� �غ��鼭 �°� Ʋ����� �˾ƾ� �ϴµ� �ֽô��� �׷� ��찡 �����ϴ� ���� ��ü�� ��û ������ ����
// �����غ��⵵ ��������� ���� �׷� ���� ��ü�� �����ٸ� �� �񶧸��� ��Ȳ�� �������� ���̴�.

struct fish
{
    int y;
    int x;
    int d;
};

vector<fish> fishs, prev_fish;
int fish_rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int shark_rot[5][2] = { {0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int M, S;
pair<int, int> shark;
pair<string, int> shark_max;
int fish_board[5][5] = { 0, };
int smell_board[5][5] = { 0, };
// 5������ �������� ��ȸ�ϸ� ��ġ�� ������ �ƴ� �����鸸 �߰� �Ѵ�.
// ������ �ִ°��� �ٽ� ������ ����� �׳� ������.

// 5���� �ش��ϴ� �Լ�. �������� �����Ѵ�.
void ReproFish()
{
    // 1���� �����ߴ� ��� �������� �����Ѵ�. �� �ִ� ĭ�̵� ������ �ִ� ĭ�̵� �����Ѵ�.
    for (auto& a : prev_fish)
        ++fish_board[a.y][a.x];
    // ���⿡�� ��û ��̴�. � ����Ⱑ �����Ǹ鼭 ������ �ִ� ĭ�� �����Ǿ��µ� 8������ ��� ������
    // ���ư��� �����ٸ� �̹� �̵��� �� ������ ������ �ִ� ĭ�� �״�� �ӹ��� �ȴ�. ���� �ּ�ó�� �� �κ�ó��
    // ������ 0�� ��ġ�� �����鸸 �߰��ϸ� �ȵȴ�. ������ 2�ΰ��� �̹��� ������ �������� ������ �������� �ƿ� ������
    // 1�� ���� ����Ѵ�� ������ �ִ� ���� �����Ǿ� ��Ƴ��� �������� �����ϱ� �����̴�.
    for (auto& a : fishs)
    {
        // if(smell_board[a.y][a.x] == 0)
        //     prev_fish.push_back(a); 
        if (smell_board[a.y][a.x] != 2)
            prev_fish.push_back(a);
    }
    // �ٽ� fishs�� ��� �������� ������ �ѱ��.
    fishs = prev_fish;
}

// ������ �������� 4�� �Լ�.
void EraseSmell()
{
    // ��� ĭ���� ������ 1�� �����. �ٸ� �̶� ������ �Ǿ �ȵȴ�.
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            if (smell_board[i][j] > 0)
                --smell_board[i][j];
}

// ����� ��� �̵����� ����غ��� �Լ�.
void CalMoveShark(int y, int x, string str, int sum)
{
    // 3���� ��� �̵��Ͽ����� ��Ƹ��� �������� ���� ������̶�� �̵�������
    // �������� ���� �����ϰ� Ż���Ѵ�.
    if (str.size() == 3)
    {
        if (sum > shark_max.second)
            shark_max = make_pair(str, sum);
        return;
    }

    // 4������ ��� ��ȸ�غ���.
    for (int i = 1; i <= 4; ++i)
    {
        int ny = y + shark_rot[i][0];
        int nx = x + shark_rot[i][1];

        // �迭���� ����� �����Ѵ�.
        if (ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
            continue;

        // �̰������� �Ǽ��ߴµ� ��Ƹ��� ĭ�� �������� �Ͻ������� 0���� ó������ ������
        // �̹� �������� �������� �ٽ� ��湮�ϰ� �ȴ�.
        int next_fish = fish_board[ny][nx];
        fish_board[ny][nx] = 0;
        CalMoveShark(ny, nx, str + to_string(i), sum + next_fish);
        fish_board[ny][nx] += next_fish;
    }
}

// ������ �� �̵��ϴ� �Լ�.
void MoveShark(int d)
{
    // �־��� ������ �̵��Ѵ�.
    shark.first += shark_rot[d][0];
    shark.second += shark_rot[d][1];

    // �̵��Ѱ��� �������� �����Ѵٸ� 0���� �����ϰ� ������ 3���� �Ѵ�.
    // �� 2�� �ƴ϶� 3�̳ĸ� �̵��� 4������ �ѹ� ����� �����̴�.
    if (fish_board[shark.first][shark.second] > 0)
    {
        smell_board[shark.first][shark.second] = 3;
        fish_board[shark.first][shark.second] = 0;
    }
}

// �������� �����̴� 2�� �Լ�.
void MoveFish()
{
    // ��� �������� ��ȸ�Ѵ�.
    for (auto& a : fishs)
    {
        int y = a.y;
        int x = a.x;
        int d = a.d - 1;

        // 8������ ��ȸ�Ѵ�.
        for (int i = 0; i < 8; ++i)
        {
            int ny = y + fish_rot[d][0];
            int nx = x + fish_rot[d][1];

            // �迭���� ����� �ʰ� �� �������� ������ ������ ���� ĭ�̶�� �̵��Ѵ�.
            if (ny > 0 && ny <= 4 && nx > 0 && nx <= 4 && smell_board[ny][nx] == 0 &&
                make_pair(ny, nx) != shark)
            {
                --fish_board[y][x];
                ++fish_board[ny][nx];
                a.y = ny;
                a.x = nx;
                a.d = d + 1;
                break;
            }
            d = (d + 7) % 8;
        }
    }
}

// �� �̵����� ���� ĭ�� ����Ⱑ �ִٸ� �װ��� �����ΰ� �ƴѰ�
void MakeAnswer()
{
    for (int iter = 0; iter < S; ++iter)
    {
        // ���⼭�� �Ǽ��߾��µ� �ִ밪�� ���ϴ� shark_max���� �Ź� �ʱ�ȭ���־�߸� �Ѵ�.
        shark_max = make_pair("", -1);
        // 1��. ���� clear()�� ���� �ʾҴ�. ���߿� �����ǳ� Ȯ��.
        prev_fish = fishs;
        // 2��.
        MoveFish();
        // 3��.
        CalMoveShark(shark.first, shark.second, "", 0);
        for (int i = 0; i < 3; ++i)
            MoveShark(shark_max.first[i] - 48);
        // 4��.
        EraseSmell();
        // 5��.
        ReproFish();
    }
    int answer = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            answer += fish_board[i][j];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> S;
    fish cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur.y >> cur.x >> cur.d;
        fishs.push_back(cur);
        ++fish_board[cur.y][cur.x];
    }
    cin >> shark.first >> shark.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}