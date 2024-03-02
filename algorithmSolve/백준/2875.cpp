#include <iostream>

using namespace std;

// 풀이. 
// 다 잘 구현했었으나 K 부분을 예시의 2로 구현해놓았었다.
// 남학생, 여학생에게 총 K만큼의 수를 빼야하기 때문에
// 0 ~ K만큼 순회하며 각각 대응대는 수를 빼고 여학생 / 2와 남학생의 수중
// 더 작은 수가 현재 만들수 있는 팀의 수이며, 그 수들의 최대값을 출력하면 된다.

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int answer = 0;
    for (int i = 0; i <= K; ++i)
    {
        int dn = N - i;
        int dm = M - K + i;
        answer = max(answer, min(dn / 2, dm));
    }
    cout << answer << '\n';
    return 0;
}