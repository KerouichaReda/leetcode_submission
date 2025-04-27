/*
 * 763_Partition_Labels.cxx
 *
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <iostream>
#include <vector>
/*
 * vector<int> partitionLabels(string S) {
  vector<int> res, pos(26, 0);
  for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
  for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
    idx = max(idx, pos[S[i] - 'a']);
    if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
  }
  return res;
}*/
std::vector<int> partitionLabels(std::string S) {
    // void partitionLabels(std::string S) {
    std::string sub = S;
    std::vector<int> solution, st;

    char firstchar;
    int last = 0, firstlast = 0, index = 0;

    while (sub.length() > 0) {
        // sub.length()>0
        std::cout << sub << std::endl;
        firstchar = sub[0];
        for (int i = 1; i < (int)sub.length(); i++) {
            if (sub[i] == firstchar) {
                firstlast = i;
            }
        }
        l

            for (int i = 1; i < last + 1; i++) {
            for (int j = 2; j < (int)sub.length(); j++) {
                std::cout << j << " ";
                if (sub[j] == sub[i] && j >= last) {
                    last = j;
                }
            }
            std::cout << std::endl;
        }
        if (firstlast > last) {
            last = firstlast;
        }

        sub = sub.substr(last + 1);
        std::cout << sub << " " << firstlast << " " << last << std::endl;
        solution.push_back(last + 1);
        last = 0;
        firstlast = 0;
        index++;
    }

    return solution;
}
int main(int argc, char** argv) {
    std::vector<int> s = partitionLabels("caedbdedda");

    for (int i = 0; i < (int)s.size(); i++) {
        std::cout << s[i] << " ";
    }
    return 0;
}
