#include <iostream>
#include <map>

using namespace std;

// Ǯ��.
// ������ ����� ������ �����Ͽ��� ���� �� Ǯ�� ����ϰ� Ǯ��ôµ� map�� ����ٰ�
// ������ �����ϴ�. 

map<int, int> board;
int T, N;

void MakeAnswer()
{
    int x, y;
    map<int, int>::iterator iter, cur_iter;
    for (int i = 0; i < T; ++i)
    {
        board.clear();
        cin >> N;
        for (int j = 0; j < N; ++j)
        {
            cin >> x >> y;

            // �� ����ٸ� �׳� �������.
            if (board.empty())
            {
                board.insert(make_pair(x, y));
                continue;
            }

            iter = board.lower_bound(x);

            // �ٷ� �հ� ���Ұǵ� �̹� �� ���̶�� �����Ѵ�.
            if (iter != board.begin())
            {
                // �ٷ� �պ��� y, x �Ѵ� ũ�ٸ� �����Ѵ�.
                cur_iter = iter;
                --cur_iter;
                if (cur_iter->second < y)
                    continue;
            }

            // �� �ڱ��� ��ȸ�ϸ� ���� ������ ��� ū ���ҵ��� �����Ѵ�.
            while (iter != board.end())
            {
                cur_iter = iter;
                ++iter;
                if (cur_iter->second > y)
                    board.erase(cur_iter);
                else
                    break;
            }
            // ���� ���Ҹ� ��������� �ִٸ� ����ִ´�.
            board.insert(make_pair(x, y));
        }
        cout << board.size() << '\n';
    }
}


void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}