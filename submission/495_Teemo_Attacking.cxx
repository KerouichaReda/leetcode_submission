/*
 * 495_Teemo_Attacking.cxx
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

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) return 0;

    int poison_time = timeSeries[0] + duration;
    int total_duration = duration;

    for (int i = 1; i < (int)timeSeries.size(); i++) {
        if (timeSeries[i] < poison_time) {
            total_duration += timeSeries[i] - timeSeries[i - 1];
        } else {
            total_duration += duration;
        }
        poison_time = timeSeries[i] + duration;
    }

    return total_duration;
}

int main(int argc, char** argv) { return 0; }
