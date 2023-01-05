#include <iostream>
#include <cstring>

using namespace std;

//������ �Ƹ����ߴ� ����. ��� N���� �̵��߿��� ���� ���� �湮���� �ʴ� Ȯ������ �˾Ҵµ�, �װ� �ƴ϶� N�� �����̴� ���߿� �湮�ߴ� ����
//�Ǵٽ� �湮���� �ʴ� Ȯ���̾���.

//Ǯ��
//�̵� �Ҽ� �ִ� ��� ��츦 ��Ʈ��ŷ���� �̵��ϵ�, �̹� �湮�ߴ� ���� �Ǵٽ� �湮�ϴ� ����� �Լ��� �����Ͽ� �����Ѵ�.
//�߿��� ����, �ѹ� �̵��� �湮�ߴ� ���� ���� ����(N���� �̵��� ���ưų� Ȥ��, �̹� �湮�Ѱ��� �湮�Ͽ� �Լ��� return�� ����)������
//��ȿ�ϱ⿡ ��Ʈ��ŷ�� true�� false�� ���� �ʰ� �Ź� �������־�� �Ѵ�.

int per[4];
int trans[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; //�������� ��
int N;
double answer = 0.0;
bool board[29][29]; //������������ �ִ� N���� �����ϼ� �־���ϴ� ũ��.

void BackTrack(int y, int x, int move, double plus) //y��ǥ, x��ǥ, ���� �̵���, ���� ��ǥ�� �����Ҽ� �ִ� Ȯ��.
{
    if (board[y][x]) //�̹� �湮�� ���̶�� �̹� �̵��� �����Ѵ�.
        return;

    if (move == 0) //������ N��° �湮�̸鼭 �������� �ʴ� ���� �����ߴٸ� �� Ȯ���� �����信 ������ �̹� �̵�����.
    {
        answer += plus;
        return;
    }

    board[y][x] = true; //�̹� �̵����� �� ��ǥ�� �湮������ ���.
    for (int i = 0; i < 4; ++i) //������������ ��� �̵��غ���, �̵��� Ȯ���� 0�̶�� ����.
    {
        if (per[i] == 0)
            continue;

        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        BackTrack(dy, dx, move - 1, plus * (per[i] / 100.0));
    }
    board[y][x] = false; //�̹� �̵��� ����Ǿ����Ƿ� �湮�ߴ� ���� ��� ��ȿȭ��Ų��.
}

void MakeAnswer()
{
    BackTrack(N, N, N, 1.0);

    cout.precision(9);
    cout << fixed;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, false, sizeof(board));

    cin >> N;
    for (int i = 0; i < 4; ++i)
        cin >> per[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}