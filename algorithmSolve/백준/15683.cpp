#include <iostream>

using namespace std;

// 풀이.
// 큰틀에서 보자면 이 문제는 결코 어려운 문제가 아니다. 문제에서 주어지듯 cctv는 총 5개의 종류가 있고
// 배열에 cctv의 위치와 벽의 위치, 빈칸의 위치가 주어진다. 각 cctv를 90도로 회전해가며 결과적으로
// cctv에 비치지 않는 빈칸의 가장 작은 개수를 출력하면 된다.

// 하지만 말이 쉽지 구현하자면 꽤나 복잡한 문제이다.
// 각 함수에 대한 주석으로 설명을 하겠다.

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
int N, M, camera_num = 0, answer = MAX_NUM; // 세로, 가로. 1 ~ 4 좌 상 우 하


// 카메라의 범위를 체크하는 함수. 중요한 점은 어떤 칸 (y, x)가 2개 이상의 카메라에 동시에 비치는 곳일때
// 하술할 백트래킹으로 한개의 카메라의 범위를 제외할때 그곳은 비치지 않는곳으로 설정되면 안됀다.
// 현 카메라에서 제외되어도 나머지 다른 카메라에 비치고 있기 때문이다.
// 그래서 (y, x)가 처음 카메라에 비친다면 7로 그 이후 겹칠경우 1씩 증가하여 체크한다.

// 제외시킬때도 이와 마찬가지로 겹쳐서 비춰지기에 7 이상일때에는 1을빼고
// 마지막으로 제외될때 즉 값이 7일때에는 0으로 변경시킨다.
// 카메라의 번호가 1 ~ 5이고 벽의 수가 6이기에 이렇게 할수밖에 없었다.
void DrawNum(int y, int x, int dir, bool isplus)
{
    int dy = y;
    int dx = x;

    while (true)
    {
        // 주어진 방향으로 1칸 증가.
        dy += rot[dir][0];
        dx += rot[dir][1];

        // 증가한 곳이 배열을 벗어났거나 6일경우 즉, 벽일 경우에는 더이상 나아가지 않는다.
        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 6)
            break;

        // 상술한 값의 처리.
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


// K번 카메라로 비치는 곳을 체크하는 함수. for문을 이용하기 위해 여러개의 함수로 나누지 않고
// 하나로 합쳤다. 
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

// 사각지대의 총합을 반환하는 함수.
int FindNotSee()
{
    int not_see = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 0)
                ++not_see;

    return not_see;
}

// 백트래킹 순회를 하는 함수. 1, 3, 4번 카메라는 90도를 4번돌아봐야하고, 2번 카메라를 2번만 5번카메라를 굳이 회전하지 않아도 됨을
// 잊으면 안됀다.
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