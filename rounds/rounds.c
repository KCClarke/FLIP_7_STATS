/** @file rounds.c
 *
 * @brief Contains the functions to simulate flip_7 play
 *
 * @par
 * Kasey Clarke July 7 2025
 */

//include statements
#include "rounds.h"
#include "shuffle/shuffle.h"
#include "dealer/dealer.h"
#include "player/player.h"
#include "points/points.h"
#include <stdint.h>
#include <stdio.h>

// private function prototypes
static inline void 
single_round (const int8_t tally_index, results_t tally[], card_t deck[]);

// public function bodies
/*!
* @brief controlls the paramaters of each round
*
* @param[in] tally[] the tally from main to keep track
* of the rusults of the rounds
*
* @ return void
*/
void
run_all_rounds(results_t tally[], card_t deck[])
{
  printf("%s\n\n", __func__);

  for (uint8_t tally_index = 0; tally_index <= STOPPING_RANGE; ++tally_index)
  {
    for (uint16_t rounds = 0; rounds < NUM_ROUNDS; ++rounds)
    {
      single_round(tally_index, tally, deck);
    }

  }
}

// private function bodies
/*!
 * @brief Runs a single round
 *
 * @param[in] tally_index, where to save the tally, also
 * where to stop the test
 *
 * @return void
 */
static inline void
single_round (const int8_t tally_index, results_t tally[], card_t deck[])
{
  shuffle(deck);
  uint8_t top_card_index = 0;
  player_t player;
  const uint8_t stopping_point = tally_index + MIN_STOPPING;
  init_player(&player, stopping_point);
  uint8_t round_points = 0;

  for (uint8_t hits = 0; hits < MAX_LINE; ++hits)
  {

    if (player.num_cards >= 2  && b_player_busted(&player))
    {
      tally[tally_index].num_busts += 1;
      break;
    }
    
    if (player.sum_of_NUMBER_cards >= stopping_point)
    {
      round_points = get_total_points(player.line, player.num_cards);
      break;
    }
    
    if (player.num_NUMBER_cards == 7)
    {
      const uint8_t bonus = 15;
      tally[tally_index].total_points += bonus;
      tally[tally_index].flip_7s += 1;

      round_points = get_total_points(player.line, player.num_cards);
      break;
    }
  
    const card_t card = deal_card(&top_card_index, deck);
    hit_player(&player, card);
    if (NUMBER_CARD == get_card_type(card))
    {
      player.num_NUMBER_cards += 1;
      player.sum_of_NUMBER_cards += card;
    }

  }

  tally[tally_index].cards_flipped += player.num_cards;
  tally[tally_index].total_points += round_points;
}
 

/*** end of file ***/