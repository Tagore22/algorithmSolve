#include <iostream>

using namespace std;

// Ǯ��.
// �������� �������� ��������. ���� ���밪�� 0�� ���� ����� �� ������ ����ϴ� �����̴�.
// ū Ʋ�� ���ڸ� ������ ����.

// 1. �ΰ��� ��ġ from�� to�� �����. �������� ���� 0�� N - 1�̴�. ����, �ּҰ� min_num�� �� ���� ��ġ�� min_pos�� �����.
// �ʱⰪ�� from�� to�� ���ʰ��� �� ���� �θ� �ȴ�.
// 2. from�� to�� ���� ���밪�� 0�� ���� ��������ϹǷ� from�� to�� �������� 0���� ũ�ٸ�
// �پ��� ���� to�� 1 �����ϰ�, 0���� �۴ٸ� �����ϱ� ���� from�� 1 �����Ѵ�. ���� ���밪�� 0�̶�� ���̻��� ��ȸ��
// �ʿ����� �����Ƿ� min_pos���� �����ϰ� �ٷ� �ݺ����� �������´�.
// 3. 2���� �ݺ��ϵ� �Ź� from�� to�� ���� ���밪�� min_num�� ���밪�� ���Ͽ� min_num�� ���밪���� �۴ٸ�
// min_num �� min_pos�� �������ش�. ����, ���� �ٸ� 2���� ����� ���� ������ from�� to���� ������ �����Ƿ�
// from�� to���� �����ʰ� ������������ �ݺ��Ѵ�.(while���� ����).

// �ڼ��� ������ �ּ����� �����.

int board[100000];
int N;

void MakeAnswer()
{
    // �ΰ��� ��ġ from�� to. �ʱⰪ�� ����Ͽ��� 0�� N - 1�̴�.
    int from = 0;
    int to = N - 1;
    // ���� 0�� ���� ����� �� min_num�� �׶��� ��ġ min_pos.
    int min_num = board[from] + board[to];
    pair<int, int> min_pos = make_pair(from, to);
    int cur;

    // ����Ͽ��� ������ ���� �ٸ� �ΰ��� ����� ���ٰ� ���������Ƿ�, from�� to�� �������� ����.
    while (from < to)
    {
        // ���� ��ġ�� ����� ���غ��� �� ���밪�� �ּҰ��� ���Ͽ� �Ź� �����Ѵ�.
        cur = board[from] + board[to];
        if (abs(min_num) > abs(cur))
        {
            min_pos = make_pair(from, to);
            min_num = cur;
        }
        // ���� ���� 0���� �۴ٸ� �� �þ���ϱ⿡ from�� 1 �����Ѵ�.
        if (cur < 0)
        {
            ++from;
        }
        // ���� ���� 0���� ũ�ٸ� �� �پ�����ϱ⿡ to�� 1 �����Ѵ�.
        else if (cur > 0)
        {
            --to;
        }
        // 0�� �߰��Ͽ��ٸ� ���̻��� ��ȸ�� �ʿ����� �ʱ⿡ ��ġ���� �����ϰ� �ݺ����� 
        // Ż���Ѵ�.
        else
        {
            min_pos = make_pair(from, to);
            break;
        }
    }
    cout << board[min_pos.first] << ' ' << board[min_pos.second] << '\n';
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