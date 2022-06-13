#include "tic_tac_toe.hpp"

#include <algorithm>

#include "doctest/doctest.h"

TEST_CASE("CreateBoard") {
    CHECK_NOTHROW(pamsi::tic_tac_toe::Board board);
    pamsi::tic_tac_toe::Board board;
    std::for_each(board.begin(), board.end(), [](auto &i) {
        CHECK(i == pamsi::tic_tac_toe::Field::empty);
    });

    board.print();
    board.put_cross(1, 1);
    board.put_nought(1, 2);
    board.put_cross(2, 0);
    board.put_cross(0, 0);

    std::cout << "\n============\n";
    board.print();
    std::cout << "\n============\n";

    pamsi::tic_tac_toe::Board board_big(6);

    board_big.put_cross(1, 1);
    board_big.put_nought(1, 2);
    board_big.put_cross(4, 5);
    board_big.put_cross(4, 4);
}

TEST_CASE("Win test") {
    pamsi::tic_tac_toe::Board board2(4, 2);

    board2.put_cross(0, 0);
    CHECK(board2.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);

    board2.put_cross(0, 1);

    CHECK(board2.row_and_column_win_check() == pamsi::tic_tac_toe::Field::cross);

    pamsi::tic_tac_toe::Board board4(4, 4);
    board4.put_nought(0, 0);
    board4.put_cross(1, 0);

    board4.put_nought(0, 1);
    board4.put_cross(2, 0);

    board4.put_nought(0, 2);
    board4.put_cross(3, 0);

    board4.put_nought(0, 3);
    CHECK(board4.row_and_column_win_check() == pamsi::tic_tac_toe::Field::nought);

    pamsi::tic_tac_toe::Board board5(5, 3);
    board5.put_cross(0, 0);
    board5.put_nought(0, 1);

    board5.put_cross(1, 1);
    board5.put_nought(2, 1);

    board5.put_cross(2, 2);
    CHECK(board5.diagonal_win_check() == pamsi::tic_tac_toe::Field::cross);

    pamsi::tic_tac_toe::Board board6(5, 3);
    std::cout << "\n============\n";
    board6.put_cross(0, 3);
    board6.put_nought(0, 1);

    board6.put_cross(1, 2);
    board6.put_nought(1, 3);

    board6.put_cross(2, 1);
    board6.print();
    CHECK(board6.diagonal_win_check() == pamsi::tic_tac_toe::Field::cross);

    pamsi::tic_tac_toe::Board board(3, 3);
    board.put_cross(1, 1);
    board.put_cross(2, 1);
    board.put_cross(2, 0);
    board.put_nought(1, 0);
    board.put_nought(0, 0);

    board.print();
    CHECK(board.diagonal_win_check() == pamsi::tic_tac_toe::Field::empty);
    CHECK(board.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);
    pamsi::tic_tac_toe::Board board_a(3, 3);
    board_a.put_cross(0, 0);
    board_a.put_nought(1, 0);
    board_a.put_cross(1, 1);
    board_a.put_nought(0, 2);
    CHECK(board_a.diagonal_win_check() == pamsi::tic_tac_toe::Field::empty);
    CHECK(board_a.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);

    pamsi::tic_tac_toe::Board board_b(3, 3);
    board_b.put_cross(0, 0);
    board_b.put_nought(1, 0);
    board_b.put_cross(1, 1);
    board_b.put_nought(2, 1);
    CHECK(board_b.diagonal_win_check() == pamsi::tic_tac_toe::Field::empty);
    CHECK(board_b.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);

    pamsi::tic_tac_toe::Board board_c(3, 3);
    board_c.put_cross(0, 0);
    board_c.put_cross(1, 1);
    board_c.put_cross(1, 2);
    board_c.put_cross(2, 0);

    board_c.put_nought(1, 0);
    board_c.put_nought(2, 1);
    std::cout << "C:" << std::endl;
    board_c.print();
    CHECK(board_c.diagonal_win_check() == pamsi::tic_tac_toe::Field::empty);
    CHECK(board_c.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);

    pamsi::tic_tac_toe::Board board_d(3, 3);
    board_d.put_cross(0, 2);
    board_d.put_cross(1, 1);
    board_d.put_cross(2, 0);
    board_d.print();
    CHECK(board_d.diagonal_win_check() == pamsi::tic_tac_toe::Field::cross);
    CHECK(board_d.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);

    pamsi::tic_tac_toe::Board board_e(3, 3);
    board_e.put_nought(1, 0);
    board_e.put_nought(2, 0);
    board_e.put_nought(2, 1);
    board_e.put_nought(0, 1);

    board_e.print();
    CHECK(board_e.diagonal_win_check() == pamsi::tic_tac_toe::Field::empty);
    CHECK(board_e.row_and_column_win_check() == pamsi::tic_tac_toe::Field::empty);
}