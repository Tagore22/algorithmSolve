#include <iostream>

using namespace std;

//단순한 브루트포스 문제인데, 높이를 몇으로 해야 최소한의 작업시간을 구할수 있는지 알수없기에 0~256을 전부 순회하며 최소값을
//구해야한다. 땅고르기 함수에서는 해당 높이가 현재 좌표의 높이보다 작다면 블록을 제거하고, 높다면 인벤토리에 있는 블록을 쌓아간다.
//한가지 실수한점이 있는데 board를 순회해가며 block이 모자랄때 이번 height로는 땅고르기를 할수 없다 판단하여 최대값을 반환한것이다.
//땅고르기는 반드시 0,0 ~ max,max의 순서로 해야하는것이라는 말이 없기에 맨 마지막에 블록이 모자란다면 그때 가서야 최대값을 반환해야
//한다. 이부분을 놓쳐서 몇번 고생했다.

const int MAX_NUM = 500;
int board[MAX_NUM][MAX_NUM];
int N, M, B;

int LandSmooth(int height)
{
    int answer = 0;
    int block = B;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] > height)
            {
                int minus = board[i][j] - height;
                answer += minus * 2;
                block += minus;
            }
            else if (board[i][j] < height)
            {
                int minus = height - board[i][j];
                //if (block < minus)     이번 좌표에 블록이 모자라도 다음번 좌표에서 끌어올수 있다면, 그래서 총 블록이 모자라지 않는다면
                //  return 987654321;    시간을 구할수 있다.
                answer += minus;
                block -= minus;
            }
        }
    return block < 0 ? 987654321 : answer; //블록의 모자람 여부는 이곳에서
}

void MakeAnswer()
{
    pair<int, int> answer = make_pair(987654321, 0);
    for (int i = 0; i <= 256; ++i)
    {
        int check = LandSmooth(i);
        answer = answer.first >= check ? make_pair(check, i) : answer;
    }
    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> B;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}