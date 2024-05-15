#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �ƹ� �������� M���� for������ N���� �迭������ ������Ű�Բ� �����Ͽ���.
// �̷��� ���귮�� N * M�� �Ǵµ� N, M�� �ִ밪�� 10���̴�. ���� 100���̶�� ���귮�� ������ �Ǿ�
// �ð��ʰ��� ���Ҽ� ���� �ȴ�. ������ �� �����ϸ� �Ʒ��� ���� �ٸ� Ǯ�̸� �����Ҽ� �ִµ�,
// queue�� �Է°��� ������ ������ �ִ� ���� �ٲٰ�, stack�� �����ϰ� �ȴ�. ��������� ������ queue�� �ִ�
// ������ �ڿ������� �ϳ��� ��µȴ�. �� ���Ŀ��� �Է¹��� ������ �ٽ� queue�� ���� ��µȴ�.
// ��, ������ queue�� �ִ� ������ �ڿ������� ����ϰ� �� ���� M�� �Է¹��� ������ ������� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

bool isStack[100000];
int board[100000], answer[100000];
int N, M, idx = -1;

void MakeAnswer()
{
    // �迭�� �������� ��ȸ�ϸ� queue�� �ִ� ������ �����Ѵ�.
    for (int iter = N - 1; iter >= 0; --iter)
        if (!isStack[iter])
            answer[++idx] = board[iter];
    int num;
    // M����ŭ �Է¹��� ������ �����Ѵ�. �� ������ ��������� ��µ� �����̴�.
    for (int iter = 0; iter < M; ++iter)
        cin >> answer[++idx];
    // ����� ������ M���� ����Ѵ�. 
    for (int iter = 0; iter < M; ++iter)
        cout << answer[iter] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> isStack[i];
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}