#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void printVector(const vector<int>& v, string title) {
    cout << title << " : ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> data = { 5, 2, 9, 1, 5, 6 };

    // 1? std::sort ? �⺻ ����
    vector<int> v1 = data;
    sort(v1.begin(), v1.end());
    printVector(v1, "1. sort");

    // 2? std::stable_sort ? ���� ����
    vector<pair<int, char>> v2 = { {3, 'A'}, {1, 'B'}, {3, 'C'}, {2, 'D'} };
    stable_sort(v2.begin(), v2.end(), [](auto& a, auto& b) { return a.first < b.first; });
    cout << "2. stable_sort ���\n";
    for (auto& [num, ch] : v2) cout << "(" << num << "," << ch << ") ";
    cout << "\n\n";

    // 3? std::partial_sort ? �Ϻθ� ����
    vector<int> v3 = data;
    partial_sort(v3.begin(), v3.begin() + 3, v3.end());
    printVector(v3, "3. partial_sort");

    // 4? std::nth_element ? n��° ���� ��ġ�� ��Ȯ�� ����
    vector<int> v4 = data;
    nth_element(v4.begin(), v4.begin() + 2, v4.end()); // 3��°�� ���� ���Ҹ� v4[2]�� �̵�
    printVector(v4, "4. nth_element");

    // 5? std::is_sorted ? ���� ���� Ȯ��
    cout << "5. is_sorted(v1): " << boolalpha << is_sorted(v1.begin(), v1.end()) << "\n";
    cout << "   is_sorted(data): " << boolalpha << is_sorted(data.begin(), data.end()) << "\n\n";

    // 6? �� ��� ���� make_heap / sort_heap
    vector<int> v6 = data;
    make_heap(v6.begin(), v6.end());  // �� ����
    sort_heap(v6.begin(), v6.end());  // ���� ����
    printVector(v6, "6. sort_heap");

    // 7? std::merge ? �� ���ĵ� ������ ��ġ��
    vector<int> a = { 1, 3, 5 };
    vector<int> b = { 2, 4, 6 };
    vector<int> merged(6);
    merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());
    printVector(merged, "7. merge");

    // 8? std::binary_search ? ���ĵ� �������� Ž��
    int target = 5;
    bool found = binary_search(v1.begin(), v1.end(), target);
    cout << "8. binary_search(5) ���: " << (found ? "������ o" : "���� x") << "\n";

    // 9? std::inplace_merge ? ���ڸ� ����
    vector<int> v9 = { 1, 4, 7, 2, 5, 8 }; // �� ���� {1,4,7}�� {2,5,8}�� ���� ���ĵ�
    inplace_merge(v9.begin(), v9.begin() + 3, v9.end());
    printVector(v9, "9. inplace_merge");

    return 0;
}