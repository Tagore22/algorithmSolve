#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Ǯ��.
// �������� ���� �������� ������ ������. ��������.
// ���߿� �˰��� �Ｚ ��������. ��������.
// �������� �̰� ��ü ���� �ϰ� �Ѿ�� �����ε� �ð��� �����ɷȾ �ᱹ�� ������ Ǯ���⿡ ���� ���������� �����Ѵ�.
// ���Ǻ��� �����ؾ������� �����ó�� �׿��ִ�. �������� ����� ������ Ǭ�� ����.

// ������ü�� ũ�� ����� �ʴ�. ��ȣ�� ������ �ִ� ��� ��츦 ����ؼ� ���� ū ������� ����ϴ� ���ε� ������ ��� �پ��ִ�.

// 1. �ϳ��� ��ȣ�ȿ��� �ϳ��� �����ڸ��� �����Ҽ� �ִ�. �� (1*2*3) �������� �Ұ����ϴ�.
// 2. ������ ���õǾ��� ��ȣ�� �ߺ��� �Ұ����ϴ�. ex((1*2)-3)

// �� ������ ���ؼ� ��ȸ�Ҽ� �ִ� ��� ��츦 �ؾ��Ѵ�. ���� �����ؾ������� �ſ� ������
// �ּ��� ���ؼ� ���ܾ��������� ����.

// ���� ó���� Ǯ������ �̻��ϰ� �ȵǴ� �ݷʵ��� ��� �־��µ� ������ ��ȣ�� ������� ���� ��츦 ó������ �ʾұ� �����̴�.
// ������ Ʋ�� Ǯ�̵��� ���� ���� ��ȣ�� ��� ����ϴ� ��츸 ��ȸ�Ǿ� �ִ�. �̰��� ���ƾ���.

// �ڼ��� ������ �ּ����� �����.

string str;
int N, answer;

// �����ڰ� ��ġ�� ���(1 * -1���� ���)�� ������ ���ÿ� ����ִ� ���� ���������� �������� Ȯ���ϴ� �Լ�.
bool CheckPunct(const string& str)
{
    if ('0' <= str[str.size() - 1] && str[str.size() - 1] <= '9')
        return false;
    return true;
}

// ���� ������ ������� �����ϴ� �Լ�.
int CalSum(const string& str)
{
    stack<string> sta;
    int oper = 0;
    bool isminus;
    // ūƲ�� ������ ����.
    // 1. ���ڿ��� ��ȸ�Ѵ�.
    // 2. ���簪�� �����ϰ��
    // 2-1. ������ ����ְų�(ù��° ���� ����) ������ ����ִ� ���� �����̰ų�(���� ���� 1�ڸ��� �ƴѰ��)
    // Ȥ�� ������� ������ �������� ������(-)�� ��쿡�� �������� �ҷ��� �ϳ��� ���ļ� ���� ����ִ´�.
    // 2-2. �׷��� ���� ��� ���簪�� ������ �ƴ� ��Ȳ���� �������� �������̰ų�, ������ �����̱⿡ �׳� ����ִ´�.
    // 2-3. ���� ������ ���� ������ ���� ������ ���� �������̹Ƿ� isminus�� false�� �������־� ���� �����ڸ� üũ�Ѵ�.
    // 3. ���簪�� �������� ���
    // 3-1. ������ ����ְų�, �������� �̹� ������(-)�� ��� ���簪�� ������ ������ �ǹǷ� isminus�� true�� �������ְ� ���� �Է¹���
    // �������� ���� �����ϴ� oper�� 1 �������־� ���� ������ �����ڴ� �����ڰ� �ƴ� ������ ���� ���������� üũ�Ѵ�.
    // 3-2. ���� oper�� 1 �����Ͽ� �����ڸ� �������� üũ�Ѵ�.
    // 3-3. ���� oper�� 2��� �ǿ����� 2���� ������ 1���� ��� ������ �����̹Ƿ� ������ �����ϴ�.
    // ���� ������ �� 3���� ������ ������� ���ÿ� ����ְ� ���簪�� �����Ѵ�.
    // 4. ��ȸ�� ������ ������ ���ÿ� ���������� ������� ��ȯ�Ѵ�.

    // ��� ������ ��ȸ�Ѵ�.
    for (int i = 0; i < str.size(); ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if (!sta.empty() && (!CheckPunct(sta.top()) || isminus))
            {
                string pre = sta.top();
                sta.pop();
                sta.push(pre + str[i]);
            }
            else
            {
                sta.push(to_string(str[i] - '0'));
            }
            isminus = false;
        }
        else
        {
            if (sta.empty() || !sta.empty() && CheckPunct(sta.top()))
            {
                isminus = true;
                --oper;
            }
            ++oper;
            if (oper == 2)
            {
                string second = sta.top();
                sta.pop();
                string ope = sta.top();
                sta.pop();
                string first = sta.top();
                sta.pop();

                int f = stoi(first);
                int s = stoi(second);

                if (ope == "+")
                    sta.push(to_string(f + s));
                else if (ope == "-")
                    sta.push(to_string(f - s));
                else
                    sta.push(to_string(f * s));
                oper = 1;
            }
            sta.push(str.substr(i, 1));
        }
    }
    string second = sta.top();
    sta.pop();
    string ope = sta.top();
    sta.pop();
    string first = sta.top();
    sta.pop();

    int f = stoi(first);
    int s = stoi(second);

    if (ope == "+")
        sta.push(to_string(f + s));
    else if (ope == "-")
        sta.push(to_string(f - s));
    else
        sta.push(to_string(f * s));
    return stoi(sta.top());
}

// ��� ����� ���� ��ȸ�ϴ� �Լ�.
void BackTrack(int idx, const string str)
{
    for (int i = idx; i < str.size() - 2; i += 2)
    {
        // i�� i + 2������ �����Ͽ� ����Լ��� �Ѱ� �װ��� �޴´�.
        // �� ���� i + 3���� ������ �����Ѱ��� ���ļ� 
        // BackTrack�� �ι�° �Ű������� �ѱ��.
        // idx�� 2�� �����Ǿ� �Ѿ��.
        int cur = CalSum(str.substr(i, 3));
        string next = to_string(cur);
        BackTrack(i + 2 + next.size() - 1, str.substr(0, i) + next + str.substr(i + 3));
    }

    // ���� ��ȣ�� ������� ���� ��츦 Ȯ���Ѵ�.
    answer = max(answer, CalSum(str));
}

void MakeAnswer()
{
    // N�� 1�� ���� 3�� ��츦 ���� ó�����־���Ѵ�.
    if (N == 1)
    {
        cout << str[0] << '\n';
        return;
    }
    else if (N == 3)
    {
        cout << CalSum(str) << '\n';
        return;
    }
    answer = CalSum(str);
    BackTrack(0, str);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}