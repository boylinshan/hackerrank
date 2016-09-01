#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;

void split(const string &s, char delim, vector<int> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(stoi(item));
	}
}

vector<int> split(const string &s, char delim) {
	vector<int> elems;
	split(s, delim, elems);
	return elems;
}

void heapify(vector<int> &vec, int pos, int n) {
	int largest = pos;
	int right = 2 * largest + 1;
	int left = 2 * largest+ 2;

	if (right<n && vec[right] > vec[largest])
		largest = right;
	if (left<n && vec[left] > vec[largest])
		largest = left;
	if (largest != pos) {
		swap(vec[largest], vec[pos]);
		heapify(vec, largest, n);
	}

}
vector<int> Solution(vector<vector<int>> &matrix, int K) {
	vector<vector<vector<int>>> sum;
	sum.resize(matrix.size());
	for (int i = 0; i < matrix.size(); ++i) {
		sum[i].resize(matrix[i].size());
		for (int j = 0; j <= i; ++j) {
			sum[i][j].resize(matrix.size() - i);
			sum[i][j][0] = matrix[i][j];
		}
	}
	
	for (int i = sum.size() - 2; i >= 0; --i) {
		for (int j = 0; j < sum[i].size(); ++j) {
			for (int k = 1; k < sum[i][j].size(); ++k) {
				sum[i][j][k] = sum[i][j][0] + sum[i + 1][j][k - 1] + sum[i + 1][j + 1][k - 1];
				if (i+2<sum.size() && k-2>=0) {
					sum[i][j][k] -= sum[i + 2][j + 1][k-2];
				}	
				
			}
		}
	}

	vector<int> result(K, INT_MAX);
	for (int i = 0; i < sum.size(); ++i) {
		for (int j = 0; j < sum[i].size(); ++j) {
			for (int k = 0; k < sum[i][j].size(); ++k) {
				int elem = sum[i][j][k];
				result[0] = elem < result[0] ? elem : result[0];
				heapify(result,0, result.size());
			}
		}
	}

	sort(result.begin(), result.end());

	return result;
}


int main() {
	unsigned int N;
	unsigned long long K;
	vector<int> sum;
	cin >> N >> K;
	cin.ignore(256, '\n');
	vector<vector<int>> matrix;
	while (N--) {
		string nums;
		getline(cin, nums);
		matrix.push_back(split(nums, ' '));
	}
	sum = Solution(matrix, K);
	for (int i = 0; i < sum.size(); ++i) {
		cout << sum[i] << endl;
	}

	return 0;
}