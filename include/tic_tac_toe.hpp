#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#include "board.hpp"
namespace pamsi {
namespace tic_tac_toe {
class Game;
struct Player {
    Player(Field type)
        : type_{type}{
    }

    virtual std::pair<std::size_t, std::size_t> choose_field() = 0;
    Field type_;
};

class RealPlayer : public Player {
   public:
    RealPlayer(Field type)
        : Player(type) {}

    virtual std::pair<std::size_t, std::size_t> choose_field() override final {
        std::size_t m, n;
        std::cin >> m >> n;
        return {m, n};
    }

   private:
};

class Game {
   public:
    Game(std::size_t size = 3u, std::size_t in_row = 3u)
        : board_(size, in_row) {
    }

    void add_players(std::shared_ptr<Player> first, std::shared_ptr<Player> second) {
        players = {first, second};
        actual_player_ = players.first;
    }

    bool loop() {
        board_.print();
        std::cout << "Runda gracza: " << static_cast<char>(actual_player_->type_) << std::endl;
        auto choose = std::pair<std::size_t, std::size_t>();
        choose = actual_player_->choose_field();

        board_.put(choose.first, choose.second, actual_player_->type_);

        board_.print();
        if (is_finished()) {
            std::cout << "Wygrywa gracz: " << static_cast<char>(actual_player_->type_) << std::endl;
            return true;
        }
        if (actual_player_ == players.first) {
            actual_player_ = players.second;
        } else {
            actual_player_ = players.first;
        }
        return false;
    }

    bool is_finished() {
        return board_.diagonal_win_check() == actual_player_->type_ or board_.row_and_column_win_check() == actual_player_->type_;
    }

    std::shared_ptr<Player> actual_player_;

    Board board_;
   protected:
    std::pair<std::shared_ptr<Player>, std::shared_ptr<Player>>
        players;
};

struct MultiplayerGame: public Game {
    MultiplayerGame(std::size_t size = 3u, std::size_t in_row = 3u)
        : Game(size, in_row) {
        add_players(std::make_shared<RealPlayer>(Field::cross), std::make_shared<RealPlayer>(Field::nought));
    }
};
}  // namespace tic_tac_toe
}  // namespace pamsi