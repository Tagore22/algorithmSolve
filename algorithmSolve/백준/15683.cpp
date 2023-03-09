#include <iostream>

using namespace std;

// Ǯ��.
// ūƲ���� ���ڸ� �� ������ ���� ����� ������ �ƴϴ�. �������� �־����� cctv�� �� 5���� ������ �ְ�
// �迭�� cctv�� ��ġ�� ���� ��ġ, ��ĭ�� ��ġ�� �־�����. �� cctv�� 90���� ȸ���ذ��� ���������
// cctv�� ��ġ�� �ʴ� ��ĭ�� ���� ���� ������ ����ϸ� �ȴ�.

// ������ ���� ���� �������ڸ� �ϳ� ������ �����̴�.
// �� �Լ��� ���� �ּ����� ������ �ϰڴ�.

struct camera
{
    int num;
    int y;
    int x;
};

camera cameras[8];
int board[8][8];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int cctvs[4][4] = { {0, 2, 0, 0}, {0, 1, 0, 0}, {0, 1, 2}, {0, 1, 2, 3} };
const int MAX_NUM = 987654321;
int N, M, camera_num = 0, answer = MAX_NUM; // ����, ����. 1 ~ 4 �� �� �� ��


// ī�޶��� ������ üũ�ϴ� �Լ�. �߿��� ���� � ĭ (y, x)�� 2�� �̻��� ī�޶� ���ÿ� ��ġ�� ���϶�
// �ϼ��� ��Ʈ��ŷ���� �Ѱ��� ī�޶��� ������ �����Ҷ� �װ��� ��ġ�� �ʴ°����� �����Ǹ� �ȉ´�.
// �� ī�޶󿡼� ���ܵǾ ������ �ٸ� ī�޶� ��ġ�� �ֱ� �����̴�.
// �׷��� (y, x)�� ó�� ī�޶� ��ģ�ٸ� 7�� �� ���� ��ĥ��� 1�� �����Ͽ� üũ�Ѵ�.

// ���ܽ�ų���� �̿� ���������� ���ļ� �������⿡ 7 �̻��϶����� 1������
// ���������� ���ܵɶ� �� ���� 7�϶����� 0���� �����Ų��.
// ī�޶��� ��ȣ�� 1 ~ 5�̰� ���� ���� 6�̱⿡ �̷��� �Ҽ��ۿ� ������.
void DrawNum(int y, int x, int dir, bool isplus)
{
    int dy = y;
    int dx = x;

    while (true)
    {
        // �־��� �������� 1ĭ ����.
        dy += rot[dir][0];
        dx += rot[dir][1];

        // ������ ���� �迭�� ����ų� 6�ϰ�� ��, ���� ��쿡�� ���̻� ���ư��� �ʴ´�.
        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 6)
            break;

        // ����� ���� ó��.
        if (isplus)
        {
            if (board[dy][dx] == 0)
                board[dy][dx] = 7;
            else
                ++board[dy][dx];
        }

        else
        {
            if (board[dy][dx] == 7)
                board[dy][dx] = 0;
            else
                --board[dy][dx];
        }
    }
}


// K�� ī�޶�� ��ġ�� ���� üũ�ϴ� �Լ�. for���� �̿��ϱ� ���� �������� �Լ��� ������ �ʰ�
// �ϳ��� ���ƴ�. 
void UpdateCCTV(int y, int x, int cctv_num, int dir, bool isplus)
{
    if (cctv_num == 1)
    {
        DrawNum(y, x, dir, isplus);
    }
    else if (cctv_num == 2)
    {
        for (int i = 0; i < 2; ++i)
            DrawNum(y, x, (dir + cctvs[cctv_num - 2][i]) % 4, isplus);
    }
    else if (cctv_num == 3)
    {
        for (int i = 0; i < 2; ++i)
            DrawNum(y, x, (dir + cctvs[cctv_num - 2][i]) % 4, isplus);
    }
    else if (cctv_num == 4)
    {
        for (int i = 0; i < 3; ++i)
            DrawNum(y, x, (dir + cctvs[cctv_num - 2][i]) % 4, isplus);
    }
    else
    {
        for (int i = 0; i < 4; ++i)
            DrawNum(y, x, (dir + cctvs[cctv_num - 2][i]) % 4, isplus);
    }
}

// �簢������ ������ ��ȯ�ϴ� �Լ�.
int FindNotSee()
{
    int not_see = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 0)
                ++not_see;

    return not_see;
}

// ��Ʈ��ŷ ��ȸ�� �ϴ� �Լ�. 1, 3, 4�� ī�޶�� 90���� 4�����ƺ����ϰ�, 2�� ī�޶� 2���� 5��ī�޶� ���� ȸ������ �ʾƵ� ����
// ������ �ȉ´�.
void BackTrack(int idx)
{
    if (idx == camera_num)
    {
        answer = min(answer, FindNotSee());
        return;
    }

    if (cameras[idx].num == 5)
    {
        UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, 1, true);
        BackTrack(idx + 1);
        UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, 1, false);
    }

    else if (cameras[idx].num == 2)
    {
        for (int i = 0; i < 2; ++i)
        {
            UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, i, true);
            BackTrack(idx + 1);
            UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, i, false);
        }
    }

    else
    {
        for (int i = 0; i < 4; ++i)
        {
            UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, i, true);
            BackTrack(idx + 1);
            UpdateCCTV(cameras[idx].y, cameras[idx].x, cameras[idx].num, i, false);
        }
    }
}

void MakeAnswer()
{
    BackTrack(0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (1 <= board[i][j] && board[i][j] <= 5)
            {
                cameras[camera_num].num = board[i][j];
                cameras[camera_num].y = i;
                cameras[camera_num].x = j;
                ++camera_num;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}