#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ���� ������ ������ ���� ���� ���� ����ϴ� ������.
// �迭�� �̿��ؼ� �� ������ ������� Ȯ���� �׵��� ���� �������� ����ϸ� �Ǵ� ���� ����������
// �� ��쿡�� ���� �ٸ���. �־����� ���� ������ long long�����̱� ������ �迭�� ����� ���� �����̴�.
// ���� �־����� ������ ��� �����Ͽ� �� ������ �ϳ��� ���� ���ۿ� ����. ���� �̵��� �� ���ٹ��� ���ø��� ����
// �� ������ ������� 30�ۼ�Ʈ�� �ȵǴ°� ����. ���� ���������� ����س��� ���·� 0 ~ N - 1���� ��ȸ�ϸ� ���簪��
// �������� �ٸ��� ���� answer�� �����ϴ� ������� Ǯ����. �ٸ� ����� ������ �޸� �� ���ɿ��� ���̰� ������.

// �ڼ��� ������ �ּ����� �����.

long long board[100000];
int N;

void MakeAnswer()
{
    // ������ �ؾ� ���� ������ ���� �ִ�.
    sort(board, board + N);
    pair<int, long long> answer = make_pair(-1, -1); // ����, ���Ұ�.
    pair<int, long long> prev_num = make_pair(0, board[0]); // ������ ��ġ��, ���Ұ�.

    // 0 ~ N - 1���� ��ȸ�ϸ� ������ ������ ������ Ȯ���Ѵ�.
    // �������� �̸� ����س��� ���簪�� ���� �ٸ��� �� ���̵��� ���� �������� ���� Ƚ���̹Ƿ�
    // �װ��� ���� ������ answer�� ����Ƚ���� ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        if (prev_num.second != board[i])
        {
            // �������� ��ġ���� ���簪�� ��ġ���� ���ϸ� �������� ����Ƚ���� �˼� �ִ�.
            int cur = i - prev_num.first;
            // �������� ����Ƚ���� ������ answer�� ����Ƚ���� ���Ͽ� answer�� �����Ѵ�.
            answer = answer.first < cur ? make_pair(cur, prev_num.second) : answer;
            // ������ �������� �� ���簪�� prev_num�� �����Ѵ�.
            prev_num = make_pair(i, board[i]);
        }
    }
    // �� ���������� �ѹ��� �������־�� �Ѵ�.
    int cur = N - prev_num.first;
    answer = answer.first < cur ? make_pair(cur, prev_num.second) : answer;
    cout << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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