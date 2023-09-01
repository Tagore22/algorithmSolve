#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 수들을 이용하여 가장 큰 30의 배수를 출력하는 문제이다.
// 처음에는 만들수 있는 모든 수를 만들어 string을 int로 변환하여 30으로 나누는 풀이를 생각했는데
// 그렇게 하면 만들수 있는 모든 수를 만드는것부터 시간이 너무 많이 들었다.
// 한가지 규칙이 존재하였는데 3의 배수는 각 자리의 수를 모두 더해서 3의 배수라는 것이다.
// 또한, 3이 아닌 30이기에 맨 뒷자리가 0이여야 한다. 따라서 다음과 같은 규칙이 존재한다.

// 1. 맨 뒷자리가 0이다.
// 2. 각 자리수의 합이 3의 배수이다.

// 이 규칙을 통과한다면 30의 배수이고 그렇지 않다면 아닌 것이다.
// 구현 자체는 어렵지 않다.

// 자세한 설명은 주석으로 남긴다.

string str;

void MakeAnswer()
{
    // 먼저 맨 마지막에 0이 오는지 알기 위해 내림차순으로 정렬한다.
    sort(str.begin(), str.end(), greater<>());
    int ssize = str.size();

    // 맨 뒷자리가 0이 아니라면 조건에 맞지 않으므로 -1을 출력.
    if (str[ssize - 1] != '0')
    {
        cout << -1 << '\n';
        return;
    }

    // 모든 자리수의 합을 구한다.
    int sum = 0;
    for (auto c : str)
        sum += c - '0';

    // 합이 3의 배수라면 30의 배수이고 그렇지 않다면 아니다.
    if (sum % 3 == 0)
        cout << str << '\n';
    else
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}