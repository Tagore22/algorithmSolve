#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//ó������ �������θ� Ȥ�� ���������θ� ���� �߰��ϴ� �Լ� 2���� ���� �߰��� ���� ��������
//����ϰԲ� �����߾����� ���� ���� �ƴϾ���. �����غ��� ������ ���� Ȥ�� �������� �ƴ϶�
//��������� ����, ��������� �������� �������� ��찡 �����ߴµ� �̰� �����߾���.
//�׷��� 2���� ��츦 ��� �賶�������� �ϱ⿣ N�� �ʹ����� �Ǳ⿡ DP�� �̿��ؾ��ߴ�.

//���� ������ from�� ���� to�� 0�� N-1�� �ΰ�, from�� to�� ���ų� from�� �� Ŀ���� ������
//��� ��ȸ�� �Ѵ�. �̶� board[from]�� board[to]�� ���ٸ� ���� ���� �߰����� �ʾƵ� ������
//�ƹ��͵� ���� �ʰ� from+1, to-1��°�� Ȯ���ϸ� �ǰ�, ���� �ٸ��ٸ� ���� Ȥ�� �����ʿ�
//���� �߰��Ͽ� �� ����� �߰��� ���� �� �������� ����ϸ� �ȴ�.

int board[5000], cashe[5000][5000];
int N;

int AddElement(int from, int to)
{
    if (from >= to)
        return 0;

    int& ans = cashe[from][to];
    if (ans != -1)
        return ans;

    ans = 5000;

    //���� �� ���� board[from]�� board[to]�� ���Ѵ�.
    if (board[from] == board[to]) //�� ���� ���� ���. �ƹ��͵� �߰����� �ʾƵ� ������ �������� �Ѿ.
        ans = AddElement(from + 1, to - 1);
    else                          //�� ���� �ٸ� ���. ���� Ȥ�� �����ʿ� �߰��ϵ� �� ���� ���� �߰� �Ǵ� ��츦 üũ�Ѵ�.
        ans = min(AddElement(from, to - 1) + 1, AddElement(from + 1, to) + 1);

    return ans;
}

void MakeAnswer()
{
    int answer = AddElement(0, N - 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}