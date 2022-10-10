#include <iostream>
#include <set>

//7662번 문제를 우선순위 큐가 아닌 multiset으로 푼 풀이. 이진 트리 형식의 multiset을 사용했기에 3가지 풀이중 가장 느리다.
//다만 기존의 큐가 2개였던것과 달리 이 풀이는 multiset을 하나만 사용하기에 메모리는 적게 사용함.

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