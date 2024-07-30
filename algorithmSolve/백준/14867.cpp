#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 풀이.
// 어렵진 않았는데 한가지 함정같은게 있는 문제였다. 결과적으로 BFS 순회를 하면 끝나는 문제다.
// 다만 a와 b의 최대값이 10만이라 10만 * 10만을 하면 100억으로 시간초과나 메모리초과가 일어나기 때문에
// 다른 방법을 찾아야한다. 실제로 연산등을 보면 a를 꽉채우거나 a를 0으로 만들거나, b를 꽉채우거나 b를 비우는
// 경우들이다. 따라서 실제로 100억을 모두 사용하지는 않는다. 결과적으로 배열이 아닌 map이나 set같은 연관 컨테이너를
// 사용해야 했다. 다른 훨씬 더 빠른 풀이도 있는데 그건 뭔지도 모르겠고 출제 의도가 아닌것 같기도 하고.

// 자세한 설명은 주석으로 남긴다.

int a, b, c, d;

// 모든 경우를 확인하는 BFS 순환 함수.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    // 배열을 사용할수 없어 연관 컨테이너를 사용해야한다.
    set<pair<int, int>> visit;
    visit.insert(make_pair(0, 0));
    int answer = -1;

    while (!que.empty())
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y == c && x == d)
            {
                cout << answer << '\n';
                return;
            }

            // a 처리.
            if (visit.find(make_pair(a, x)) == visit.end())
            {
                que.push(make_pair(a, x));
                visit.insert(make_pair(a, x));
            }
            if (visit.find(make_pair(0, x)) == visit.end())
            {
                que.push(make_pair(0, x));
                visit.insert(make_pair(0, x));
            }
            int ny = b - x >= y ? 0 : y - b + x;
            int nx = b - x >= y ? y + x : b;
            if (visit.find(make_pair(ny, nx)) == visit.end())
            {
                que.push(make_pair(ny, nx));
                visit.insert(make_pair(ny, nx));
            }
            // b 처리.
            if (visit.find(make_pair(y, b)) == visit.end())
            {
                que.push(make_pair(y, b));
                visit.insert(make_pair(y, b));
            }
            if (visit.find(make_pair(y, 0)) == visit.end())
            {
                que.push(make_pair(y, 0));
                visit.insert(make_pair(y, 0));
            }
            ny = a - y >= x ? y + x : a;
            nx = a - y >= x ? 0 : x - a + y;
            if (visit.find(make_pair(ny, nx)) == visit.end())
            {
                que.push(make_pair(ny, nx));
                visit.insert(make_pair(ny, nx));
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

int main()
{
    cin >> a >> b >> c >> d;
    MakeAnswer();
    return 0;
}