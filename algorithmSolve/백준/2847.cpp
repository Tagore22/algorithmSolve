#include <iostream>

using namespace std;

// 풀이.
// 각 레벨을 클리어 할시 얻을수 있는 점수들을 줄일때 오름차순으로 만들수 있는 최소한의 점수를 출력하면 된다.
// i번을 클리어할때 얻는 점수는 i + 1번을 클리어할때 얻는 점수보다 작아야하므로 맨 뒤부터 순회하며
// 현재 점수보다 최소한으로 작게끔 줄여나가면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 현재 점수들을 입력받는다.
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    // 맨뒤부터 오름차순이 되게끔 최소한으로 줄인다. 
    int here = board[N - 1], answer = 0;
    for (int i = N - 2; i >= 0; --i)
    {
        // 현재 점수가 기존점수보다 크거나 같다면 점수를 줄인다.
        if (board[i] >= here - 1)
        {
            // 최소한으로 줄여야하므로 기존점수 - 1까지 줄이고 줄인만큼 최종값 answer에 더한다.
            answer += board[i] - here + 1;
            // 기존점수는 1만큼 줄어든다.
            here -= 1;
        }
        // 기존점수보다 작다면 굳이 줄일필요가 없다.
        else
        {
            // 현재점수가 기존점수가 된다.
            here = board[i];
        }
    }
    cout << answer << '\n';
    return 0;
}