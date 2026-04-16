// 3개의 정보가 필요하다. 
// 1. vector<set<>> [100]. 배열은 알고리즘 분류이다.
// 2. set<>. 전부 집어넣어 단순 난이도별로 정렬.
// 3. vector<set<>> [100]. 배열은 난이도이다.

#include <iostream>
#include <set>

using namespace std;

// 풀이.
// 위의 주석은 사실 멍한 상태에서 대충 구현한 틀린 정보들이다.
// 다만 그래도 남겨놓는다. 이 문제를 풀기 위해서는 어떤 자료 구조를
// 사용해서 어떤 방식으로 정렬을 하여 가장 적은 용량과 가장 빠른
// 검색 시간을 이끌어 내는가에 대한 아주 기본적인 문제 같다.
// 정답율이 보여주듯 매우 복잡한 문제였다.

int N, M, P, L, G, x;
set<pair<int, int>> board1[101]; // 알고리즘 분류별 난이도 정렬.
set<pair<int, int>> board2;      // 모든 문제를 난이도별 정렬
set<int> board3[101];            // 각 난이도 분류별 정렬.
pair<int, int> board4[100001];   // 문제 번호, 난이도, 알고리즘 분류의 매핑.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> P >> L >> G;
        board1[G].insert({ L, P });
        board2.insert({ L, P });
        board3[L].insert(P);
        board4[P] = { L, G };
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (str == "recommend")
        {
            cin >> G >> x;
            auto iter = x == 1 ? --(board1[G].end()) : board1[G].begin();
            cout << iter->second << '\n';
        }
        else if (str == "recommend2")
        {
            cin >> x;
            auto iter = x == 1 ? --(board2.end()) : board2.begin();
            cout << iter->second << '\n';
        }
        else if (str == "recommend3")
        {
            cin >> x >> L;
            bool isfind = false;
            if (x == 1)
            {
                for (int j = L; j <= 100; ++j)
                {
                    if (board3[j].size() != 0)
                    {
                        cout << *board3[j].begin() << '\n';
                        isfind = true;
                        break;
                    }
                }
                if (!isfind)
                    cout << -1 << '\n';
            }
            else
            {
                for (int j = L - 1; j > 0; --j)
                {
                    if (board3[j].size() != 0)
                    {
                        auto iter = --(board3[j].end());
                        cout << *iter << '\n';
                        isfind = true;
                        break;
                    }
                }
                if (!isfind)
                    cout << -1 << '\n';
            }
        }
        else if (str == "add")
        {
            cin >> P >> L >> G;
            board1[G].insert({ L, P });
            board2.insert({ L, P });
            board3[L].insert(P);
            board4[P] = { L, G };
        }
        else
        {
            cin >> P;
            L = board4[P].first;
            G = board4[P].second;
            board1[G].erase({ L, P });
            board2.erase({ L, P });
            board3[L].erase(P);
        }
    }
    return 0;
}