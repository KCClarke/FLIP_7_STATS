/** @file template.c
 *
 * @brief A template for a .c file.
 *
 * @par
 * Kasey Clarke July 5 2025
 */

//include statements
#include "test_dealer.h"
#include "dealer/dealer.h"
#include "cards/cards.h"
#include <assert.h>


// public function bodies
/*!
 * @brief Assert that the dealer function steps through our list 
 * oof cards as expected
 *
 * @param void
 *
 * @return void
 */
void
test_dealer()
{

  const card_t fake_deck[] = {TWO, FOUR, SIX, EIGHT, TEN};
  uint8_t top_card_index = 0;
  
  assert(TWO   == deal_card(&top_card_index, fake_deck));
  assert(1 == top_card_index);
  
  assert(FOUR  == deal_card(&top_card_index, fake_deck));
  assert(2 == top_card_index);

  assert(SIX   == deal_card(&top_card_index, fake_deck));
  assert(EIGHT == deal_card(&top_card_index, fake_deck));
  assert(TEN   == deal_card(&top_card_index, fake_deck));
  
}

/*** end of file ***/