#include <iostream>
#include <string>

using namespace std;

//1206���� Ǯ���� 0~�ο��� * 10�� for���� �̺�Ž������ ��ȯ�� Ǯ��. �ִ� 100�� �ۿ� ��ȸ���� �ʱ⿡ ������ ���� 20��� ��������.

int board[50];
int N;

void MakeAnswer()
{
    for (int i = 1; i <= 1000; ++i)
    {
        int find_num = 0;
        for (int j = 0; j < N; ++j)
        {
            int lo = -1, hi = i * 10 + 1, mid;
            for (int iter = 0; iter < 100; ++iter)
            {
                mid = (lo + hi) / 2;
                if (mid * 1000 / i > board[j])
                {
                    hi = mid;
                }
                else if (mid * 1000 / i < board[j])
                {
                    lo = mid;
                }
                else
                {
                    ++find_num;
                    break;
                }
            }
        }
        if (find_num == N)
        {
            cout << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board[i] = stoi(str.substr(str.find('.') + 1));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}