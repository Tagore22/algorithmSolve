#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 내 가장 큰 단점중 하나인 어렵게 풀기에 의해 한참 헤맨 문제다.
// 처음에는 범위를 구하는 방식으로 코드도 거의 2배 가까이 길게 구현하였었는데 복잡하고 이해도 힘들었다.
// 진짜 풀이는 아주 간단했는데, 스택에 있는 문자를 현재 문자와 비교했을때 둘이 같다면 스택에 있는 문자를 비우고,
// 둘이 다르다면 스택에 현재 문자를 집어넣으면 된다. 조금 더 침착하게 임하자.

// 자세한 설명은 주석으로 남긴다.

string str;
int N;

void MakeAnswer()
{
    int answer = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;

        // 홀수라면 모든 문자들이 짝을 이룰수 없기에 답이 성립되지 않는다.
        if (str.size() % 2 == 1)
            continue;

        stack<int> sta;
        // 모든 문자들을 순회하며 스택에 있는 문자와 비교한다.
        for (int i = 0; i < str.size(); ++i)
        {
            // 스택이 비지 않았을때 스택의 문자와 현 문자가 같다면 스택의 문자를 삭제한다.
            if (!sta.empty() && sta.top() == str[i])
                sta.pop();
            // 스택이 비었거나 스택의 문자와 현 문자가 다르다면 스택에 현 문자를 집어넣는다.
            else
                sta.push(str[i]);
        }

        // 모든 순회가 끝났을때 각 문자들끼리 짝이 맞아 스택이 비었다면 좋은 단어이다.
        if (sta.empty())
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}