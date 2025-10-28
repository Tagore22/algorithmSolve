#include <iostream>

using namespace std;

// 풀이.
// 그다지 어려운 문제는 아니었다. 투 포인터를 이용한 범위 로직까지는 잘 짰으나
// 범위를 좁히는 방식에서 시간이 많이 걸렸다. 예를 들어 예시로 주어진 2, abbcaccba를 보면
// 범위를 caccb로 할 때, 알파벳의 종류가 3가지이기 때문에 맨 앞에 있는 c를 제거해야한다.
// 이 때의 로직이 애매했는데 기존에는 from ~ to - 1까지 존재하는 str[from]을 모두 찾아
// 그 위치 + 1을 from으로 바꾸었으나 전혀 답이 되질 않았다. 진짜 방식은 isvisit을 bool이 아닌
// int로 구현하여 각 알파벳의 등장 횟수를 저장하면 되었다. 다시 위 예제를 보면 c는 전혀 상관없이
// a가 지워졌을 때 알파벳의 종류가 2가지로 줄어든다. 따라서 b에서 시작하는 것이 아니라 두번째 c에서
// 새로운 범위가 시작되는 것이었다. 

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string str;
    cin >> N >> str;
    int from = 0, to = 0, ssize = str.size(), answer = 0, num = 0;
    int isvisit[26] = { 0, };

    while (to < ssize)
    {
        // to를 체크한다. 만약 처음 등장한다면 새로운 알파벳의 종류가 하나 늘어난다.
        num = isvisit[str[to] - 'a'] == 0 ? num + 1 : num;
        ++isvisit[str[to] - 'a'];

        // 알파벳의 종류를 N 미만까지 줄인다.
        while (num > N)
        {
            // 상술한 예시의 방식이다. 각 알파벳의 등장횟수를 하나씩 줄여가되,
            // 어떤 알파벳의 등장 횟수가 0이 된다면 num이 1씩 줄어든다.
            --isvisit[str[from] - 'a'];
            num = isvisit[str[from] - 'a'] == 0 ? num - 1 : num;
            ++from;
        }
        answer = max(answer, to - from + 1);
        ++to;
    }
    cout << answer << '\n';
    return 0;
}