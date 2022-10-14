#include <iostream>
#include <cstring>

//브루트포스는 늘 그렇듯이 한참 고민했던 문제이다. 분명 채널을 주어진 N에 가장 가깝게 만든 후 모자란 부분을 더해줘야 하는 문제인데,
//그리디로 풀려고 하니 좀처럼 패턴이 생각나질 않았다. 이럴땐 역시 주먹구구식으로 0부터 대입하는것이 최고였으나 최대값을 어떻게 잡아야
//할지가 또 떠오르지 않았다. 그러다가 문뜩 떠올랐는데 최대값은 100만으로 잡으면 된다. 왜냐하면 가장 작은 채널값은 0이고 주어지는 값 N의
//최대값은 50만이기에 결과적으로 숫자가 아닌 + - 버튼으로 변하는 수는 최대 50만이며, 최대값을 100만으로 잡으면 N이 어떤 값으로 주어지든
//100만보다 큰 수가 답이 될순 없기 때문이다.(100만보다 증가하면 abs(N-내가 만든수)가 최소 50만을 돌파하여 최소값을 구해야 하는 채널에서
//배제된다.) 결과적으로 0부터 100만까지 수를 1씩 증가하며 그 수가 현재 버튼으로 만들 수 있는 채널인지 확인해가며, 최소값 answer를 수정
//하여 출력하면 된다.

using namespace std;

bool check[10];
const int MAX_NUM = 1000000;
int N, M, answer;

//현재 채널을 만들기 위해 눌러야하는 버튼의 수를 구하는 함수.
//매번 10으로 나누어가며 현재 자리수를 구하고 혹여나 그 자리수를 만들수 없다면(check[현재 자리수]가 false라면) 무시하며 return한다.
//그렇지 않다면 마지막 자리를 구한 순간(num이 0일때) 빠져나오며, abs(N-com) (만들어야 하는 채널과 현재 만든 채널의 차이값을 + 혹은 - 버튼
//으로 채워가야하는 수) + idx(현재 채널을 만들때 누른 버튼의 수)를 구해 기존값과 비교한다.

void Cal(int num)
{
    int com = num;
    int idx = 0;
    int now = 0;
    while (true)
    {
        now = num % 10;
        num /= 10;
        ++idx;
        if (!check[now])
            return;
        if (num == 0)
            break;
    }
    answer = min(answer, abs(N - com) + idx);
}

//answer의 최소값은 abs(N-100)으로 숫자버튼을 누르지 않고, + 혹은 - 버튼만으로 N번채널을 만들었을때의 값이다.

void MakeAnswer()
{
    answer = abs(N - 100);
    for (int i = 0; i <= MAX_NUM; ++i)
        Cal(i);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, true, sizeof(check));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        check[a] = false;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}