#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 문제를 읽어봤을때 스택을 이용해서 풀어야 한다는 느낌이 왔다. 다만 스택을 이용한 문제는 정형화되기에는
// 가지수가 매우 많아서 약간 이것저것 생각을 해야했기에 시간이 꽤 걸렸다. 다만 정답율이 35퍼밖에 안되는 문제이기에
// 너무 신경쓰지 말자. 경험에서 느꼈듯이 뒤에서부터 순회를 해야 한다. 왜냐하면 왼쪽에서 오른쪽 즉, 0번째부터 쳐다보기
// 때문에 N - 1번째는 볼수 있는 건물이 0임이 확정되기 때문이다. 따라서 N - 1번째부터 0번째까지 역순으로 순회하되,
// 스택에 있는 원소들중 현재 idx번째 건물보다 낮은 건물들의 수와 그 건물들이 보는 수들을 모두 더해가며 스택에 추가해야한다.
// 그러면서 도중에 볼수 있던 건물들의 수를 모두 더하여 출력하면 된다. 한가지 실수를 했는데 각 건물에서 볼수 있는 최대 개수는
// 79999 + 79998 .... 0까지 해서 int값을 벗어날수 있다. 따라서 모두 더하는 최종값 answer는 long long변수가 되어야 했다.

// 자세한 설명은 주석으로 남긴다.

int board[80000];
int N;

void MakeAnswer()
{
    // 각각 인덱스값, 볼수 있는 건물의 수를 뜻한다.
    stack<pair<int, int>> sta;
    // 상술한대로 볼수 있는 모든 건물의 수는 int값을 벗어날수도 있기에 long long 변수.
    long long answer = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        // 최초값은 볼수 없는 상황이 있기에 0으로 초기화한다.
        int cur = 0;
        while (true)
        {
            // 스택이 비었거나, idx번째 건물보다 스택의 맨 위값이 크거나 같다면 볼수 없기에 반복문을 탈출한다.
            if (sta.empty() || sta.top().first >= board[i])
                break;
            // 자신보다 낮은 건물이 볼수 있는 수 + 1. + 1은 그 건물 자체가 idx번째 건물보다 낮기에 그 건물 자체를
            // 더해줌.
            cur += sta.top().second + 1;
            // 추가된 건물들은 스택에서 삭제된다.
            sta.pop();
        }
        // 새로이 더 높은 건물과 그 건물에서 볼수 있는 수가 추가된다.
        sta.push(make_pair(board[i], cur));
        // 모든 건물에서 볼수 있는 건물의 수 answer에 idx번째 건물에서 볼수 있는 값 cur이 추가됨.
        answer += cur;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}