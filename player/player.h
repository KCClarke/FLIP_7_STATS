/** @file player.h
 *
 * @brief Defines the player type.
 *
 * @par
 * Kasey Clarke July 1 2025
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "cards/cards.h"
#include <stdint.h>
#include <stdbool.h>

// A line may have at most 7 NUMBER 9 ACTION 6 MOD cards 22  total
#define MAX_LINE 22

typedef struct
{
    uint8_t stopping_point;
    uint8_t num_cards;
    uint8_t num_NUMBER_cards;
    uint8_t sum_of_NUMBER_cards;
    card_t line[MAX_LINE];
    bool b_busted;
    bool b_stayed;
} player_t;

void init_player(player_t * player, const uint8_t stopping_point);
void hit_player(player_t * player, const card_t card);
bool b_player_busted(player_t * player);
bool b_player_stays(player_t * player);

#endif /* PLAYER_H */

/*** end of file ***/