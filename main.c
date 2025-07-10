/** @file main.c
 *
 * @brief This file contains the main function and is used to
 * drive all other functions.
 *
 * @par
 * Kasey Clarke June 6 2025
 */

 #include "cards/cards.h"
 #include "results/pregame.h"
 #include "random/random.h"
 #include "shuffle/shuffle.h"
 #include "results/postgame.h"
 #include "player/player.h"
 #include "dealer/dealer.h"
 #include "rounds/rounds.h"

 #if DEBUG
    #include "tests/tests.h"
 #endif

 /*!
  * @brief The main function for FLIP 7
  *
  * @param void
  *
  * @return Return ommited.
  */
 int main ()
 {
   card_t deck[NUM_CARDS];
   init_deck(deck);   
   seed_random();
   
   results_t tally[STOPPING_RANGE + 1];
   clear_tally(tally);

   #if DEBUG
      test_internals();
      test_init_deck(deck);
      test_quantities(deck);
      test_total_points(deck);

      shuffle(deck);
      test_quantities(deck);
      test_total_points(deck);

      test_player();
      test_rounds();

   #else
      print_card_analysis(deck);
      print_deck_analysis(deck);
      
      run_all_rounds(tally, deck);

      notes();
      print_result_analysis(tally);
   #endif

}

 /*** end of file ***/