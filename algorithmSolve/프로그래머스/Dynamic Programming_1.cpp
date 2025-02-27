#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Ǯ��.
// ���α׷��ӽ� ������ Ǯ��Ҵµ� �ϵ� �������̶� ����3�� ������� ���̵����� ������ ���� �ʾҴ�.
// �������� ���̵��� �־��µ� �ܼ� ��Ģ������ �ƴ� ���޾� N�� ���̴� ��쵵 �����ؾ��ߴ�. ���� �ߺ���
// �����ϱ� ���� set�� ����ؾ������� ���� ������ �ʿ�������Ƿ� unordered_set�� �ùٸ��� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

int solution(int N, int number) {
    if (N == number)
        return 1;

    // ����ߵ� �ߺ��� �����ϱ� ���� set. �ٸ� ������ �ʿ�����Ƿ� unordered_set�� ����Ѵ�.
    vector<unordered_set<int>> Board(9);

    for (int i = 1; i <= 8; ++i)
    {
        int num = 0;
        // ��Ģ������ �ƴ� N�� N�� ���ٿ� NN���� ����� ���.
        for (int j = 1; j <= i; ++j)
            num = num * 10 + N;
        Board[i].insert(num);

        // ���ؼ� i���� �Ǵ� ������ ��Ģ������ ���� ��� ��츦 ������.
        for (int j = 1; j < i; ++j)
        {
            for (auto& num1 : Board[j])
            {
                for (auto& num2 : Board[i - j])
                {
                    Board[i].insert(num1 + num2);
                    Board[i].insert(num1 - num2);
                    Board[i].insert(num1 * num2);
                    if (num2 != 0)
                        Board[i].insert(num1 / num2);
                }
            }
        }
        // i��°���� number�� ������°�.
        if (Board[i].count(number))
            return i;
    }
    return -1;
}