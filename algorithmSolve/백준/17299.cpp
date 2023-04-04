#include <iostream>
#include <stack>

using namespace std;

// Ǯ��.
// ���������� for���� 2�� ��ø�Ͽ� Ǯ�� �ִ� 100�� * 100������ �ð��� ���� �Ѿ�⿡ Ǯ�� ����. 
// �׷��� ������ ����Ͽ� ���� ����ū������ ��鼭 �ִ� 100������ ��ȸ�Ͽ��� �Ѵ�.
// �� ������ ��� �� ��(������)���� ��ȸ�ϱ� �����ϴµ� ���þȿ� �� ���� ����Ƚ����
// ���� i��° ���Һ��� Ŭ������ ��� ����. �׸��� ���� �� �� ���ð��� ���� �����̸鼭
// ����Ƚ���� ū �� ��, ����ū���̴�. �ٸ� ������ ����ٸ� ����ū���� �������� �ʱ⿡
// -1�� �������ָ� �ȴ�.

int board[1000000], nums[1000001], answer[1000000];
int N;

void MakeAnswer()
{
    // �ֺ� ������ ���ϰ� �ڿ������� N����ŭ ��ȸ�Ѵ�.
    stack<int> sta;
    for (int i = N - 1; i >= 0; --i)
    {
        // ������ ��ų� �� ���� ������ ����Ƚ���� ���� i��° ������ ����Ƚ������ Ŭ������ ����.
        while (!sta.empty() && nums[sta.top()] <= nums[board[i]])
        {
            sta.pop();
        }

        // ������ ����ٸ� ����ū���� �������� �ʱ⿡ -1��, �׷��� �ʴٸ� ����ū���� ���ҹ�ȣ�� �����Ѵ�.
        answer[i] = sta.empty() ? -1 : sta.top();
        sta.push(board[i]);
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        ++nums[board[i]];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}