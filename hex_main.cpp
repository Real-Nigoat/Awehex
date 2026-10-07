/* SPDX-License-Identifier: GPL-3.0-only
 * Copyright (C) 2026 Awehex contributors
 */

#include <iostream>
#include <iomanip>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please Enter A file to edit it\n";
        return 1;
    }
    const int bytes_per_row = 16;

    std::ifstream file_chosen;
    file_chosen.open(argv[1], std::ios::binary);

    while (true) {
        int row_size;
        char buffer[bytes_per_row];
        file_chosen.read(buffer, bytes_per_row);
        row_size = file_chosen.gcount();
        if (row_size == 0) {
            break;
        }
        for (int i = 0; i < row_size; i++) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(buffer[i]) << " "; // print the current byte as two digit hexadecimal
            }
         std::cout << '\n'; // end current hex row
        return 0;
        }
    }
