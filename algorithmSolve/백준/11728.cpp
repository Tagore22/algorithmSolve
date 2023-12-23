#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 정렬된 두 배열을 정렬된 상태로 합치는 문제다.
// 처음에는 두 배열을 입력상태부터 합쳐서 다시 정렬했는데 그러면 굳이 정렬을 한번 더해야했다.
// 이 풀이는 두 배열을 입력받은 상태에서 정렬을 하지 않고 A와 B중의 현재 원소중 더 작은 원소를
// 최종값 answer에 추가하는 방식이다. 또한, 기존에는 이 풀이처럼 string을 사용하지 않고
// 배열을 사용하였는데 그게 훨씬 느렸다. 결과적으로 하나씩 고른것을 최종답 string answer에 추가하여
// 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board_A[1000000], board_B[1000000];
string answer;
int N, M;

void MakeAnswer()
{
    int idx_A = 0, idx_B = 0, idx = 0;
    // 총 N + M개만큼 최종답 answer에 추가한다.
    for (int iter = 0; iter < N + M; ++iter)
    {
        // A의 모든 원소를 추가하여 N번째를 가리키고 있다면
        // 더이상 A는 비교할 필요도 없다.
        if (idx_A == N)
        {
            answer += to_string(board_B[idx_B]) + " ";
            ++idx_B;
        }
        // B의 모든 원소를 추가하여 M번째를 가리키고 있다면
        // 더이상 B는 비교할 필요도 없다.
        else if (idx_B == M)
        {
            answer += to_string(board_A[idx_A]) + " ";
            ++idx_A;
        }
        // 둘다 아직 끝에 도달하지 않았다면 두 배열의 현재 원소를
        // 비교한다.
        else
        {
            // A의 원소가 더 작다면 추가한다.
            if (board_A[idx_A] > board_B[idx_B])
            {
                answer += to_string(board_B[idx_B]) + " ";
                ++idx_B;
            }
            // B의 원소가 더 작다면 추가한다.
            else
            {
                answer += to_string(board_A[idx_A]) + " ";
                ++idx_A;
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

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board_A[i];
    for (int i = 0; i < M; ++i)
        cin >> board_B[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}