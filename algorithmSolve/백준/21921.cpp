#include <iostream>

using namespace std;

// Ǯ��
// �����հ� �������� Ȥ�� �����̵� �����츦 ����ϸ� �Ǵ� ������.
// �������� ���������� ���ӵ� ������ �̶�� ���� �������� ������ ���ø� ���� ���ӵ� ������ �ִ밪�� ���ϴ� ����
// �˼� �ִ�. ���� ù��° ������ X��° ������ ������ �ʱⰪ���� ���ؼ� �� ���ĺ��� �Ϸ羿 ���ϰ� ���� �����ȳ��� �����
// �ϴ� ������ �� ������ ���� �˼� �ִ�. �̷��� ��� ���ڸ� ��ȸ�ص� �ִ� 25�����ۿ� ���� �ʱ⿡ �ð������� ����� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[250000];
int N, X;

void MakeAnswer()
{
    // ���ӵ� X���� ������ �ʱ�ȭ�Ѵ�.
    int sum = 0;
    for (int i = 0; i < X; ++i)
        sum += board[i];
    pair<int, int> answer = make_pair(1, sum);
    // ��� ���ڸ� ��ȸ�ϸ� ������ �ִ밪 �� ��ġ�� Ƚ���� ã�´�.
    for (int i = X; i < N; ++i)
    {
        // ���ο� �պκ��� �߰��ϰ�,
        sum += board[i];
        // ���� �޺κ��� �����.
        sum -= board[i - X];
        // �ִ밪�� �ѹ� �� ã�Ҵٸ� Ƚ���� ������Ų��.
        if (sum == answer.second)
            ++answer.first;
        // ���ο� �ִ밪�� ã�Ҵٸ� �����Ѵ�.
        else if (sum > answer.second)
            answer = make_pair(1, sum);
    }
    // ���� �ִ밪�� 0�̶��.
    if (answer.second == 0)
        cout << "SAD" << '\n';
    // �׷��� �ʴٸ�.
    else
        cout << answer.second << '\n' << answer.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> X;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}