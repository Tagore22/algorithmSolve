#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 언제나 그렇듯 생각해보면 그리 어려운 문제는 아닌데 왜 생각을 못했을까. 조금 빡친다.
// 그러니까 자세히 써보자. 처음에는 3차원 배열을 사용하려고 했다. 하지만 불가능했다. 500 * 500 * 500이 너무 커서
// 배열화 할수 없었기 때문이다. 그럼 2차원 배열을 써야했는데 여기서 문제였다. 3개중 2개만을 확인하여 어떻게 결론을
// 내릴 것인가. 결국 찾을수 없었고 다른이들이 푼걸 봤는데 어이가 없었다. 나머지 한개는 주어진 수들의 총합에서 앞선
// 2개를 뺀값이었다. 하하. 다음엔 좀 더 집중해서 더 여러가지 가능성을 찾아보자.

// 자세한 설명은 주석으로 남긴다.

// 처음에는 bool 배열의 길이가 [1000][1000]이면 된다고 생각했다. 왜냐하면 가장 작은수의 가장 큰수는
// 498이기에 2배가 되어도 1000보다 낮기 때문이다. 하지만 틀렸다. 주어지는 수의 최대값이 500이기에
// 총합의 최대는 1500이 된다. 다른 두 수가 가장 적다면 1이 되기 때문에 1000으로는 부족하다.
bool check[1500][1500] = { false, };
int board[3];
int sum = 0;

// 모든 결과를 순회하는 BFS함수.
void BFS()
{
    // 상술한대로 2가지만 가직고 있으면 된다. 나머지 하나는 총합에서 앞선 2가지 수를 뺀다.
    queue<pair<int, int>> que;
    que.push(make_pair(board[0], board[1]));
    // 초기값은 이미 방문한 상태.
    check[board[0]][board[1]] = true;

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        // 상술한대로 2가지 수를 가지고 3가지 수를 만든다. 이 부분이 핵심인듯.
        int now[3] = { x, y, sum - x - y };

        // 만약 첫번째 수와 두번째 수가 총합 / 3이라면 현재가 같은 개수로 되어있는 상태이다. 그러므로 1을 출력하고
        // 탈출한다. 하술하겠으나 총합이 3의 배수가 아닌 경우는 애시당초 답이 될수 없다. 3개로 나눌수 없기 때문이다.
        if (now[0] == sum / 3 && now[1] == sum / 3)
        {
            cout << 1 << '\n';
            return;
        }

        // 모든 수들을 순회하며 자신보다 큰수를 찾는다. 그때 돌의 수를 계산한후 방문하지 않았다면 순회에 포함시킨다.
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (now[i] < now[j])
                {
                    int min = now[i] * 2;
                    int max = now[j] - now[i];
                    if (!check[min][max])
                    {
                        check[min][max] = true;
                        que.push(make_pair(min, max));
                    }
                }
    }
    // 아직 탈출하지 못했다면 불가능한 경우이므로 0을 출력한다.
    cout << 0 << '\n';
}

void MakeAnswer()
{
    // 상술한대로 모든 돌의 수를 3으로 나누어야 하기 때문에
    // 총합이 3의 배수가 아니라면 절대 답이 될수 없다.
    if (sum % 3 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    BFS();
}

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
    MakeAnswer();
    return 0;
}