#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

// 풀이.
// 자료구조를 얼마나 잘 다루느냐에 대한 문제였던듯 싶다. recommend와 add까지는
// 정렬된 컨테이너를 사용하면 되기에 크게 어렵지 않았다. 다만 solved에서 막혔는데
// 기존에 정렬은 (난이도, 문제 번호) 순인데 갑자기 문제 번호를 기준으로 찾아야 했기
// 때문이다. 결국은 unordered_map을 이용하여 문제번호를 기준으로 난이도를 매핑시켜
// 해결할 수 있었다.

int N, M;
set<pair<int, int>> board;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int P, L;
        cin >> P >> L;
        board.insert(make_pair(L, P));
        // 상술한대로 문제 번호를 기준으로 난이도를 매핑함.
        um[P] = L;
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (str == "recommend")
        {
            int x;
            cin >> x;
            set<pair<int, int>>::iterator iter;
            if (x == 1)
            {
                iter = board.end();
                --iter;
            }
            else
            {
                iter = board.begin();
            }
            cout << iter->second << '\n';
        }
        else if (str == "add")
        {
            int P, L;
            cin >> P >> L;
            board.insert(make_pair(L, P));
        }
        else
        {
            int P;
            cin >> P;
            pair<int, int> erase_idx = make_pair(um[P], P);
            board.erase(erase_idx);
            um.erase(P);
        }
    }
    return 0;
}