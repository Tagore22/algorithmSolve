#include <iostream>

using namespace std;

// 풀이.
// 단순한 구현이지만 구현하게 많은 복잡한 문제였다. 현재 거북이의 위치, y축과 x축의 최소값과 최대값
// 현재 방향등이 그러했다. 집중해서 풀면 어려울건 없었다.

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        string str;
        cin >> str;
        int curdir = 0, y = 0, x = 0, maxy = 0, miny = 0, maxx = 0, minx = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == 'F')
            {
                y += dir[curdir][0];
                x += dir[curdir][1];
                maxy = max(maxy, y);
                maxx = max(maxx, x);
                miny = min(miny, y);
                minx = min(minx, x);
            }
            else if (str[i] == 'B')
            {
                y += dir[(curdir + 2) % 4][0];
                x += dir[(curdir + 2) % 4][1];
                maxy = max(maxy, y);
                maxx = max(maxx, x);
                miny = min(miny, y);
                minx = min(minx, x);
            }
            else if (str[i] == 'L')
            {
                curdir = (curdir + 3) % 4;
            }
            else
            {
                curdir = (curdir + 1) % 4;
            }
        }
        cout << (maxy - miny) * (maxx - minx) << '\n';
    }
    return 0;
}