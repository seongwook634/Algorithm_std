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

    // 1 std::sort - 기본 정렬
    vector<int> v1 = data;
    sort(v1.begin(), v1.end());
    printVector(v1, "1. sort");

    // 2 std::stable_sort - 안정 정렬
    vector<pair<int, char>> v2 = { {3, 'A'}, {1, 'B'}, {3, 'C'}, {2, 'D'} };
    stable_sort(v2.begin(), v2.end(), [](auto& a, auto& b) { return a.first < b.first; });
    cout << "2. stable_sort 결과\n";
    for (auto& [num, ch] : v2) cout << "(" << num << "," << ch << ") ";
    cout << "\n\n";

    // 3 std::partial_sort - 일부만 정렬
    vector<int> v3 = data;
    partial_sort(v3.begin(), v3.begin() + 3, v3.end());
    printVector(v3, "3. partial_sort");

    // 4 std::nth_element - n번째 원소 위치만 정확히 정렬
    vector<int> v4 = data;
    nth_element(v4.begin(), v4.begin() + 2, v4.end()); // 3번째로 작은 원소를 v4[2]로 이동
    printVector(v4, "4. nth_element");

    // 5 std::is_sorted - 정렬 여부 확인
    cout << "5. is_sorted(v1): " << boolalpha << is_sorted(v1.begin(), v1.end()) << "\n";
    cout << "   is_sorted(data): " << boolalpha << is_sorted(data.begin(), data.end()) << "\n\n";

    // 6 힙 기반 정렬 make_heap / sort_heap
    vector<int> v6 = data;
    make_heap(v6.begin(), v6.end());  // 힙 구성
    sort_heap(v6.begin(), v6.end());  // 힙을 정렬
    printVector(v6, "6. sort_heap");

    // 7 std::merge - 두 정렬된 범위를 합치기
    vector<int> a = { 1, 3, 5 };
    vector<int> b = { 2, 4, 6 };
    vector<int> merged(6);
    merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());
    printVector(merged, "7. merge");

    // 8 std::binary_search - 정렬된 범위에서 탐색
    int target = 5;
    bool found = binary_search(v1.begin(), v1.end(), target);
    cout << "8. binary_search(5) 결과: " << (found ? "존재함 o" : "없음 x") << "\n";

    // 9 std::inplace_merge - 제자리 병합
    vector<int> v9 = { 1, 4, 7, 2, 5, 8 }; // 두 구간 {1,4,7}과 {2,5,8}은 각각 정렬됨
    inplace_merge(v9.begin(), v9.begin() + 3, v9.end());
    printVector(v9, "9. inplace_merge");

    return 0;

}

