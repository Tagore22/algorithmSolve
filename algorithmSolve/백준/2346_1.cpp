#include <iostream>
#include <deque>

using namespace std;

// 2346번의 덱으로 푼 풀이.
// 더 깔끔하고 좋은 풀이인것 같다.
// 처음엔 덱으로 어떻게 풀지 한참 고민했는데 그냥 빙그르르 돌면서 삭제 및 삽입이었다.

// 자세한 설명은 주석으로 남긴다.

deque<pair<int, int>> board;
int N;

void MakeAnswer()
{
    while (!board.empty())
    {
        // 이동값을 저장한후 현재 번호를 출력한다. 그리고 삭제한다.
        cout << board.front().first << ' ';
        int cost = board.front().second;
        board.pop_front();

        if (board.empty())
            break;

        // 이동값이 양수라면 이전에 삭제하면서 한번 이동했기에 cost - 1만큼만 맨 앞값을
        // 맨 뒤로 옮긴다.
        if (cost > 0)
        {
            for (int i = 0; i < cost - 1; ++i)
            {
                pair<int, int> cur = board.front();
                board.push_back(cur);
                board.pop_front();
            }
        }
        // 이동값이 음수라면 cost만큼 맨 뒷값을 맨 앞으로 옮긴다.
        else
        {
            for (int i = 0; i < -1 * cost; ++i)
            {
                pair<int, int> cur = board.back();
                board.push_front(cur);
                board.pop_back();
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        board.push_back(make_pair(i, num));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}