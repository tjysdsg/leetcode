// https://leetcode.cn/problems/restore-ip-addresses/

#pragma once

#include "common.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret{};
        int n = s.length();
        if (n < 4 || n > 12) return ret;

        search(s, ret, 0, 0, "", "");
        return ret;
    }

    void search(string s, vector<string> &res, int seg_i, int i, string ip, string curr_num) {
        int n = s.length();

        // end this segment if not empty
        if (curr_num.length() > 0) {
            if (seg_i + 1 >= 4) { // if this is the last segment
                if (i == n) // add to res if all digits are used
                    res.push_back(ip);
            } else { // append "." and search for the next segment
                search(s, res, seg_i + 1, i, ip + ".", "");
            }
        }

        // add the next digit to current segment if valid
        if (curr_num.length() >= 3 || i >= n) return;
        curr_num += s[i];
        ip += s[i];
        int num = std::atoi(curr_num.c_str());
        // [0, 255] and no leading zeros
        if (num <= 255 && num >= 0 && !(curr_num[0] == '0' && curr_num.length() != 1)) {
            search(s, res, seg_i, i + 1, ip, curr_num);
        }
    }
};
