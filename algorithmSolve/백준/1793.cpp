#include <iostream>
#include <string>

using namespace std;

//풀이
//우선 타일을 놓는 수를 얻는 방법부터 구해야 한다. 타일은 2*1, 2*2 2가지 방법으로 놓을수 있고 그 중 2*1은 세로로 긴 방법 하나밖에 없다.
//2*2는 2*1을 가로로 2개 놓거나, 1*2를 세로로 2개 놓거나, 아예 2*2짜리를 쓰는 총 3개의 방법이 있다. 이 방법으로 하나씩 늘려가며 답을 구할건데
//주의할점은 2*1짜리 타일로 1칸씩 늘려가는것과 2*1을 가로로 2개 놓아서 2칸씩 늘려가는 것이 겹친다는 점이다. 따라서, 2*1로 2칸을 늘리는 방법은
//무시하여 2칸을 채우는 방법은 총 2개가 있다. 결국 점화식은 아래와 같이 나온다.

//n칸의 방법 = (n-1칸의 방법 * 1(뒤에 2*1 타일을 놓는 방법 1가지 밖에 없음)) + (n-2칸의 방법 * 2(1*2를 세로로 2개 놓거나, 2*2타일을 사용하는 방법))

//그러나, 예시에서도 볼수 있듯이, 최대 250칸의 수는 long long을 훌쩍 초월하는 몇자리인지 세기도 싫을 정도의 긴 수이므로 문자열로 구현해야한다.
//따라서 수를 문자열로 변환했을때, 그 문자열들의 덧셈(수의 덧셈)을 함수로 구현해야했다. 

//처음엔 자리수를 맞춰주기 위해 두 문자열의 size함수로 자리수를 비교해가며 짧은 문자열앞에 "0"을 추가해주었다.
//그 이후 int로 변환하여 수를 더했을때 10보다 크다면 다음자리수에 영향을 끼치기에 plus변수에 기록해두어 다음 자리수의 덧셈때 관여한다.
//주의할점은 문자열의 순회 끝에 마지막 plus가 1이라면 추가로 "1"을 맨 앞에 붙여야한다는 점이다. (50 + 50 = 100)
//전처리로 미리 답들을 구현해놓고, 입력받은 수에 해당하는 답을 출력하되 테스트 케이스가 주어지지 않음에 주의한다.

string board[251];

string Func_Plus(string a, string b)
{
    while (a.size() != b.size()) //자리수를 맞춰야 후에 구현이 편하다.
    {
        if (a.size() > b.size())
            b = "0" + b;
        else
            a = "0" + a;
    }

    string mul = "";
    int first, second, plus = 0;

    for (int i = a.size() - 1; i >= 0; --i)
    {
        first = (a[i] - '0') + plus;
        second = b[i] - '0';
        plus = first + second >= 10 ? 1 : 0; //first와 second의 값이 10이상이라면 다음 자리수에 영향을 끼치기에 기록해놓는다.
        mul = to_string((first + second) % 10) + mul; //현재 자리수를 다시 문자열로 변환한다.
    }

    if (plus == 1)
        mul = "1" + mul;

    return mul;
}

void CalBoard()
{
    board[0] = "1";
    board[1] = "1";

    for (int i = 2; i < 251; ++i)
        board[i] = Func_Plus(Func_Plus(board[i - 2], board[i - 2]), board[i - 1]); //점화식은 n = (n-1 * 1) + (n-2 * 2);
}

void MakeAnswer()
{
    CalBoard();
    int num;

    while (cin >> num)
        cout << board[num] << '\n';
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