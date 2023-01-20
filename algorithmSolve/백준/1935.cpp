#include <iostream>
#include <stack>

using namespace std;

//풀이
//후위표기식은 A + B의 식을 AB+로 변경하는걸 뜻한다. 즉, 연산자가 등장했을 경우 그보다 앞 2개의 수를 해당 연산자로 계산하면 되는데
//이는 stack을 사용하면 어렵지 않게 풀수있다. 입력된 후위 표기식을 string에 담아둔후 순회하되, 알파벳이 나오면 해당 알파벳에 대응되는
//수를 stack에 저장하고, 알파벳이 아니라면 stack에서 2개의 수를 빼내서 해당 연산자로 계산후 다시 stack에 넣기를 반복하면 된다.
//다만, 소수점 2자리까지 출력해야하므로 int가 아닌 double을 사용해야하며, precision 처리 역시 빠져서는 안된다.

string str;
int board[26];
int N;

void MakeAnswer()
{
    stack<double> sta;
    for (int i = 0; i < str.size(); ++i)     //주어진 후위 표기식을 순회한다.
    {
        if ('A' <= str[i] && str[i] <= 'Z')  //알파벳일 경우 해당 알파벳에 대응되는 수를 스택에 넣는다.  
        {
            sta.push(board[str[i] - 'A']);
        }
        else                                 //연산자일 경우 stack에서 2개의 수를 꺼내 계산후 stack에 넣는다.
        {
            double second = sta.top();
            sta.pop();
            double first = sta.top();
            sta.pop();

            if (str[i] == '+')              //연산자에 종류에 따라 다른 연산을 행함.
                sta.push(first + second);
            else if (str[i] == '-')
                sta.push(first - second);
            else if (str[i] == '*')
                sta.push(first * second);
            else
                sta.push(first / second);
        }
    }

    cout.precision(2);         //소수점 이전과 이후 총 2자리까지 출력됨.
    cout << fixed;             //소수점 이후 2자리로 변경.
    //cout.unsetf(ios::fixed); //소수점 이후로의 변경을 없앨 경우.
    cout << sta.top() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}