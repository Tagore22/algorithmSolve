#include <iostream>

using namespace std;

// 풀이.
// 처음에는 아무 생각없이 M번의 for문에서 N번의 배열값들을 변동시키게끔 구현하였다.
// 이러면 연산량은 N * M이 되는데 N, M의 최대값은 10만이다. 따라서 100억이라는 연산량이 나오게 되어
// 시간초과를 피할수 없게 된다. 문제를 잘 이해하면 아래와 같은 다른 풀이를 도출할수 있는데,
// queue는 입력값을 기존에 가지고 있던 값과 바꾸고, stack은 무시하게 된다. 결과적으로 기존의 queue에 있던
// 값들이 뒤에서부터 하나씩 출력된다. 그 이후에는 입력받은 값들이 다시 queue에 들어가고 출력된다.
// 즉, 기존의 queue에 있던 값들을 뒤에서부터 출력하고 그 이후 M번 입력받은 값들을 순서대로 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

bool isStack[100000];
int board[100000], answer[100000];
int N, M, idx = -1;

void MakeAnswer()
{
    // 배열을 역순으로 순회하며 queue에 있는 값들을 저장한다.
    for (int iter = N - 1; iter >= 0; --iter)
        if (!isStack[iter])
            answer[++idx] = board[iter];
    int num;
    // M번만큼 입력받은 값들을 저장한다. 이 값들이 결과적으로 출력될 값들이다.
    for (int iter = 0; iter < M; ++iter)
        cin >> answer[++idx];
    // 저장된 값들을 M개만 출력한다. 
    for (int iter = 0; iter < M; ++iter)
        cout << answer[iter] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> isStack[i];
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}