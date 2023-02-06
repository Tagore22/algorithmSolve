#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//Ǯ��
//1������ N������ �̵��ϴ� Ʈ������ �ù踦 ����Ҷ� �Ǿ���� �ù��� �켱������ ������ ����.
//1. �ִ��� ���� ������ �ִ��� ���� ������ �����Ƿ� ���� ������ �ִ°�(���� ��Ұ� 1������ ������)
//2. ���� ���������� �ִ��� ���� ������������ �ٸ����� ǥ���ϸ�(���� ��Ұ� ������ҿ� ������)
//�� 2�����̴�.

//�� 2���� ���ǿ� ���� �־����� �ù���� �����ϵ� �� ����� ������ ����.
//1. �޴� ��Ұ� ������������ ���ĵɰ�. (�� ���ǿ� 1���� ����)
//2. �޴� ��Ұ� ������ ���� ��Ұ� ���� ���� �� �տ� �ð�. (�� ���ǿ� 2���� ����)

//�̷��� ������ ������ ��� �ù���� ��ȸ�ϸ� �� ���ÿ��� ������ �ִ� ���Ը� ���ϰ� �� ���԰��� �� ���� �����ش�.
//�ù踦 �Ǵ� ���� from���� ����ϴ� �� - 1�� to���� �ٽ� ��ȸ�ϸ� �� ���ÿ����� ���� �ִ� ���Ը� ���Ѵ�.
//�׸��� �� �ù��� ���Կ� �ִ� ����(C) - ���� �ִ� ���Ը� ������ �ּҰ��� from���� to���� ��Ʋ�� �߰��Ҽ� �ִ� ���� now_capa��.
//�� ���� from���� to���� ��� ���� �ָ� ���� ����ؾ��� �Ѱ� answer�� ���������ν� ��ȸ�� �Ϻθ� �ϼ��Ѵ�.
//�� ��ȸ�� ������ ������ answer�� ��ȯ�Ѵ�.

struct box
{
    int from;
    int to;
    int num;
};

int capa[10001];
box board[10000];
int N, C, M;

bool ComposeFunc(const box& first, const box& second)
{
    if (first.to != second.to)
        return first.to < second.to;
    else
        return first.from < second.from;
}

void MakeAnswer()
{
    int answer = 0;
    sort(board, board + M, ComposeFunc);

    for (int i = 0; i < M; ++i)
    {
        int max_capa = 0;
        for (int iter = board[i].from; iter < board[i].to; ++iter)
            max_capa = max(max_capa, capa[iter]);

        int now_capa = min(board[i].num, C - max_capa);

        answer += now_capa;
        for (int iter = board[i].from; iter < board[i].to; ++iter)
            capa[iter] += now_capa;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(capa, 0, sizeof(capa));

    cin >> N >> C >> M;
    for (int i = 0; i < M; ++i)
        cin >> board[i].from >> board[i].to >> board[i].num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}