#include <iostream>
#include <set>

//7662�� ������ �켱���� ť�� �ƴ� multiset���� Ǭ Ǯ��. ���� Ʈ�� ������ multiset�� ����߱⿡ 3���� Ǯ���� ���� ������.
//�ٸ� ������ ť�� 2�������Ͱ� �޸� �� Ǯ�̴� multiset�� �ϳ��� ����ϱ⿡ �޸𸮴� ���� �����.

using namespace std;

int T, k;

void MakeAnswer()
{
    multiset<int> board;
    for (int i = 0; i < T; ++i)
    {
        board.clear();
        char command;
        int num;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> command >> num;
            if (command == 'I')
            {
                board.insert(num);
            }
            else
            {
                if (!board.empty())
                {
                    if (num == 1)
                        board.erase(--board.end());
                    else
                        board.erase(board.begin());
                }
            }
        }
        if (board.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *(--board.end()) << ' ' << *board.begin() << '\n';
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