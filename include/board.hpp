#pragma once

#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
namespace pamsi {
namespace tic_tac_toe {
enum class Field : char {
    empty = ' ',
    nought = 'O',
    cross = 'X',
    finished = 'F'
};

class Board {
   public:
    Board(std::size_t size = 3u, std::size_t in_row = 3u)
        : size_{size}, in_row_{in_row} {
        fields_ = std::vector<Field>(size * size, Field::empty);
    };
    Board(const Board &other) = default;

    std::vector<pamsi::tic_tac_toe::Field>::iterator begin() {
        return fields_.begin();
    }

    std::vector<pamsi::tic_tac_toe::Field>::iterator end() {
        return fields_.end();
    }

    void put(std::size_t n, std::size_t m, Field type) {
        fields_[n + m * size_] = type;
    }

    void put_cross(std::size_t n, std::size_t m) {
        fields_[n + m * size_] = Field::cross;
    }

    void put_nought(std::size_t n, std::size_t m) {
        fields_[n + m * size_] = Field::nought;
    }
    Field &operator()(std::size_t n, std::size_t m) {
        return fields_[n + m * size_];
    }

    void print() {
        // system("clear");
        std::cout << "  ";

        for (auto i = 0u; i < size_; ++i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (auto i = 0u; i < size_ * size_; ++i) {
            if (i % size_ == 0) {
                std::cout << i / size_ << " ";
            }
            std::cout << static_cast<char>(fields_[i]);

            if (not((i + 1) % size_) and i != size_ * size_ - 1) {
                std::cout << std::endl;
                std::cout << "  ";

                for (auto j = 0u; j < 2 * size_ - 1; ++j) {
                    std::cout << '-';
                }
                std::cout << std::endl;

            } else if ((i + 1) % size_) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }

    std::size_t size() const {
        return size_;
    }

    std::size_t in_row() const {
        return in_row_;
    }

    Field row_and_column_win_check() {
        std::size_t cross_in_row = 0;
        std::size_t nought_in_row = 0;

        std::size_t cross_in_column = 0;
        std::size_t nought_in_column = 0;

        for (auto i = 0u; i < size_; ++i) {
            for (auto j = 0u; j < size_; ++j) {
                if ((*this)(i, j) == Field::cross) {
                    ++cross_in_row;
                    nought_in_row = 0;
                } else if (fields_[i + size_ * j] == Field::nought) {
                    ++nought_in_row;
                    cross_in_row = 0;
                } else {
                    nought_in_row = 0;
                    cross_in_row = 0;
                }

                if ((*this)(j, i) == Field::cross) {
                    ++cross_in_column;
                    nought_in_column = 0;
                } else if ((*this)(j, i) == Field::nought) {
                    ++nought_in_column;
                    cross_in_column = 0;
                } else {
                    cross_in_column = 0;
                    nought_in_column = 0;
                }

                if (cross_in_row == in_row_ or cross_in_column == in_row_) {
                    return Field::cross;
                }
                if (nought_in_row == in_row_ or nought_in_column == in_row_) {
                    return Field::nought;
                }
            }
            nought_in_row = 0;
            cross_in_row = 0;
            cross_in_column = 0;
            nought_in_column = 0;
        }
        return Field::empty;
    }

    Field diagonal_win_check() {
        std::size_t cross_in_dia = 0;
        std::size_t nought_in_dia = 0;

        for (auto i = 0u; i < size_ - in_row_ / 2; ++i) {
            for (auto j = 0u; j < size_ - in_row_ / 2; ++j) {
                for (auto k = 0; k + i < size_ and k + j < size_; ++k) {
                    auto n = k + i;
                    auto m = k + j;
                    if ((*this)(n, m) == Field::cross) {
                        ++cross_in_dia;
                        nought_in_dia = 0;
                    } else if ((*this)(n, m) == Field::nought) {
                        ++nought_in_dia;
                        cross_in_dia = 0;
                    } else {
                        cross_in_dia = 0;
                        nought_in_dia = 0;
                    }
                    if (cross_in_dia == in_row_) {
                        return Field::cross;
                    }
                    if (nought_in_dia == in_row_) {
                        return Field::nought;
                    }
                }
                cross_in_dia = 0;
                nought_in_dia = 0;
                for (auto k = size_ - 1; k - i < std::numeric_limits<std::size_t>::max() and size_ - 1 - k -j < std::numeric_limits<std::size_t>::max(); --k) {
                    auto n = k - i;
                    auto m = size_ - 1 - k - j;
                    if ((*this)(n, m) == Field::cross) {
                        ++cross_in_dia;
                        nought_in_dia = 0;
                    } else if ((*this)(n, m) == Field::nought) {
                        ++nought_in_dia;
                        cross_in_dia = 0;
                    } else {
                        cross_in_dia = 0;
                        nought_in_dia = 0;
                    }
                    if (cross_in_dia == in_row_) {
                        return Field::cross;
                    }
                    if (nought_in_dia == in_row_) {
                        return Field::nought;
                    }
                }
                cross_in_dia = 0;
                nought_in_dia = 0;
            }
        }
        return Field::empty;
    }

   private:
    std::vector<Field> fields_;
    std::size_t size_;
    std::size_t in_row_;
};

}  // namespace tic_tac_toe
}  // namespace pamsi
