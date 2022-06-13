#pragma once

#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "tic_tac_toe.hpp"

#define UNUSED(x) x
namespace pamsi {
namespace tic_tac_toe {
struct AiMove {
    AiMove() = default;
    AiMove(double cost)
        : cost_{cost} {
    }
    std::size_t n_;
    std::size_t m_;
    double cost_;
};

class AiPlayer : public Player {
   public:
    AiPlayer(Field type, Game *game)
        : Player(type), game_(game) {
    }

    virtual std::pair<std::size_t, std::size_t> choose_field() override final {
        auto best_move = get_best_move(type_);
        return {best_move.n_, best_move.m_};
    }

   private:
    std::shared_ptr<Game> game_;
    // double cut_cost = std::numeric_limits<double>::min()
    AiMove get_best_move(Field player_round) {
        auto type1 = game_->board_.diagonal_win_check();
        auto type2 = game_->board_.row_and_column_win_check();
        if (type1 == type_ or type2 == type_) {
            return AiMove(-10.0);
        } else if (type1 == Field::empty and type2 == Field::empty) {
            bool found = false;
            for (auto i = 0u; i < game_->board_.size(); ++i) {
                for (auto j = 0u; j < game_->board_.size(); ++j) {
                    if (game_->board_(i, j) == Field::empty) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                return AiMove(0.0);
            }
        } else {
            return AiMove(10.0);
        }

        // TODO: change to graph
        auto iter = 0u;
        std::vector<AiMove> moves;
        for (auto i = 0u; i < game_->board_.size(); ++i) {
            for (auto j = 0u; j < game_->board_.size(); ++j) {
                if (game_->board_(i, j) == Field::empty) {
                    ++iter;
                    AiMove move;
                    move.n_ = i;
                    move.m_ = j;
                    game_->board_.put(i, j, player_round);

                    if (player_round == Field::cross) {
                        move.cost_ = get_best_move(Field::nought).cost_;
                    } else {
                        move.cost_ = get_best_move(Field::cross).cost_;
                    }
                    moves.push_back(move);

                    game_->board_.put(i, j, Field::empty);
                }
            }
        }

        double best_move_cost = 0;
        auto best_move = AiMove();
        if (player_round == Field::nought) {
            best_move_cost = std::numeric_limits<double>::max();
            for (auto &move : moves) {
                if (move.cost_ < best_move_cost) {
                    best_move_cost = move.cost_;
                    best_move = move;
                }
            }
        } else {
            best_move_cost = std::numeric_limits<double>::min();
            for (auto &move : moves) {
                if (move.cost_ > best_move_cost) {
                    best_move_cost = move.cost_;
                    best_move = move;
                }
            }
        }

        return best_move;
    }
};

struct SinglePlayerGame : public Game {
    SinglePlayerGame(std::size_t size = 3u, std::size_t in_row = 3u)
        : Game(size, in_row) {
        add_players(std::make_shared<RealPlayer>(Field::cross), std::make_shared<AiPlayer>(Field::nought, this));
    }
};
}  // namespace tic_tac_toe
}  // namespace pamsi