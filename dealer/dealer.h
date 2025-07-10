/** @file dealer.h
 *
 * @brief The public function prototypes for dealing 
 * a card to a player.
 *
 * @par
 * Kasey Clarke July 5 2025
 */

#ifndef DEALER_H
#define DEALER_H

#include "cards/cards.h"

card_t deal_card(uint8_t * top_card_index, const card_t deck[]);

#endif /* DEALER_H */

/*** end of file ***/