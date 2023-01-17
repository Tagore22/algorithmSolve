#include <iostream>
#include <map>

using namespace std;

//풀이
//0부터 N까지 가기에는 N이 너무 컸다. 그래서 0부터 순회하는게 아닌 N부터 거꾸로 순회하기로 하였다.
//그러나, N이 최대 1조에 달하기에 DP배열을 만드는 것도 쉽지 않았는데 생각해보면 매번 인덱스는 최소 2로 나누어지기에
//굳이 모든 배열을 다 사용할리가 없었다. 그렇기에 map으로 DP를 하면 되었다. 결과적으로 풀이는
//N에서 시작하여 각 P와 Q로 나누어지는 두가지 경우로 나누어 이진 탐색을 해나가면 된다.
//기저 사례는 현재 인덱스값이 이미 구해져 있는 경우(map에 해당 원소값이 0이 아닌 경우)에서 빠져나오면 된다.
//0번째값은 1임을 이미 알고 있기 때문이다. 마지막으로 형식에 주의해야하는데, N은 이미 int갑을 훌쩍 뛰어넘었고,
//P와 Q의 값은 최대 10억이다. 또한, long long과 int의 연산은 승격의 규칙으로 인해 long long이 되기에 N과 Q는
//int로 해도 상관은 없다. 다만, board[N]값이 int값을 벗어 나기에 map은 반드시 map<long long, long long>이 되어야한다.

map<long long, long long> board; //인덱스 뿐만 아니라 값 자체도 int값을 벗어갈수 있다. 반드시 <long long, long long>.
long long N, P, Q; 

long long CalAnswer(long long num)
{
    if (board[num] != 0) //board[num]값이 구해져 있는 경우. 최소 board[0]은 구해져 있기에 기저사례로 적합하다.
        return board[num];

    long long first = num / P;
    long long second = num / Q;

    return board[num] = CalAnswer(first) + CalAnswer(second); //board[num] = board[num / P] + board[num / Q].
}

void MakeAnswer()
{
    board.insert(make_pair(0, 1));
    cout << CalAnswer(N) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}