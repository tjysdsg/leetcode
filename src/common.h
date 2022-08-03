#pragma once

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }

    bool operator==(const TreeNode &other) {
        if (val != other.val) return false;
        if (!left) {
            if (other.left)
                return false;
        } else {
            if (!other.left || *left != *other.left) return false;
        }

        if (!right) {
            if (other.right)
                return false;
        } else {
            if (!other.right || *right != *other.right) return false;
        }

        return true;
    }

    bool operator!=(const TreeNode &other) {
        return !this->operator==(other);
    }

    /**
     * Create a tree from a binary heap
     */
    static TreeNode *from_heap(std::vector<int> v, int empty_val = -1) {
        std::vector<TreeNode *> nodes{};
        for (int val: v) {
            if (val != empty_val)
                nodes.push_back(new TreeNode(val));
            else
                nodes.push_back(nullptr);
        }

        int n = v.size();
        for (int i = 0; i < n; ++i) {
            if (nodes[i]) {
                if (2 * i + 1 < n)
                    nodes[i]->left = nodes[2 * i + 1];
                if (2 * i + 2 < n)
                    nodes[i]->right = nodes[2 * i + 2];
            }
        }

        return nodes[0];
    }

    /**
     * Convert tree to a binary heap
     */
    std::vector<int> to_heap(int empty_val = -1) {
        std::vector<int> ret{};

        std::deque<TreeNode *> q{};
        q.push_back(this);
        while (!q.empty()) {
            int n = q.size();
            bool valid_level = false; // false if no nodes in this level
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front();
                q.pop_front();

                if (t) {
                    valid_level = true;
                    ret.push_back(t->val);
                    q.push_back(t->left);
                    q.push_back(t->right);
                } else {
                    ret.push_back(empty_val);
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                }
            }

            if (!valid_level) break;
        }

        return std::move(ret);
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode *from_array(std::vector<int> v) {
        ListNode fake;

        auto *prev = &fake;
        for (int e: v) {
            prev->next = new ListNode(e);
            prev = prev->next;
        }

        return fake.next;
    }

    std::vector<int> to_array() {
        std::vector<int> ret;

        ListNode *n = this;
        while (n) {
            ret.push_back(n->val);
            n = n->next;
        }

        return ret;
    }
};