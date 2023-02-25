#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// � ���� ���� ����� ġŲ���� �Ÿ��� ġŲ�Ÿ���� �Ͽ����� ��� ���� ġŲ�Ÿ��� ���Ѱ��� ������ ġŲ�Ÿ���.
// �̶� ġŲ���� �ִ� M���� �������� �ּ����� ������ ġŲ�Ÿ��� ���ϴ� �����̴�.
// ������ �ٽ��� � ġŲ���� ��� ���� ���ΰ��ε� �׸���� Ǯ�⵵ ������ ���� ���ð� ������ ����Ž������ Ǯ����Ѵ�.

// ����ͺ��� �������� Ǯ��ڸ� ġŲ�Ÿ��� ���ϴ� ���� ������ ���õǾ� �ֵ��� ��ǥ�� y, x��� �Ҷ�
// abs(���� y - ġŲ���� y)  + abs(���� x - ġŲ���� y)�̴�. ������ ���� ���� �������� ���ؾ��ϱ⿡ 
// � ���� ġŲ�Ÿ��� ġŲ���� ������ŭ ��ȸ�ϸ� ���� ������ �Ÿ��� ���Ͽ� ���� �������� �ȴ�.

// ġŲ���� K���϶��� bool�迭�� ���� ����� ���� �����ϴ� ġŲ���� true�� �����Ͽ� �����Ͽ���
// ���� �����ϴ� ġŲ���� ������ ���ϱ� ���� for���� ��ȸ�ϸ� true�� ������ ��ȯ�ϴ� �Լ��� �����Ͽ���.

// ���� ��� ġŲ���� �����ϴ��� �������� �ʴ����� ��츦 �������ϴµ� �̴� ��Ʈ��ŷ���� �����Ͽ���.
// ���� �����ϴ� ġŲ���� ���� num�� �� ����� �Լ��� ���ϰ� num�� M���� ũ�ٸ� �����Ѵ�.
// �׷��� �ʴٸ� num���� ġŲ���� �����Ҷ��� ������ ġŲ�Ÿ��� ���ϵ� ���� �ּҰ��� �����Ѵ�.
// �� ��, ���� ġŲ�� ������ ġŲ������ �Ǵٽ� �ϳ��� true�� ��ȯ�Ͽ� �ٽ� ������ ġŲ�Ÿ��� �����Ѵ�.

vector<pair<int, int>> house, chicken; // ����, ����
vector<int> answer;
vector<bool> check;
int N, M;
const int MAX_NUM = 987654321;

// num��° ���� ġŲ�Ÿ��� ���ϴ� �Լ�. ���� �����ϴ� ġŲ������ �Ÿ����� ���Ѵ�.
int HouseLength(int num)
{
    int from_house = MAX_NUM;
    for (int i = 0; i < chicken.size(); ++i)
        if (check[i])
            from_house = min(from_house, abs(house[num].first - chicken[i].first) +
                abs(house[num].second - chicken[i].second));

    return from_house;
}


// ���� K���� ġŲ���� �����Ҷ� ������ ġŲ�Ÿ��� ���ϴ� �Լ�. vector<bool> Ÿ���� check�� �����ȴ�.
int TotalLength()
{
    int total = 0;
    for (int i = 0; i < house.size(); ++i)
        total += HouseLength(i);

    return total;
}


// ���� �����ϴ� ġŲ���� ������ ���ϴ� �Լ�. for���� ��ȸ�ϸ� true�� ����(�����ϴ� ����)�� ������ ��ȯ�Ѵ�.
int ChickenNum()
{
    int num = 0;
    for (int i = 0; i < check.size(); ++i)
        if (check[i])
            ++num;

    return num;
}


// ��� ġŲ������ true Ȥ�� false�� ��Ȳ�� �ùķ��̼� �ϴ� �Լ�.
void CalAnswer(int from)
{
    int num = ChickenNum();
    if (num > M)
        return;

    if (from != -1)
        answer[num] = min(answer[num], TotalLength()); // ���⼭ �Ÿ��� ���Ѵ�.

    for (int i = from + 1; i < chicken.size(); ++i)
    {
        check[i] = true;
        CalAnswer(i);
        check[i] = false;
    }
}


// ����������� ���ϴ� �Լ�. �������� ������ ġŲ�Ÿ��� �����Ҷ� �� �ּҰ��� ����ϰ� ��ģ��.
void MakeAnswer()
{
    CalAnswer(-1);
    int ans = MAX_NUM;
    for (int i = 1; i <= M; ++i)
        ans = min(ans, answer[i]);

    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    answer.resize(M + 1, MAX_NUM);
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            if (cur == 1)
                house.push_back(make_pair(i, j));
            else if (cur == 2)
                chicken.push_back(make_pair(i, j));
        }
    check.resize(chicken.size(), false);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}