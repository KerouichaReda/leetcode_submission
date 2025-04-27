/*
 * 299_Bulls_and_Cows.cxx
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
#include <string>
/*
 * string getHint(string secret, string guess) {
        vector<int>tb_guess(10),tb_secret(10);
        int A=0,B=0;
        for (int i=0;i<secret.size();++i){
            if (secret[i]==guess[i]) A++;
            else {
                tb_guess[guess[i]-'0']++;
                tb_secret[secret[i]-'0']++;
            }
        }
        for (int i=0;i<10;++i){
            B=B+ min(tb_guess[i],tb_secret[i]);
        }
        return to_string(A)+'A'+to_string(B)+'B';
    }*/
std::string getHint(std::string secret, std::string guess) {
    int a = 0, b = 0;
    bool Aa[secret.length()], Bb[secret.length()];
    std::string result;

    for (int i = 0; i < secret.length(); i++) {
        Aa[i] = false;
        Bb[i] = false;
    }

    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) {
            a++;
            Aa[i] = true;
            Bb[i] = true;
        }
    }

    for (int i = 0; i < secret.length(); i++) {
        if (!Aa[i]) {
            for (int j = 0; j < secret.length(); j++) {
                if (secret[i] == guess[j] && !Bb[j]) {
                    b++;
                    Bb[j] = true;
                    break;
                }
            }
        }
    }
    result = std::to_string(a) + "A" + std::to_string(b) + "B";
    return result;
}
int main(int argc, char** argv) { return 0; }
