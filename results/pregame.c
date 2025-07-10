/** @file pregame.c
 *
 * @brief The file containing the functions to print information about 
 * the game FLIP 7.
 *
 * @par
 * Kasey Clarke June 20 2025
 */

 //include statements
 #include "pregame.h"
 #include "percent/percent.h"
 #include "points/points.h"
 #include <stdio.h>
 #include <stdint.h>

 // private function prototypes

 // public function bodies
 /*!
  * @brief Prints some information about the deck as a whole.
  *
  * @param[in] deck The whole deck of cards.
  *
  * @return void.
  */
 void
 print_deck_analysis(const card_t deck[])
 {
  printf("\n");
  printf("The deck contains %d cards", NUM_CARDS);
  printf(" and a total of %d points.\n", TOTAL_POINTS);
  printf("A card is worth %.1lf", 1.0 * TOTAL_POINTS / NUM_CARDS );
  printf(" points on average.\n");
  printf("\n");
 }

 /*!
  * @brief Prints a breakdown of the cards by type.
  *
  * @param void.
  *
  * @return void.
  */
 void
 print_card_analysis (const card_t deck[])
 {
  uint8_t num_cards[UNIQUE_CARDS]= {0};

  fill_quantities(num_cards, deck, NUM_CARDS);

  printf("\n%16s %10s %12s %6s\n\n",
    "card name", "quantity", "occurance", "type");

  for (uint8_t index = 0; index < UNIQUE_CARDS; ++index)
  {
    printf("%16s", get_card_name(index));
    printf("%8d", num_cards[index]);
    printf("%12.1lf%%", to_percent(1.0 * num_cards[index] / NUM_CARDS));
    printf("%12s", get_type_name(index));

    if (index == TWELVE || index == TIMES_2)
    {
      printf("\n");
    }

    printf("\n");
  }
  
 }
 
 // private function bodies

 /*** end of file ***/