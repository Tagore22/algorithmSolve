#include <iostream>

using namespace std;

// 풀이.
// 처음에는 각 저장된 내용들을 정렬할 생각을 했었는데, 다시 생각해보면 그럴 필요가 없다.
// 매번 입력은 무조건 받아야하기에 그 상태에서 매번 최대량을 갱신해나가면 된다.
// 아직도 어렵게 푸는 방식이 몸에 밴것 같다. 고쳐나가자.

// 자세한 설명은 주석으로 남긴다.

int T, N;

void MakeAnswer()
{
    // 매번 갱신해나가는 최종값 answer.
    pair<string, int> answer = make_pair("", 0);
    // 현재값을 저장하는 cur.
    pair<string, int> cur;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // N번의 입력을 받되 저장할 필요없이 매번 입력받을때마다 최종값을 갱신해나간다.
        for (int i = 0; i < N; ++i)
        {
            cin >> cur.first >> cur.second;
            answer = answer.second < cur.second ? cur : answer;
        }
        cout << answer.first << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}