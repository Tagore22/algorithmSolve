#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 평범한 스택 문제다. 다만 처리해야할 스택이 여러개이다.
// 그럼에도 불구하고 애시당초 문제에서 줄은 최대 6개라는 것을 제시해놓았으므로
// 최대 스택의 개수는 정해져 있어 그리 어렵지 않다.
// 최대 스택을 6개 만들어놓고 각 줄의 번호를 스택의 번호와 동일시하여 
// 프랫의 번호가 현재 스택의 프랫보다 크거나, 원래 해당 줄의 스택이 비어있었다면 그냥 누르면(스택에 저장) 된다.
// 하지만 현재 프랫이 스택에 저장된 프랫보다 작다면 현재 프랫이 같거나 커질때까지 스택의 프랫을 버려가며
// 누르는 것을 떼야하니 최종답을 하나씩 늘린다. 그 후 버릴만큼 버렸을때 현재 프랫과 스택의 프랫이 같다면
// 무시하면 되고 현재 프랫이 더 크다면 위와 마찬가지로 다시 수를 1을 늘린다.
// 이를 반복하여 최종답을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N, P;

void MakeAnswer()
{
    int answer = 0;
    stack<int> sta[7];
    // 총 음의 개수만큼 반복한다.
    for (int i = 0; i < N; ++i)
    {
        int s, p;
        cin >> s >> p;

        // 현재 줄의 스택이 비거나, 현재 프랫이 스택의 프랫보다
        // 크거나 같을때까지 스택의 프랫을 버리며 줄을 떼기에 최종답 answer의 값을
        // 1씩 늘려간다.
        while (!sta[s].empty() && sta[s].top() > p)
        {
            ++answer;
            sta[s].pop();
        }

        // 버릴만큼 모두 버렸을때 스택이 비었거나 현재 프랫이 스택의 현재 프랫보다
        // 클때 그 프랫을 누르며 answer의 값을 1 늘린다.
        if (sta[s].empty() || sta[s].top() < p)
        {
            sta[s].push(p);
            ++answer;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}