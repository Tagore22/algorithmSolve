#include <iostream>

using namespace std;

// 풀이.
// 주어진 명령대로 주사위를 움직여서 배열안에 존재한다면 주사위를 회전시켜 칸에 내용을 변경, 혹은 변경하지 않는 문제이다.

// 구현한 함수는 다음과 같다.

// 1. 주사위를 회전시키는 함수.
// 2. 주어진 명령에 의해 주사위를 이동 및 회전시킨후 출력하는 함수.

// 보통 세로값을 Y, 가로값을 X로 잡아서 주어진 입력값의 반대로 사용했는데 오히려 X가 세로를 Y가 가로를 가리키고 있었다.
// 심지어 반대로 해도 주어진 예제는 다맞았었다. 이게 무슨... 문제를 잘보자.

int board[20][20];
int rot[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // 동, 서, 북, 남
int moves[1000];
int dice[6] = {}; // 위쪽에서 봤을때 동, 서, 북, 남 그리고 위와 아래 순서.
int N, M, X, Y, K;

// 주사위를 회전시키는 함수.
void MoveDice(int num)
{
    int temp = dice[5];
    if (num == 1)
    {
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = temp;
    }
    else if (num == 2)
    {
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[0];
        dice[0] = temp;
    }
    else if (num == 3)
    {
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[3];
        dice[3] = temp;
    }
    else
    {
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[2];
        dice[2] = temp;
    }
}

// 나머지를 처리하는 함수.
void MakeAnswer()
{
    int check_y;
    int check_x;
    
    // 주어진 명령에 의해 주사위를 이동시켜보고 배열안이라면 나머지를 밖이라면 무시한다.
    for (int i = 0; i < K; ++i)
    {
        check_y = Y + rot[moves[i] - 1][0];
        check_x = X + rot[moves[i] - 1][1];

        if (check_x < 0 || check_x >= M || check_y < 0 || check_y >= N)
            continue;

        // 실제로 주사위를 이동 및 회전시킨다.
        Y = check_y;
        X = check_x;
        MoveDice(moves[i]);

        // 이동한 칸의 값이 0이라면 주사위의 아래값을 복사시키고, 그렇지 않다면 주사위의 아래값을 칸의 값으로 복사한 후
        // 칸의 값을 0으로 변경시킨다.
        if (board[Y][X] == 0)
        {
            board[Y][X] = dice[5];
        }
        else
        {
            dice[5] = board[Y][X];
            board[Y][X] = 0;
        }

        // 주사위의 윗값 출력.
        cout << dice[4] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> Y >> X >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    for (int i = 0; i < K; ++i)
        cin >> moves[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}