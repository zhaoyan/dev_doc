#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <map>
#include <numeric>
#include <random>
using namespace std;

vector<pair<int, int> > vi = { {0, 2}, {3, 7}, {4, 7}, {9, 11}, {7, 10}, {1, 5}, {6, 8} };

void machine() {
	sort(begin(vi), end(vi), [](auto& e1, auto& e2) {
		if (e1.first < e2.first) {
			return true;
		}
		else if (e1.first == e2.first) {
			return e1.second > e2.second;
		}
		return false;
		}
	);

	priority_queue<int, vector<int>, greater<int> > pq;  //#small priority queue.
	pq.push(vi[0].second);
	int sum = 1;
	for (int i = 1; i < vi.size(); ++i) {
		int end = pq.top();
		if (vi[i].first < end) {
			++sum;
			pq.push(vi[i].second);
		}
		else {
			pq.pop();
			pq.push(vi[i].second);
		}
	}
	cout << "sum=" << sum << endl;
}

struct com {
	bool operator ()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second > p2.second;  //greater is mininal heap. 
	}
};

void test_map() {
	vector< pair<string, int> > vi = { {"book1", 100}, {"book1", 100}, {"book2", 300},  {"book3", 100}, {"book4", 50} };
	map<string, int> m;
	for (auto e : vi) { //#use auto here. 
						//# use 
		if (m.find(e.first) != m.end()) { //# end add ()
			m[e.first] += e.second;
		}
		else {
			m[e.first] = e.second;
		}
	}
	//for (auto [k, v] : m) {
	//	cout << k << " " << v << endl;
	//}

	priority_queue<pair<string, int>, vector< pair<string, int>>, com> pq;
	for (auto e : m) {
		if (pq.size() == 2) {
			pq.push(e);
			pq.pop();
		}
		else {
			pq.push(e);
		}
	}


	while(pq.size())
	{
		auto [k, v] = pq.top(); //# structual binding.
		pq.pop();
		cout << k << " " << v << endl;
	}

}

void basic_stl()
{
	vector vi{ 1 };
	vi.resize(10);
	fill_n(vi.begin(), 3, 2);
	fill(vi.begin(), vi.end(), 1);
	cout << "sum" << accumulate(vi.begin(), vi.end(), 0) << endl;
	vector<int> re;
	partial_sum(vi.begin(), vi.end(), inserter(re, re.begin()));

	std::random_device rd;
	std::mt19937 g(rd());
	shuffle(re.begin(), re.end(), g);
	auto p = find(re.begin(), re.end(), 4);
	re.erase(p);

	sort(re.begin(), re.end());

	auto p1 = lower_bound(re.begin(), re.end(), 4);
	cout << *p1 << endl;
	re.insert(p1, 4);

	

	for (auto e : re) {
		cout << " " << e;
	}
}


	int splitArray(vector<int>&nums, int m) {
		// 重叠子问题 最优子结构
		// dp[i][j] 将其前 i 个元素分成 j 组，全局最小值
		// 7 2 5 10 8
		//          i dp[i][1] = sum[i]
		//   k      i 从 1 到 k 分成 j - 1，从 k + 1到 i 分成一组
		// dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
		int n = nums.size();
		long long dp[15][55], sum[15];
		memset(dp, 0x3f, sizeof dp);
		memset(sum, 0, sizeof sum);
		for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + nums[i - 1];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= min(i, m); ++j) {
				if (j == 1) {
					dp[i][j] = sum[i];
				}
				else {
					for (int k = 1; k <= i - 1; ++k) {
						if (i == 4 && j == 1)
						{
							cout << k << j - 1 << endl;
						}
						dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
					}
				}
			}
		}
		return dp[n][m];
	}

	int minj(int arr[], int last) {

		if (last == 1 && arr[last] >= 1) {
			return 1;
		}

		int min = last;
		for (int i = last - 1; i >= 0; i--) {
			if (i + arr[i] >= last) {
				int step = 1 + minj(arr, i);
				if (step < min) {
					min = step;
				}
			}
		}
		return min;
	}

int main() {

	int arr11[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };

	minj(arr11, 3);
	return 0;

	vector vi = { 7, 2, 5, 10, 8 };
	cout <<  splitArray(vi, 2) << endl;

	//basic_stl();
	return 0;
	//test_map();
	//return 0;
	

	//# different alorithms.
	//# search, find_end, find_first_of, search_n, find: Five confused functions.
	//#
	array<int, 10> arr = { 1, 2, 3, 6, 19, 18, 2, 3, 6, 19 };
	array<int, 3> arr1 = { 2,3, 6 };
	auto p1 = search(begin(arr), end(arr), begin(arr1), end(arr1));
	auto p2 = find_end(begin(arr), end(arr), begin(arr1), end(arr1));
	cout << "found " << distance(begin(arr), p2) << endl;

	sort(begin(arr), end(arr));
	for (auto e : arr) {
		cout << e << " ";
	}
	auto p = search_n(begin(arr), end(arr), 3, 6);
	if (p != end(arr)) {
		cout << "found" << endl;
	}
	else {
		cout << "not" << endl;
	}



	//char** ca = { "abc", "de" };
	//char* ca[] = { {'a','b', 'c'} , {'d', 'e'} };
	//char* ca[] = { "abc" , "de" };
	//int** da = { {1,2,3}, {4,5} };
	//int* da[] = { {1,2,3}, {4,5} };
	int* da[] = { new int[] {1,2,3}, new int[] {4,5} }; //an array of pointer, ragged
	int** pda = da;  // da is adress of pointer
	cout << *(*(pda + 1) + 1) << endl;// output 5

	int da1[2][3] = { {1,2,3}, {4,5,6} }; //an array of array, square
	int(*pda1)[3] = da1;  //da1 is address of array [3]
	cout << *(*(pda1 + 1) + 1) << endl;// output 5

	char* ca[] = { new char[] {'a', 'b', 'c', '\0'}, new char[] {'d', '\0'} };
	const char* cca[] = { "abc", "de" };
}