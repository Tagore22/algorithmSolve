#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ������ Ǯ���µ� ��ä���Ǿ����� Ʋ�� ��������.
// �������� �ݿø��� �ȵǾ� �ִ��� ������ 1000�� ���ؼ� �ݿø� �� �ٽ� 1000�� ������ �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int C;

void MakeAnswer()
{
    for (int iter = 0; iter < C; ++iter)
    {
        board.clear();
        int idx;
        cin >> idx;
        int sum = 0;
        for (int i = 0; i < idx; ++i)
        {
            int num;
            cin >> num;
            board.push_back(num);
            sum += num;
        }
        double aver = static_cast<double>(sum) / idx;
        int upper = 0;
        for (int i = 0; i < idx; ++i)
        {
            if (board[i] > aver)
                ++upper;
        }
        double answer = upper / static_cast<double>(idx) * 100;
        // �ٷ� �� �κ��� Ʋ�ȴ� ���ϴ�.
        // ����Ͽ��� 1000�� ���� �����δ� �Ҽ� 4��° �ڸ��� �ݿø� ����� �ǰԲ� �Ѵ�.
        answer *= 1000;
        // 4��° �ڸ��� �ݿø��ȴ�.
        answer = round(answer);
        // �ٽ� 1000�� ������ ������� �ǵ�����.
        answer /= 1000;
        cout.precision(3);
        cout << fixed;
        cout << answer << '%' << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> C;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}