#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//�� �������� 2���� 2���� �迭�� �ʿ��ѵ� 
//1. ���� ��ǥ�� ġ���ΰ�(1�ΰ�), ġ� �ƴѰ�(0�ΰ�)�� ���ϴ� int�� �迭 board.
//2. ���� ��ǥ�� �ܺ� �����ΰ� Ȥ�� ���� �����ΰ��� ���ϴ� bool�� isinside.(�ļ��ϰ����� �̹��� ��� ġ����� �����ϴµ����� ����.)
//�� 2������ �ʿ��ϴ�. 

//ù��°�� ġ� ���̱� ���ؼ��� ����� 2���� �̻� �´�� �־���ϴµ� �ٸ�, ���� ����� �´�Ƶ� �ƹ��� ����� ���⿡ �ܺ� �����
//���� ���⸦ �и��ؾ߸� �Ѵ�. �������� �� �����ڸ��� ����� ġ� �ƴ϶�� ����س��⿡ {0,0}�� ������ �ܺ� �����̴�. �̰��� �̿��ؼ�
//0,0���� �����ϴ� DFS�� �����Ͽ� �ܺ� ������� �˾Ƴ��� isinside�� false�� üũ�س��´�. 

//DFS��ȸ�� ������ ��� ��ǥ���� ��ȸ�Ͽ� �ش� ��ǥ�� board���� 1�϶� �����¿� 4������ ���Ͽ� board���� 0�̸鼭(�����̸鼭), 
//isinside���� false��(���� ���Ⱑ �ƴҶ�) ���� 2�̻��϶� �� ��ǥ���� ġ��� ��� �ǹǷ� isinside���� false�� �ٲپ� ����س��´�.
//(�ֽô��� board�� 1�ΰ����� isinside���� �������� ���⿡ �̷��� ����ϴ°��� �޸� ���࿡ ������ �ȴ�.)

//�̷��� board���� ��ȸ�� ������ �̹��� ���� ġ����ǥ���� board�� 1�̸鼭 isinside�� false�� �����̴�.
//�� ��ǥ���� board���� ��� 0���� �ٲپ� �ش�.

//���������� �̹� ��ȸ�� ���� ġ����� �ֳ� Ȯ���� �ϴµ� ���� ���� ������ ���ٸ� ��� ġ� ���� ���̹Ƿ� while���� ����� �ǰ�,
//�׷��� �ʴٸ� �ð����� 1 �߰��Ͽ� �ٽ� while���� ��ȸ�Ѵ�.

int board[100][100];
bool isinside[100][100];
int trans[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;

void CheckInsideDFS(int y, int x)
{
    isinside[y][x] = false;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 1 || !isinside[dy][dx])
            continue;

        CheckInsideDFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0;
    bool ismelt;
    while (true)
    {
        ismelt = false;
        memset(isinside, true, sizeof(isinside));
        CheckInsideDFS(0, 0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 1)
                {
                    int check = 0;
                    for (int iter = 0; iter < 4; ++iter)
                    {
                        int y = i + trans[iter][0];
                        int x = j + trans[iter][1];

                        if (board[y][x] == 0 && !isinside[y][x])
                            ++check;
                    }

                    if (check >= 2)
                    {
                        ismelt = true;
                        isinside[i][j] = false;
                    }
                }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 1 && !isinside[i][j])
                    board[i][j] = 0;
        if (ismelt)
            ++answer;
        else
            break;
    }
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
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}