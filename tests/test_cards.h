/** @file card_tests.h
 *
 * @brief Contains public function prototypes for testing cards
 *
 * @par
 * Kasey Clarke June 9 2025
 */

 #ifndef CARD_TESTS_H
 #define CARD_TESTS_H

 #include "cards/cards.h"

 void test_init_deck (const card_t deck[]);
 void print_deck (const card_t deck[]);
 void test_quantities (const card_t deck[]);
 
 #endif /* CARD_TESTS_H */

 /*** end of file ***/