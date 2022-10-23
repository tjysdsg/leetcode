// https://leetcode.cn/problems/text-justification/

#pragma once

#include "common.h"

class Solution {
public:
    // get n consecutive whitespaces
    string blank(int n) {
        return string(n, ' ');
    }

    // join strings with sep
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right; // index of the starting word of current line
            int line_len = 0; // length of the current line in characters
            // check how many words we can put in current line
            while (right < n && line_len + words[right].length() + right - left <= maxWidth) {
                line_len += words[right++].length();
            }

            // current line is the last line so the words are left-aligned
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int n_words = right - left; // number of words in the current line
            int n_spaces = maxWidth - line_len; // number of spaces after the text

            // the current line only contains 1 word, so left-aligned
            if (n_words == 1) {
                ans.emplace_back(words[left] + blank(n_spaces));
                continue;
            }

            // more than 1 word in this line
            int avg_spaces = n_spaces / (n_words - 1);
            int extra_spaces = n_spaces % (n_words - 1);
            // join strings that needs avg_spaces+1 whitespaces between them
            string s1 = join(words, left, left + extra_spaces + 1, blank(avg_spaces + 1));
            // join strings that needs avg_spaces whitespaces between them
            string s2 = join(words, left + extra_spaces + 1, right, blank(avg_spaces));
            ans.emplace_back(s1 + blank(avg_spaces) + s2);
        }
    }
};
