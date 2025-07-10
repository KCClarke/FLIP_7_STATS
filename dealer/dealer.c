/** @file dealer.c
 *
 * @brief A template for a .c file.
 *
 * @par
 * Kasey Clarke July 5 2025
 */

#include "dealer.h"

// public function bodies
/*!
 * @brief The dealer function returns the top card and advances 
 * the index of the top of the deck
 *
 * @param[in] top_card_index a pointer to the top card's index
 * @param[in] deck[] the list of cards we are calling the deck
 *
 * @return The top card of the deck according to our index.
 */
card_t 
deal_card(uint8_t * top_card_index, const card_t deck[])
{

  const card_t top_card = deck[*top_card_index];
  
  ++(*top_card_index);
  
  return (top_card);
}
 
/*** end of file ***/