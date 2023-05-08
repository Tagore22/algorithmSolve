#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ���� �ùķ��̼� ������.
// �������� �־��� �⺻���� Ʋ�� ������ ����.

// 1. ��Ʈ�� ��ĭ�� �ű��. �κ� ���� ��Ʈ�� �Բ� �̵��Ѵ�.
// 2. �κ��� ��ĭ �̵������ϴٸ� �̵��Ѵ�. �ٸ� �̵��� �ش� ĭ�� �������� 1 �پ���.
// 3. ù��° ĭ�� �������� 0�� �ƴ϶�� ���ο� �κ��� �ø���.
// 4. �������� 0�� ĭ�� K�� �̻��̶�� �׶��� ���� ����Ѵ�.

// �ٸ�, �����ؾ��� ���ǵ��� ��� �ִµ� 

// 1. N - 1ĭ(���������� N��ĭ)���� �κ��� ���޽� �ٷ� ������.

// ������ �����ؾ��Ѵ�.
// �ڼ��� ������ �ּ����� �����.

int N, K;
// ���� ĭ�� �������� �κ��� ���� ������ ����ϴ� deque��.
deque<int> board;
deque<bool> visit;

// ù��° �ܰ迡 �ش��ϴ� �̵��� �����ϴ� �Լ�.
// deque�� �̿��ϸ� �� ���� �����Ҽ� �ִ�.
void First()
{
    int cur = board.back();
    board.pop_back();
    board.push_front(cur);

    bool now = visit.back();
    visit.pop_back();
    visit.push_front(now);
    // ����Ͽ��� N - 1ĭ�� �κ��� ���޽� �ٷ� �����Ƿ�
    // � ��Ȳ������ ����־���Ѵ�.
    visit[N - 1] = false;
}

// 2 ~ 3��° �ܰ踦 �����ϴ� �Լ�.
void Second_Third()
{  
    // �ǵ�ĭ(N - 1��°ĭ)�� ������ �ٸ������� ���� �ٸ��⿡ ���� �����ߴ�.
    // ����Ͽ��� N - 1ĭ�� ������ ����־�� �ϱ� ������ ���ǹ������� ���� �ְ�
    // ���� �������� �ʾƵ� �ȴ�.
    if (visit[N - 2] && board[N - 1] > 0)
    {
        --board[N - 1];
        visit[N - 2] = false;
        if (board[N - 1] == 0)
            --K;
    }
    // ���� 3������ ���ǿ� �ش�ȴٸ� ���� �κ��� ��ġ�� ��ĭ �̵���Ŵ.
    
    // 1. ����ĭ�� �κ��� ����.
    // 2. ����ĭ�� �κ��� �������� ����.
    // 3. ����ĭ�� �������� 0���� ũ��.
    for (int i = N - 3; i >= 0; --i)
        if (visit[i] && !visit[i + 1] && board[i + 1] > 0)
        {
            --board[i + 1];
            visit[i] = false;
            visit[i + 1] = true;
            if (board[i + 1] == 0)
                --K;
        }

    // ù��°ĭ(�ø��� ��ġ)�� �������� 0���� ũ�ٸ� �κ��� �ø���.
    if (board[0] > 0)
    {
        visit[0] = true;
        --board[0];
        if (board[0] == 0)
            --K;
    }
}

void MakeAnswer()
{
    int answer = 0;
    while (K > 0)
    {
        ++answer;
        First();
        Second_Third();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int num;
    for (int i = 0; i < 2 * N; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
    visit.resize(2 * N, false);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}