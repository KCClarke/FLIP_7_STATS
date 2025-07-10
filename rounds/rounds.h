/** @file template.h
 *
 * @brief A template for a .h file.
 *
 * @par
 * Kasey Clarke June 6 2025
 */

#ifndef ROUNDS_H
#define ROUNDS_H

#include "results/postgame.h"
#include "cards/cards.h"

#define NUM_ROUNDS 60000

void run_all_rounds(results_t tally[], card_t deck[]);

#endif /* ROUNDS_H */

/*** end of file ***/