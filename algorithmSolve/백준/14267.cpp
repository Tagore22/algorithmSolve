#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ó������ M���� DFS()�� ����ߴ�. ��, Ī���� �߻��Ҷ����� ���� ��ȣ���� �����ؼ� DFS()�� �����ϰ� �߾���.
// ������ �ѹ��� DFS()���� �ִ� 10���� ��带 �������� �װ��� �ִ� 1000�� �ݺ��Ǳ⿡ �ð��ʰ��� ����.
// ���⼭ �Ӹ��� ���ݸ� ���� �Ǵµ�, Ī�������� DFS��ȸ�� ���� �ʰ� ������ Ī���� �� Ī������ ��� ���ѻ��¿���
// �� �ѹ��� DFS��ȸ�� ���� ���Ҽ� �ֱ� �����̴�. � ��尡 Ī���� �޾� ���� �����ϸ� �� �ڽ� ������ ������
// ���� ����ŭ �����ϱ� ������ Ī�� ���������� DFS ��ȸ�� �ϴ� ��� ���� ������ ��ȸ�� �ϴ� ����� ���� ���̴�.
// ���õ� ���� �ƽ��� ������ ��.. ������ �� ��������!

// �ڼ��� ������ �ּ����� �����.

vector<int> board[100001];
int answer[100001];
int N, M;

// DFS ��ȸ�� �����ϴ� �Լ�.
void Comp(int idx)
{
    // idx��° ����� ��� �ڽĵ��� ��ȸ�ϸ� Ī������ �����ϰ� ��� ȣ���Ѵ�.
    for (auto& a : board[idx])
    {
        answer[a] += answer[idx];
        Comp(a);
    }
}

void MakeAnswer()
{
    Comp(1);
    for (int i = 1; i <= N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        answer[i] = 0;
    int a;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a;
        if (a != -1)
            board[a].push_back(i);
    }
    int b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        answer[a] += b;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}