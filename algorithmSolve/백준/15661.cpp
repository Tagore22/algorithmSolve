#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ���� �ƴ� �����ε� �� �ɿ��ϰ� �����ߴ� �����̴�.
// �������� �ִٴ°� �̷������� �𸣰�����, �ϳ� �߿��� �����ε� �ϴ�.
// ������ ūƲ�� ������ ����.

// 1. ����� �ִ� ��� ��쿡 ���� ������ �ɷ�ġ�� �ּҰ��� ����Ѵ�.

// �ٸ� ���⼭ �������� Ǯ�̰� ���ü� �ִ�. �� ������ ���� �پ��� ������� Ǯ��ñ⿡
// ���� �����̶�� �����Ǵ� Ǯ�� ����� ���´�.

// 1. ó��Ǯ������ ��Ʈ����ũ�� ��� ��츦 ��������. �׷��� �Ű������� �߰��� ��Ʈ��ŷ ������ �� ���Ҵµ�
// ��Ʈ����ũ�� ��� ��츦 ���鶧���� �Ź� N���� ���Ҹ� ��ȸ�ؾ� �ߴ�. ������ ��Ʈ��ŷ�� �Ű������� �߰��Ѵٸ�
// ���� ���Ұ����� �߰��Ͽ� �����ϸ� �Ǳ⿡ �ξ� ������.(ù��° Ǯ�̿� ���� �ֱ� Ǯ�̸� ���غ��� �ȴ�.)

// 2. �� ���� �ɷ�ġ�� �����Ҷ����� �߿��ѵ� �������� ������ N��° ���Ұ� �߰��� ���� �ѹ��� �ɷ�ġ�� ����߾���.
// �̶� �ִ� N���� �ش��ϴ� ������ ���� ��ø�� 2���� for������ ��ȸ�߾���. ������ �̷��� �ϱ⺸��
// �Ʒ� Ǯ�̿� ���� �ֵ��� �ƿ� �ɷ�ġ ��ü�� �Ű�����ȭ�Ͽ� �Ź� �����شٸ� �� �ѹ��� for������ ���Ҽ� �ִ�.
// �� ����� ���� 3�� ������ ������.

// �ڼ��� ������ �ּ����� �����.

int board[20][20];
int N, answer = 987654321;
vector<int> first, second;

void BackTrack(int idx, int first_sum, int second_sum)
{
    // ������ ���ұ��� ����־��ٸ� �� ���� �ɷ�ġ�� ���Ͽ� �������� �����Ѵ�.
    if (idx == N)
    {
        if (!first.empty() && !second.empty())
            answer = min(answer, abs(first_sum - second_sum));
        return;
    }

    // �� ����Ͽ��� �ɷ�ġ�� �� �������� ������� �ʰ� �Ű�����ȭ�Ͽ� �׶� �׶����� �����ش�.
    int plus = 0;
    for (int i = 0; i < first.size(); ++i)
        plus += board[idx][first[i]] + board[first[i]][idx];
    first.push_back(idx);
    BackTrack(idx + 1, first_sum + plus, second_sum);
    first.pop_back();

    plus = 0;
    for (int i = 0; i < second.size(); ++i)
        plus += board[idx][second[i]] + board[second[i]][idx];
    second.push_back(idx);
    BackTrack(idx + 1, first_sum, second_sum + plus);
    second.pop_back();
}

void MakeAnswer()
{
    // 1. ��Ʈ��ŷ���� idx��° ���Ҹ� ���� ù��°, �ι�° ���� �־��.
    // 2. ���������� ��� �־����� �� ���� �ɷ�ġ�� ���̸� ���Ͽ� �������� �����Ѵ�.
    // 3. �ּҰ� ���.
    BackTrack(0, 0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}