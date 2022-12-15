#include <iostream>

using namespace std;

//코 쓰윽.
//푼사람이 50명도 안되서 많이 쫄았던 문제다. 풀이도 찾을수 없을테니 아예 맘편히 고민하면서 풀었다.

//풀이
//처음에는 배낭문제 풀이 비슷하게 완전탐색을 생각했으나 2의 50제곱에 가까운 연산량이 필요로 하기에 시간초과가 났다.
//꽤나 오래 고민했는데 결국 풀이는 맨 처음 원소부터 순회하며 최초로 최대값 - 최소값이 V이상이 되는 원소 from에서 to까지의 최소 문제수를
//구하는 것이었다. 다만, 1번 문제는 무조건 풀어야했으므로 1번 문제부터 from까지의 거리수를 추가로 더해줘야 한다.


int board[50];
int N, V;

void MakeAnswer()
{
    int answer = N;
    for (int i = 0; i < N; ++i) //i가 from이 되어 차이가 V이상이 되는 원소값의 존재 유무를 탐색한다.
    {
        int plus = i == 0 ? 1 : (i - 0 - 1) / 2 + 2; //1번 문제부터 from까지의 최소 문제수
        for (int j = i; j < N; ++j) //to를 찾는다.
            if (abs(board[i] - board[j]) >= V)
            {
                plus += (j - i - 1) / 2 + 1;
                answer = min(answer, plus);
                break; //현재 from과 to를 찾았다면 종료한다. 더 순회해도 plus보다 적을수 없기 때문.
            }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> V;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}