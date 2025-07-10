/** @file shuffle.c
 *
 * @brief Defines the function for shuffling the deck.
 *
 * @par
 * Kasey Clarke June 30 2025
 */

//include statements
#include "shuffle.h"
#include "random/random.h"

// private function prototypes
static inline void 
swap(card_t deck[], const uint8_t index_a, const uint8_t index_b);

// public function bodies
/*!
 * @brief Shuffles the deck of cards.
 *
 * @param[in] deck[] the deck of cards.
 *
 * @return void.
 */
void
shuffle (card_t deck[])
{
  for (uint8_t index = NUM_CARDS - 1; index > 0; --index)
  {
    swap(deck, index, random_number(index + 1));
  }

}
 
// private function bodies
/*!
 * @brief Swaps two cards of the deck.
 *
 * @param[in] deck[] the deck of cards.
 * @param[in] index_a the index of the deck.
 * @param[in] index_b the index of the deck.
 *
 * @return void.
 */
static inline void 
swap(card_t deck[], const uint8_t index_a, const uint8_t index_b)
{
  const card_t tmp_card = deck[index_a];
  deck[index_a] = deck[index_b];
  deck[index_b] = tmp_card;
}
 

/*** end of file ***/