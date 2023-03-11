#include <iostream>

using namespace std;

// 풀이.
// 현재 막대기의 값 cur와 최종 막대기값 answer가 있을때, 이 문제에는 다음과 같은 원리가 있다.

// 1. 현재 원소값이 '('일때 cur와 answer을 1씩 증가시킨다. 
// 2. 현재 원소값이 ')'일때
// 2-1. 이 앞 원소값이 '('이라면 현재 레이져이므로 이전에 증가시켰던 cur와 answer을 다시 1씩 감소시키고
// answer을 cur만큼 증가시킨다.(레이저로 나누어짐.)
// 2-2. 이 앞 원소값이 ')'이라면 레이저가 아닌 가장 짧은 쇠막대기의 끝이기에 cur을 1 감소시킨다.

// 이 원리만 구현해내면 된다.

string str;

void MakeAnswer()
{
    int cur = 1, answer = 1;
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            ++cur;
            ++answer;
        }
        else
        {
            if (str[i - 1] == '(')
            {
                --cur;
                --answer;
                answer += cur;
            }
            else
            {
                --cur;
            }
        }
    }
    cout << answer << '\n';
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