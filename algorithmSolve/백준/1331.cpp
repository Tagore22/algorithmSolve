#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 각 이동이 가로세로 총 2칸, 1칸씩 움직여 나이트의 이동이 맞는지 확인하고
// 각 칸에 단 한번씩만 방문했는지, 마지막 이동에서 시작점으로 돌아올 수 있는지 등
// 확인할게 많은 문제였기에 코드가 꽤나 길어졌다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string prev = "", str;
    bool isanswer = true;
    bool visit[6][6] = { false, };
    for (int iter = 0; iter < 36; ++iter)
    {
        string cur;
        cin >> cur;

        // 현재 위치의 좌표값을 계산.
        int firstidx = cur[0] - 'A';
        int secondidx = cur[1] - '1';
        if (prev == "")
        {
            prev = cur;
            str = prev;
            visit[firstidx][secondidx] = true;
            continue;
        }

        // 가로, 세로의 이동칸 계산.
        int first = abs(cur[0] - prev[0]);
        int second = abs(cur[1] - prev[1]);
        // 나이트의 움직임이 맞는지, 중복 방문했는지 확인.
        if (!((first == 2 && second == 1) || (first == 1 && second == 2)) ||
            visit[firstidx][secondidx])
            isanswer = false;

        // 기존값을 교체하고 방문 여부를 수정한다.
        prev = cur;
        visit[firstidx][secondidx] = true;
    }
    // 맨 마지막 지점에서 시작 지점으로 되돌아올 수 있는지 확인.
    int first = abs(str[0] - prev[0]);
    int second = abs(str[1] - prev[1]);
    if (!((first == 2 && second == 1) || (first == 1 && second == 2)))
        isanswer = false;
    cout << (isanswer ? "Valid" : "Invalid") << '\n';
    return 0;
}