#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ó���� Ǯ�̸� ����ġ ���ؼ� ��Ʈ�� �ôµ� �������Ͱ� �־���. �� ���ķ� �������Ϳ� �����ϰ� �Ǿ
// �̹� �����س´� Ǯ�̸� �Ѱܹ����� �Ǽ��� ��������. Ǯ�̴� �̷��ϴ�. 

// 1. �� �ݿ��� ���� ���� �ɷ�ġ�� �л����� ��� �ִ밪 - �ּҰ��� ���Ѵ�.
// 2. ���� �ִ� �ɷ�ġ�� �л��� �����ϰ� �� ���� �� �������� ���� �ɷ�ġ�� �л��� ���Խ��� �ٽ� �ִ밪 - �ּҰ��� ���Ѵ�.
// 3. ���� �ݺ��ϴٰ� ���̻� �л��� �������� �ʴ� ���� �����Ѵٸ� ���±����� �ּҰ��� ����Ѵ�.

// �߰����� �߿����� �ʰ� �ִ밪�� �ּҰ����� �߿��ϱ� ������ �Ź� �ִ밪�� ���� �л��� �ٲپ��ָ� �ȴ�.
// �ð� ���⵵�� ���ʿ� ��� ���� �л����� �����ϴµ� NMlogM + ��� �л����� ���Խ�Ű�µ� NM * �� ���� ť���� �����µ�
// logM�� ��⿡ 2NMlogM�� �ɸ���. 2 * 1000 * 1000 * 9.99..���� 2õ���� ���귮�� ����ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N, M, minnum = 9876543211, answer = 9876543211;
priority_queue<int> board[1000];
priority_queue<pair<int, int>> ans;

void MakeAnswer()
{
    // ������ �л����� ���Խ�Ų��. �켱���� ť�� �� ���� �˾Ƶ� �� �Ʒ��� �˼� ���⿡
    // ���� �ּҰ��� ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        int here = board[i].top();
        minnum = min(minnum, here);
        board[i].pop();
        ans.push(make_pair(here, i));
    }
    while (true)
    {
        // �ִ밪�� �ּҰ��� ���̸� ���Ѵ�.
        pair<int, int> here = ans.top();
        ans.pop();
        answer = min(answer, here.first - minnum);

        int idx = here.second;
        // ���� ���� ���� ū �л��� �ݿ� ���̻� �л��� �������� �ʴ´ٸ� while���� Ż���Ѵ�.
        if (board[idx].empty())
            break;
        // �ش� �ݿ��� �� �������� ���� �л��� ���Խ�Ų��.
        int now = board[idx].top();
        minnum = min(minnum, now);
        board[idx].pop();
        ans.push(make_pair(now, idx));
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int now;
        for (int j = 0; j < M; ++j)
        {
            cin >> now;
            board[i].push(now);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}