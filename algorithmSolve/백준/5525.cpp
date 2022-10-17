#include <iostream>
#include <vector>

using namespace std;

//ū ���ڿ� A���� ���� ���ڿ� B�� �����ϴ� ��ġ�� ã�� �������� KMP�����̴�. ������ �����صξ��� �Լ��� �־��⿡ �׸� ����� �ʾҴ�.

vector<int> proto, answer;
string S, str = "I";
int N, M;

void KMPProto()
{
    proto.resize(str.size(), 0);
    int begin = 1;
    int matched = 0;
    while (begin + matched < str.size())
    {
        if (str[begin + matched] == str[matched])
        {
            ++matched;
            proto[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
            {
                ++begin;
            }
            else
            {
                begin += matched - proto[matched - 1];
                matched = proto[matched - 1];
            }
        }
    }
}

void KMP()
{
    int begin = 0;
    int matched = 0;
    while (begin + matched < S.size())
    {
        if (matched < str.size() && S[begin + matched] == str[matched])
        {
            ++matched;
            if (matched == str.size())
                answer.push_back(begin + 1);
        }
        else
        {
            if (matched == 0)
            {
                ++begin;
            }
            else
            {
                begin += matched - proto[matched - 1];
                matched = proto[matched - 1];
            }
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        str += "OI";
    KMPProto();
    KMP();
    cout << answer.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> S;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}