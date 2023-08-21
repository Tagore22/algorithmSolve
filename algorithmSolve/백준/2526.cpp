#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Ǯ��.
// ó���� Ǯ������ �ʹ� �������̷� Ǯ����. ����Ŭ�� ���ٺ��� ���������� �ݺ��Ǵ� �κ��� ����µ�
// �̰��� �ݵ�� N * N % P, �� �ι�° ����������ϸ��� ���� �����̴�.
// �� Ǯ�̴� ��������� �� L�� ���Ϳ� �ϳ��� �߰��ϸ� bool�迭�� �ش� ���� ���忩�θ� üũ�Ѵ�.
// ����Ŭ�� ��ȸ�ϴٰ� �̹� ������ ���� �� �����Ѵٸ� ���Ϳ��� �� ���� ������ ã��
// ������ ������ ���� ���� ���� ������ ���� �������� ���Ѵ�.
// �ٸ� ���� �ʿ���� �͵��� �ϳ� ���Ҵ�. ����ȭ�� Ǯ�̴� ���� Ǯ�̿� �߰��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

bool board[97];
int N, P;

void MakeAnswer()
{
    // � �� i�� �����ߴ����� ���� ���θ� �����ϴ� bool �迭.
    memset(board, false, sizeof(board));
    board[N] = true;
    // ���±��� ������ ������ �����ϴ� ����.
    vector<int> ans;
    ans.push_back(N);
    int cur = N;
    int answer;
    // ���Ѵ�� ����Ŭ�� ��ȸ�ϴٰ� �̹� ������ ���� �� �����Ұ��
    // ���� ������ ������ �� - ���� ���� ���� ������ ����Ѵ�.
    while (true)
    {
        cur = cur * N % P;
        if (board[cur])
        {
            for (int i = 0; i < ans.size(); ++i)
                if (ans[i] == cur)
                {
                    answer = i;
                    break;
                }
            break;
        }
        else
        {
            ans.push_back(cur);
            board[cur] = true;
        }
    }
    answer = ans.size() - answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}