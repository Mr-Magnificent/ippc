/*
 * test.cxx
 * 
 * Copyright 2020 ayush <ayush@ayush-pc>
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


#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    std::multiset<int, int> myset;
    std::vector<std::pair<double, int>> myvec;
    std::cout << myset.max_size() << std::endl;
    std::cout << ULONG_MAX << std::endl;
    std::cout << myvec.max_size() << std::endl;
    long sum = (1000l * 1000 * 1000) * (1000 * 1000);
    cout << sum << endl;
    return 0;
}

