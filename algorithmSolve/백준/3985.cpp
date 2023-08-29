#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 브론즈식으로 어렵진 않은데 나름 조건이 덕지덕지 붙은 문제다.
// 선착순으로 원하는 부분의 조각을 관객들에게 나누어 줄때 처음에 가장 많이 받게 될것으로 예상되는 관객의 번호와
// 실제로 가장 많이 받게 된 관객의 번호를 출력하는 문제다. 문제 풀이의 큰틀은 다음과 같다.

// 1. 케이크의 남은 여부를 파악하는 bool 배열 cake를 준비하여 전부 false로 초기화한다.
// 2. 관객들의 희망 번호 from ~ to를 입력받는다. 여기서 가장 많이 받게 될것으로 예상되는 답을 구할수 있다.
// to - from + 1로 예상되는 케이크 조각수를 갱신하며 첫번째 답 f_answer를 구한다.
// 3. from ~ to를 순회하며 해당 번호의 케이크가 존재하는지를 파악한다. true라면 이미 누가 받은 것이고
// false라면 받아갈수 있다. 그렇게 순회하며 실제 받은 케이크의 수로 두번째 답 s_answer를 구한다.
// 4. 최악의 순회를 할시 1000 * 1000 = 100만이므로 시간내에 충분히 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

bool cake[1001];
int L, N;

void MakeAnswer()
{
    memset(cake, false, sizeof(cake));
    int from, to, ans;
    // 조각의 수, 방청객의 번호.
    pair<int, int> f_answer = make_pair(0, -1);
    pair<int, int> s_answer = f_answer;
    for (int i = 1; i <= N; ++i)
    {
        cin >> from >> to;
        int cur = to - from + 1;
        // 가장 많이 받게 될것으로 예상되는 첫번째 답을 구한다.
        f_answer = f_answer.first < cur ? make_pair(cur, i) : f_answer;
        ans = 0;
        // from ~ to까지 순회하며 실제로 받는 케이크의 수를 구한후 실제 가장 많이 받게 되는 두번째 답을 구한다.
        for (int j = from; j <= to; ++j)
        {
            if (!cake[j])
            {
                cake[j] = true;
                ++ans;
            }
        }
        s_answer = s_answer.first < ans ? make_pair(ans, i) : s_answer;
    }
    cout << f_answer.second << '\n' << s_answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}