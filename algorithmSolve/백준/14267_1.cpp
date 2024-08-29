#include <iostream>

using namespace std;

// 14267번의 더 빠르고 메모리도 적게 차지하는 상위호환 풀이.
// 트리의 원리를 잘 생각해보면 DFS 순회를 만들필요도, vector를 사용할 필요도 없다.
// 어디까지나 부모에서 자식으로 내려가면서 칭찬값을 증가시키기만 하면 되기 때문이다.
// 따라서 기존처럼 vector에 자식값들을 모두 저장하는 것이 아닌 부모의 인덱스값만을
// 저장하여 모든 원소들을 순회하며 부모값만큼 증가시키기만 하면 된다. 문제에서 주어지듯
// 모든 자식 노드는 부모 노드보다 번호가 크기 때문이다.

// 자세한 설명은 주석으로 남긴다.

// 상술한대로 vector가 사라져 메모리가 크게 줄었다.
int p[100001], answer[100001];
int N, M;

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        // 1번은 사장이기 때문에 값을 증가할수가 없다.
        // 또한 사장의 부모는 -1이기 때문에 이것을 조건문으로 처리해주지 않으면
        // 오류가 난다.
        if (i > 1)
            // 현재 칭찬값은 부모 노드의 칭찬값만큼 증가한다.
            answer[i] += answer[p[i]];
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        answer[i] = 0;
    int a;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a;
        // 기존처럼 vector에 자식값들을 저장하는 것이 아닌
        // 부모값만을 저장하기에 vector를 사용하지 않고 int 배열만을 사용할수 있다.
        p[i] = a;
    }
    int b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        answer[a] += b;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}