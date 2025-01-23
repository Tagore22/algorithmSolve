#include <iostream>

using namespace std;

// 풀이.
// 낮은 정답율답게 어려운 문제였다. 분할 정복 문제였는데 기존에 일관적으로 나누어지던 것과는 다르게
// 전부 다르게 나뉠수도 있기에 생각해내기 어려웠다. 결과적으로 하나의 큐브를 박스에 넣을때
// 나머지 빈 부분을 3군데로 나누어 다시 재귀를 반복하는 형식이다. 이것까지만 떠올린다면 나머지 구현은
// 어렵지 않다. 다만, 큐브값을 최소화해야하기 때문에 가장 큰 큐브부터 대입해야하는 것을 잊으면 안된다.

// 자세한 설명은 주석으로 남긴다.

int L, W, H, N, answer = 0;
pair<int, int> board[20];
bool isFail = false;

// L * W * H의 박스가 존재할때 큐브를 넣어보는 함수.
void DivFunc(int L, int W, int H)
{
    // 현재 박스의 부피가 0이라면 박스를 넣을수 없고, 한번이라도 실패했다면
    // 아예 실패이기 때문에 그냥 탈출한다.
    if (L == 0 || W == 0 || H == 0 || isFail)
        return;

    // 상술한대로 큐브값을 최소화해야하기에 가장 큰 큐브부터 역순으로 순회한다.
    for (int i = N - 1; i >= 0; --i)
    {
        // i번째 큐브의 남은 개수가 0이거나 큐브의 변의 길이가 현재 박스의 변보다 더 큰 경우는 무시한다.
        if (board[i].second == 0 || board[i].first > L || board[i].first > W || board[i].first > H)
            continue;

        // i번재 큐브값을 하나 줄이고 사용한 큐브의 값을 하나 늘린다.
        --board[i].second;
        ++answer;

        // 채워진 부분을 제외한 나머지 3부분을 분할하여 재귀호출한다.
        DivFunc(board[i].first, board[i].first, H - board[i].first);
        DivFunc(L - board[i].first, board[i].first, H);
        DivFunc(L, W - board[i].first, H);

        // 이 부분에 return이 없다면 현재 박스를 더 작은 큐브들로도 채워보는 의미없는 행동을 하게 된다.
        // 따라서 return으로 무시한다.
        return;
    }
    // 이번 재귀에서 맞는 큐브를 단 하나도 찾지 못했을때. 
    // 이런 경우는 애시당초 큐브의 개수가 모자랄때밖에 존재할수 없다. 
    // 주어지는 큐브의 길이는 무조건 1부터 2, 4, 8등 2의 제곱순으로 등장하기 때문에
    // 큐브를 고르는 순서에 의해 틀리는 경우는 존재하지 않는다. 예를 들어
    // 큐브가 3과 2만 존재한다면 길이가 7일때 3, 2, 2가 아닌 
    // 3, 3을 골랐을때에는 isFail이 되어 답을 고를수 없으나, 상술한대로 무조건 1부터
    // 등장하기에 이런 경우는 존재할수 없다. 따라서 큐브의 개수가 모자라서
    // 아예 박스를 채울수 없는 경우만이 isFail이 true가 되는 경우이다.
    isFail = true;
}

void MakeAnswer()
{
    DivFunc(L, W, H);
    cout << (isFail ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> W >> H >> N;
    int mul;
    for (int i = 0; i < N; ++i)
    {
        cin >> mul >> board[i].second;
        board[i].first = (1 << mul);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}