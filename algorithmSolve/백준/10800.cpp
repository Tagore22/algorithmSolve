#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� ���� �˰����� �ϳ� ����� ������ ���� �Ϸ����� Ǯ����.
// ���ٱ����� ���Ҵµ� �ʹ� ��ư� �����ߴ�.
// �ʹ� ��ư� �������� ����.
// ūƲ�� ������ ����.

// 1. ���� i, ũ�� j�� ���� ������ ������ �ٸ��� ũ�Ⱑ �� ���� ���� ���� ������ ȹ���Ҽ� �ִ�.
// 2. ������ ���ų� ũ�Ⱑ ���ų� �� ū ���� ������ ȹ���Ҽ� ����.

// ���� ũ�⸦ �������� ������������ ������ �������� ����� ���� ������ ����� ũ�Ⱑ ���Ҵ� ������
// ������ ������ ������ ���ϸ� �ȴ�.
// ó������ ���� ���͸� �̿��ؼ� �������� �̸� ���Ϸ��� �ߴµ� �װ� ����ġ����.
// �׳� �ִ� 20������ ��ȸ�� ���鼭 �׶��׶� ũ��� ������ �������� ������Ű�� �ȴ�.
// �ٸ� �����ؾ������� ũ��� ������ ���� ���϶��ε� �̶����� ������������ ���ĵ� �����̱⿡ �տ� ���� ���Ͽ�
// ũ��� ���� ���ٸ� �� ���� ������ ġȯ���ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int colors[200001], nums[2001];
vector<pair<pair<int, int>, int>> board; // ũ��, ��, ��ȣ;
int N;

void MakeAnswer()
{
    // ����Ͽ��� ũ�⸦ �������� �������� �����Ѵ�.
    sort(board.begin(), board.end());

    vector<int> answer(N, 0);
    int sum = 0;
    int cur_num, cur_color, cur_idx;
    for (int i = 0; i < N; ++i)
    {
        // ���� ũ��� ���� �׸��� ����.
        cur_num = board[i].first.first;
        cur_color = board[i].first.second;
        cur_idx = board[i].second;

        // ���� ���� ���Ҽ� ���� �������� �����Ѵ�.

        // 1. ������ ���� ����.
        // 2. ũ�Ⱑ ���� ����.(ũ�Ⱑ �� ū ������ �ڿ� ������ ������ �����ص� �������.)
        answer[cur_idx] = sum - colors[cur_color] - nums[cur_num];

        // ����Ͽ��� ũ��� ���� ���ٸ� �������� ���Ŀ� ���� �پ��ִ�. ���� �����غ��� �˵���
        // �ι�° ���� ���� ���� �̻��ϰ� �ȴ�. ���� ���� ��(������)���� ġȯ���ش�.
        if (i > 0 && cur_num == board[i - 1].first.first &&
            cur_color == board[i - 1].first.second)
            answer[cur_idx] = answer[board[i - 1].second];

        // �� ũ��� ���� �� ���տ� ���簪�� �����ش�.
        colors[cur_color] += cur_num;
        nums[cur_num] += cur_num;
        sum += cur_num;
    }

    for (int i : answer)
        cout << i << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int color, num;
    for (int i = 0; i < N; ++i)
    {
        cin >> color >> num;
        board.push_back(make_pair(make_pair(num, color), i));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}