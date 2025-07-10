/** @file player.c
 *
 * @brief The source file for player bots that stay at a given sum of the NUMBER
 * cards in their line.
 *
 * @par
 * Kasey Clarke June 6 2025
 */

//include statements
#include "player.h"
#include "points/points.h"
#include <stdio.h>

// private function prototypes
static inline bool
b_duplicate_NUMBER_card(const uint8_t quantities[]);

// public function bodies
/*!
 * @brief checks to see if the player stays.
 *
 * @param[in] player, the current player.
 * @param[in] stopping_point, the desired sum of the NUMBER cards
 *              in the players line at which to stop taking cards.
 *
 * @return true if the player stays.
 */
 bool
 b_player_stays(player_t * player)
 {
    uint8_t sum = 0;
    for (uint8_t index = 0; index < player->num_cards; ++index)
    {
        card_t card = player->line[index];
        if (get_card_type(card) == NUMBER_CARD)
        {
            sum += get_points(card);
        }
    }

    player->b_stayed = sum >= player->stopping_point;

    return (player->b_stayed);
 }


/*!
 * @brief The function to initialize a player for a new round.
 *
 * @param[in] player player to be initialized
 * @param[in] stoppint_point the sum of the NUMBER cards at which to stay
 *
 * @return void.
 */
void init_player(player_t * player, const uint8_t stopping_point)
{
    player->stopping_point = stopping_point;
    player->num_cards = 0;
    player->num_NUMBER_cards = 0;
    player->sum_of_NUMBER_cards = 0;
    
    player->b_busted = false;
    player->b_stayed = false;
}


/*!
 * @brief Adds one card to the players line, incriments their num_cards field
 *
 * @param[in] player the current player.
 * @param[in] card the card to be added to the line.
 *
 * @return void
 */
 void
 hit_player(player_t * player, const card_t card)
 {
  player->line[player->num_cards] = card;
  ++player->num_cards;

    if (player->num_cards > MAX_LINE) 
    {
      printf("\nERROR\n");
    }
 }

 /*!
  * @brief checks to see if player is busted
  *
  * @param[in] player in question
  *
  * @return true or false player busted
  */
 bool b_player_busted(player_t * player)
 {
    uint8_t quantities[UNIQUE_CARDS];
    fill_quantities(quantities, player->line, player->num_cards);
    player->b_busted = b_duplicate_NUMBER_card(quantities);
    return (player->b_busted);
 }

 
// private function bodies
/*!
 * @brief Checks for a duplicate NUMBER card
 *
 * @param[in] quantities array.
 *
 * @return true if a duplicate NUMBER card is found
*/
static inline bool
b_duplicate_NUMBER_card(const uint8_t quantities[])
{
    bool b_duplicate_found = false;

    for (uint8_t index = ZERO; index <= TWELVE; ++index)
    {
        if (quantities[index] > 1)
        {
            b_duplicate_found = true;
        }
    }

    return (b_duplicate_found);
}

/*** end of file ***/