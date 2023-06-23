#include <iostream>
#include <cstring>

using namespace std;

// 풀이. 
// 백트래킹 문제이다. 어제 풀었던 문제와 비슷하게
// 사전순으로 정렬되어 출력해야하기 때문에 1 ~ K까지 작은 수부터 하나씩 대입해 나가면서
// 그 수가 6개가 되었을때 현재 선택한 수들을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[13];
bool check[13];
int K;
const int LAST_NUM = 6;

// 현재 선택된 수들을 출력하는 함수. 벡터를 사용해도 되지만 bool 배열은 무조건 사용해야 하기에
// 이렇게 bool 배열만을 이용하여 구현해도 될듯하다.
void ShowAnswer()
{
    for (int i = 0; i < K; ++i)
        if (check[i])
            cout << board[i] << ' ';
    cout << '\n';
}

// 백트래킹 함수. 상술하였듯 사전순으로 정렬되어야 하기에 작은수부터 하나씩 선택해 나가며,
// 총 6개를 선택했을시 현재 고른수들을 출력한다.
void BackTrack(int idx, int num)
{
    if (idx == LAST_NUM)
    {
        ShowAnswer();
        return;
    }

    for (int i = num + 1; i < K; ++i)
        if (!check[i])
        {
            check[i] = true;
            BackTrack(idx + 1, i);
            check[i] = false;
        }
}

void MakeAnswer()
{
    while (true)
    {
        cin >> K;
        if (K == 0)
            break;
        memset(check, false, sizeof(check));
        for (int i = 0; i < K; ++i)
            cin >> board[i];
        BackTrack(0, -1);
        cout << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}