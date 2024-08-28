#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 정답율이 54퍼라고는 믿을수 없을정도로 나한텐 어려운 문제였다. 결국 풀이를 보고 말았다. 얼추 비슷하긴 한데
// 풀이 과정 자체를 조금 혼동했다. 아닌가 떠올릴수 없었다. 생각을 해보자. 루트에서 모든 리프까지의 길이가 같으려면
// 결과적으로 양쪽 리프의 가중치가 동일해야 한다. 왜냐하면 루트부터 현재 노드까지의 거리는 단 하나고 현재 노드의
// 두 자식 노드까지의 거리가 같기 위해서는 다시 두 가중치가 동일해야 하기 때문이다. 즉 리프부터 루트까지 올라가면서
// 두 가중치를 비교하고 더 큰 가중치로 갱신후 그 가중치들을 모두 더해주면 된다. 요즘 따라 알고리즘 풀때 머리가
// 맑지 않다. 늦게 자서 그런가. 일찍 자자.

// 특히 이번 문제는 포화이중트리의 특성을 이용한 풀이기에 매우 강력하다. 잘 기억해두자.

// 자세한 설명은 주석으로 남긴다.

// 비트마스크를 이용하여 배열의 길이값을 구한다. 매우 간단하면서도 강력하다. 잘 기억해두자.
int board[1 << 21];
int k, limit, sum = 0;

int SumToLeaf(int idx)
{
    // 더이상 자식 노드가 존재하지 않을때에는 현재 가중치를 저장하고 반환한다.
    if (idx * 2 >= limit)
    {
        sum += board[idx];
        return board[idx];
    }

    // 중요한 부분 1. 나는 원래 시작점을 0으로 두고 왼쪽 노드는 idx * 2 + 1로, 오른쪽 노드는 idx * 2 + 2로 했는데
    // 밑에서 보면 알겠지만 원소개수를 찾기가 쉽지 않다. 따라서 시작점을 1로 두고 왼쪽을 idx * 2로, 오른쪽을 idx * 2 + 1로 해야
    // 했다.
    int left = SumToLeaf(idx * 2);
    int right = SumToLeaf(idx * 2 + 1);
    // 현재 가중치를 총값에 더해주고 추가로 자식 노드들의 가중치의 차이값을 더해준다.
    sum += abs(left - right) + board[idx];
    // 리프부터 총 가중치를 더해나간다.
    return board[idx] + max(left, right);
}

void MakeAnswer()
{
    // 중요한 부분 2. 상술하였듯 시작점은 0이 아닌 1이 된다.
    SumToLeaf(1);
    // 총 가중치를 출력한다.
    cout << sum << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    // 상술한 비트마스크를 이용한 부분과 일치한다. 
    limit = 1 << (k + 1);
    // 시작점이 1번이기에 무시하고 2번부터 입력받는다.
    for (int i = 2; i < limit; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}