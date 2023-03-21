#include <iostream>
#include <map>

using namespace std;

// 풀이.
// 예전에 비슷한 문제를 종만북에서 보고 그 풀이 비슷하게 풀어봤는데 map을 쓴대다가
// 로직도 복잡하다. 

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

            // 텅 비었다면 그냥 집어넣음.
            if (board.empty())
            {
                board.insert(make_pair(x, y));
                continue;
            }

            iter = board.lower_bound(x);

            // 바로 앞과 비교할건데 이미 맨 앞이라면 무시한다.
            if (iter != board.begin())
            {
                // 바로 앞보다 y, x 둘다 크다면 무시한다.
                cur_iter = iter;
                --cur_iter;
                if (cur_iter->second < y)
                    continue;
            }

            // 맨 뒤까지 순회하며 현재 값보다 모두 큰 원소들을 삭제한다.
            while (iter != board.end())
            {
                cur_iter = iter;
                ++iter;
                if (cur_iter->second > y)
                    board.erase(cur_iter);
                else
                    break;
            }
            // 현재 원소를 집어넣을수 있다면 집어넣는다.
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