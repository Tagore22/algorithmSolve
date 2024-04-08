#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 문제를 풀때 2가지 경우를 생각하지 못했다. 첫번째로는 불필요한 0이 존재할때이다.
// 문제에 나왔는데 대충 흘려넘겼다. 이것은 맨 마지막 덧셈이 1이 아닐때에 발생한다. 
// 따라서 if ~ else문으로 구현이 가능한데 최종적으로 만들어진 answer를 순회하며
// 첫번째로 0이 아닐때부터 끝까지 복사한것을 answer에 덧씌우면 된다.
// 복사의 시작은 from이라는 int 변수로 저장해놨는데 초기값은 그냥 생각없이 0이었다.
// 두번째 실수가 여기서 발생하는데 주어진 두 문자열이 0000, 000일 경우 1이 아예 나타나지 않기에
// 그냥 0번째부터 쭉 복사되어 답이 0000이 출력된다. 불필요한 0이 달려있다. 따라서 시작점의 초기화를
// answer.size() - 1로 해야했다. 순회 끝에 1이 존재하지 않을 경우 결과적으로는 0이 나와야 하기 때문에
// 맨 마지막 1자리를 시작점으로 해놓으면 상술한 예시의 경우마저 답파할수 있기 때문이다.

// 자세한 설명은 주석으로 남긴다.

int T;
string str1, str2;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str1 >> str2;

        // 두 문자열의 길이가 같아질때 까지 적은 앞에 "0"을 추가한다.
        while (str1.size() != str2.size())
        {
            if (str1.size() > str2.size())
                str2 = "0" + str2;
            else
                str1 = "0" + str1;
        }
        string answer = "";
        int plus = 0;
        // 문자열들을 순회하며 각 자리수를 더하며 연산을 한다.
        for (int i = str1.size() - 1; i >= 0; --i)
        {
            int first = stoi(str1.substr(i, 1));
            int second = stoi(str2.substr(i, 1));
            int cur = first + second + plus;
            // 만약 이번 덧셈의 값이 2 이상이었다면 다음 덧셈에 1을 더해줘야한다.
            plus = cur / 2;
            // 현재 자리값은 덧셈 % 2가 되어야 한다.
            answer = to_string(cur % 2) + answer;
        }
        // 마지막 덧셈의 결과값이 1이라면 맨앞에 1을 추가적으로 붙여준다.
        if (plus == 1)
        {
            answer = "1" + answer;
        }
        // 1이 아닐 경우 불필요한 0들을 지워야한다.
        else
        {
            // 상술한 복사의 시작값. 0이 아닌 맨 마지막 자리수로 초기화해야 000, 0000 경우 같은 것을 답파가능하다.
            int from = answer.size() - 1;
            // 문자열을 순회하며 첫번째로 1이 등장하는 위치를 찾는다.
            for (int i = 0; i < answer.size(); ++i)
                if (answer[i] != '0')
                {
                    from = i;
                    break;
                }
            // 첫번째로 등장한 이후로 answer를 수정한다.
            answer = answer.substr(from);
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}