#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��ü�� ������ ������. while(cin >> ����)�� ���� eofó���� �������͸� ����
// ���� X�� �Ǵ� ���̰� ���� ū �ѽ��� ã���� �Ǳ� �����̴�. �ٸ� �Ѱ��� �Ǽ��� ����
// 20���� �Ѱ� ��ǰ� ����.

// �ڼ��� ������ �ּ����� �����.

int board[1000000];
int X, N;
const int MUL = 10000000;

void MakeAnswer()
{
    // eof ó��.
    while (cin >> X)
    {
        cin >> N;
        for (int iter = 0; iter < N; ++iter)
            cin >> board[iter];
        // ��Ƽ���Ϳ��� ������ͷ��� ġȯ.
        X *= MUL;

        // �������� ó���� ���� ����.
        sort(board, board + N);
        int from = 0, to = N - 1;
        // ������� ���� ã������ while���� Ż���ؾ� �ϳ� ���� �� ����
        // while���� Ż���ϸ� �ȵǱ⿡ ���� ã�Ҵ��� ��ã�Ҵ����� ������
        // bool ������ �ϳ� �ʿ��ϴ�.
        bool bIsFind = false;
        // �̰����� �Ǽ��� �־���. �ƹ� �������� from <= to�� �����Ͽ��� �����̴�.
        // ������ ���������� ������ 2���� ������ ã�ƾ��߱� ������ from == to�� ����
        // �����ؼ��� �ȵȴ�.
        while (from < to)
        {
            // ���� X�� ������ �ѽ��� �߰��Ͽ��ٸ� ����� ���� while���� Ż���Ѵ�.
            // �������� ���̰� ���� ū �ѽ��� �䱸�Ͽ��µ� �糡���� �����ϴ� �������� Ư����
            // ���ʷ� �߰ߵ� �� �ѽ��� ���̰� ���� ũ�� �����̴�.
            if (board[from] + board[to] == X)
            {
                cout << "yes " << board[from] << ' ' << board[to] << '\n';
                bIsFind = true;
                break;
            }
            // ���� Ŭ ��� to���� �ٿ� ���糪����.
            else if (board[from] + board[to] > X)
            {
                --to;
            }
            // ���� ���� ��� from���� �÷� ���糪����.
            else
            {
                ++from;
            }
        }
        // ��� ��ȸ ���� ���� ã�� ������ ���.
        if (!bIsFind)
            cout << "danger" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}