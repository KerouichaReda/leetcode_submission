/*
 * 1396_Design_Underground_System.cxx
 *
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
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

class UndergroundSystem {
   public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) { in[id] = make_pair(stationName, t); }

    void checkOut(int id, string stationName, int t) {
        avg[in[id].first + "_" + stationName].first += t - in[id].second;
        avg[in[id].first + "_" + stationName].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        return avg[startStation + "_" + endStation].first / avg[startStation + "_" + endStation].second;
    };

   private:
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<double, int>> avg;
};

int main(int argc, char** argv) { return 0; }
