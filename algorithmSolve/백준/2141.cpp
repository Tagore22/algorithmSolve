#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 마을까지의 거리가 아닌 사람들까지의 거리이므로, 양쪽의 사람들의 수가 비슷한 마을의 위치를 찾으면 된다.
// 처음 입력시 사람의 수를 전부 더한 Sum을 저장해놓고 더 작은 위치에서부터 순회하기 위해 위치를 기준으로
// 모든 마을을 정렬한다. 각 마을을 순회하며 다시 현재 사람들의 총합 Cur을 더하는데 Cur이 Sum의
// 절반 혹은 그 이상이 되는 마을의 위치를 구하면 된다. 이때 Sum의 절반은 단순히 Sum / 2가 아닌
// (Sum + 1) / 2를 구해야하는데 Sum이 홀수일수도 있기 때문이다. 또한 Cur이 (Sum + 1) / 2와 같다는 것은
// 이 마을이 모든 사람들의 수를 양분하는 왼쪽 마을이라는 것이고 크다는 것은 가운데 마을임을 뜻한다.

// 자세한 설명은 주석으로 남긴다.

int N;
pair<int, int> Board[100000];
long long Sum = 0; // 주어지는 각 마을의 사람수가 최대 10억이므로 int값을 벗어날수 있다.

void MakeAnswer()
{
    // 더 작은 위치를 찾을수 있도록 위치를 기준으로 정렬한다.
    sort(Board, Board + N);
    long long Cur = 0;
    for (int i = 0; i < N; ++i)
    {
        // 각 마을을 순회하며 현재 총합 Cur을 구한다.
        // Cur이 Sum의 절반보다 같거나 크다면 그 위치에 우체국을 세워야한다.
        Cur += Board[i].second;
        if (Cur >= (Sum + 1) / 2)
        {
            cout << Board[i].first << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Board[i].first >> Board[i].second;
        Sum += Board[i].second;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}