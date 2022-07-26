// https://leetcode.cn/problems/k-closest-points-to-origin/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class MaxHeap {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        // <dist, idx>
        std::priority_queue<std::pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            const auto &p = points[i];
            q.push({p[0] * p[0] + p[1] * p[1], i});
        }

        int n = points.size();
        for (int i = k; i < n; ++i) {
            const auto &p = points[i];
            int dist = p[0] * p[0] + p[1] * p[1];
            if (q.top().first > dist) {
                q.pop();
                q.push({dist, i});
            }
        }

        vector<vector<int>> ret;
        while (!q.empty()) {
            ret.push_back(points[q.top().second]);
            q.pop();
        }
        return ret;
    }
};

// FIXME: slow when points contains a large number of the same point, and k is 1
class QuickSort {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        partial_sort(points, 0, points.size() - 1, k);

        points.resize(k);
        return points;
    }

    void partial_sort(vector<vector<int>> &arr, int low, int high, int k) {
        if (low < high) {
            int pivot_idx = partition(arr, low, high);
            if (pivot_idx < k)
                partial_sort(arr, pivot_idx + 1, high, k);
            else
                partial_sort(arr, low, pivot_idx - 1, k);
        }
    }

    int partition(vector<vector<int>> &arr, int low, int high) {
        std::swap(arr[high], arr[(low + high) / 2]);
        int pivot = dist(arr[high]);
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            int dist = arr[j][0] * arr[j][0] + arr[j][1] * arr[j][1];
            if (dist <= pivot)
                swap(arr[++i], arr[j]);
        }
        swap(arr[++i], arr[high]);
        return i;
    }

    int dist(vector<int> v) {
        return v[0] * v[0] + v[1] * v[1];
    }
};
