#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// 풀이.
// 별 것 아닌 문제에 한가지 큰 실수를 해서 시간을 썼는데, distance를 이용한
// 두 지점간 거리를 구하는 부분이 그러하다. 뒤로 물러가는 학생들의 수는
// 끼어드는 위치로부터 맨 마지막까지 모든 학생들의 수이기에 distance의
// 두 변수는 끼어드는 위치, 맨 마지막 end()인데 거꾸로 맨 앞에서 끼어드는
// 위치의 값을 answer에 더하고 있었다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int num, answer = 0;
        cin >> num;
        // 정렬된 학생들의 위치를 저장하는 set.
        set<int> board;
        for (int i = 0; i < 20; ++i)
        {
            int cur;
            cin >> cur;

            // 현재 학생이 끼어드는 위치를 구하고 그 위치부터 맨 마지막까지의 학생수를 
            // 최종값 answer에 더한 후 set에 추가한다.
            answer += distance(upper_bound(board.begin(), board.end(), cur), board.end());
            board.insert(cur);
        }
        cout << num << ' ' << answer << '\n';
    }
    return 0;
}