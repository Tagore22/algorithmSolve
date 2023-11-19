#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 주어진 문자열에 포함되어 있는 수들의 합을 출력하는 문제다.
// 첫째로 문자열 입력이 나누어져 입력되므로 while(cin >> str)을 통해
// 무작위로 이루어진 수만큼 입력받아야 했다.
// 두번째로 문자열들중에서 숫자는 콤마로 나뉘어져 있기 때문에 콤마를 발견할시 시작점부터 콤마까지
// 문자열로 변환하여 최종값 answer에 더해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, cur;
    // 문자열이 무작위수만큼 나뉘어져 입력되므로 while(cin >> str)을 사용해야 한다.
    while (cin >> str)
    {
        // 모든 입력받은 문자열을 하나로 합친다.
        cur += str;
    }

    // 시작점은 0.
    int idx = 0, answer = 0;
    // 문자열의 처음부터 끝까지 순회한다.
    for (int i = 0; i < cur.size(); ++i)
    {
        // 현재 문자가 콤마거나 맨 마지막에 도달했을때
        if (cur[i] == ',' || i == cur.size() - 1)
        {
            // 시작점부터 현재까지의 부분문자열을 정수로 변환하여 최종값 answer에 추가한다.
            answer += stoi(cur.substr(idx, i));
            // 시작점을 현재 바로 뒷칸으로 변경한다.
            idx = i + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}