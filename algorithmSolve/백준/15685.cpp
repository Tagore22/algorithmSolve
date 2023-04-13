#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Ǯ��.
// �巡�� Ŀ��� ������ 2���� ������ ���� �׷�����.
// 1. ó�� �׸���(0����)���� ������ 1�� �����δ�.
// 2. ó���� �ƴҽ� ������ ������� �ڿ������� ������ �� ������ 1�� ������Ų �������� �����δ�.

// �׷��� ������ ���Ϳ� ���� �����ӵ��� �����س��� �ڿ������� ������ 1�� ������Ų�� ���� ��ġ��
// �ű��� �� ������ �ٽ� ���Ϳ� ����ִ°��� �ݺ��ϸ� �ȴ�.

// �ᱹ ���� Ǯ�̴� ��� �巡�� Ŀ�긦 ����� ������ ��ǥ�� bool �迭 check�� �����س���
// ��� ��ǥ���� ��ȸ�ϸ� ���� ��ġ {y, x}�� ����Ͽ� {y + 1, x}, {y, x + 1}, {y + 1, x + 1}��
// true���� Ȯ���ϰ� �´ٸ� ������ answer�� 1�� �������ѳ��� �������� answer�� ����ϸ� �ȴ�.

// P.S 
// x���� y���� �Ųٷ� �ִ� ���� ���� ��������. ���� ���� ���غ��� ����� �ʾҴ�.
// Ȥ���� Ŀ�긦 �׸��µ� �迭�� ����� ��찡 ������ ���� ���ǹ��� �־������ 
// ���ǹ��� ��� �´°ɺ��� ������ ��찡 ��������.

struct curve
{
    int from_y;
    int from_x;
    int dir;
    int gen;
};

vector<int> board;
int rot[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
bool check[101][101];
curve curves[20];
int N;

// Ŀ�긦 �׸��� �Լ�. 
void DrawCurve(int y, int x, int dir, int gen)
{
    if (gen == -1)
        return;

    if (board.empty())
    {
        check[y][x] = true;
        board.push_back(dir);
        y = y + rot[dir][0];
        x = x + rot[dir][1];

        if (y < 0 || y > 100 || x < 0 || x > 100)
            return;

        check[y][x] = true;
    }
    else
    {
        int iter = board.size() - 1;
        int new_dir;
        for (int i = iter; i >= 0; --i)
        {
            new_dir = (board[i] + 1) % 4;
            y = y + rot[new_dir][0];
            x = x + rot[new_dir][1];

            if (y < 0 || y > 100 || x < 0 || x > 100)
                return;

            check[y][x] = true;
            board.push_back(new_dir);
        }
    }
    DrawCurve(y, x, dir, gen - 1);
}

// ��� Ŀ�긦 �׸��� �Լ�.
void DrawAllCurves()
{
    for (int i = 0; i < N; ++i)
    {
        board.clear();
        DrawCurve(curves[i].from_y, curves[i].from_x, curves[i].dir, curves[i].gen);
    }
}

// 4������ ��� Ŀ�꿡 ���ԵǾ��ִ��� Ȯ���ϴ� �Լ�.
bool CheckPos(int y, int x)
{
    return (check[y][x] && check[y + 1][x] && check[y][x + 1] && check[y + 1][x + 1]);
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    DrawAllCurves();

    int answer = 0;
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            if (CheckPos(i, j))
                ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> curves[i].from_x >> curves[i].from_y >> curves[i].dir >> curves[i].gen;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}