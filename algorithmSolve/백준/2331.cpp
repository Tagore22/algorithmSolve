#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// 풀이.
// 이전수의 각자리값들을 P번 제곱하여 더한것이 현재수일때 반복되지 않는 원소들의 값을
// 출력하는 문제다. 딱히 그리디한 점화식이 생각나지 않아 반복하기로 하였다.
// 최대값은 아마 9999의 5인 경우가 되어 25만이 좀 안되는 수이다.
// 그 이후 수가 점점 줄어들고 늘어나기를 반복한다. 똑같은 수가 2번 나왔을때부터
// 반복이 시작되므로 그것만 확인하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int visit[250000];
int A, P;

int main()
{
    cin >> A >> P;
    // 모든 수들은 아직 방문하지 않았음.
    memset(visit, -1, sizeof(visit));
    // 0번째로 방문함.
    visit[A] = 0;
    board.push_back(A);
    int idx = 1;
    while (true)
    {
        int prev = board.back();
        int here = 0;
        // 현재수는 이전수의 각 자리값을 P번 제곱하여 더한값.
        while (prev >= 1)
        {
            here += pow(prev % 10, P);
            prev /= 10;
        }
        // 만약 현재수가 이미 방문한적 있는 수라면 방문했던 순서를 출력한다.
        if (visit[here] != -1)
        {
            cout << visit[here] << '\n';
            break;
        }
        // 현재수의 방문여부를 갱신하고 다음으로 넘어간다.
        visit[here] = idx;
        board.push_back(here);
        ++idx;
    }
    return 0;
}