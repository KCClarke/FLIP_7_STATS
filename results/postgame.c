/** @file postgame.c
 *
 * @brief The file containing the functions to print results from 
 * running round simulations of the game FLIP 7.
 *
 * @par
 * Kasey Clarke July 1 2025
 */

 //include statements
 #include "postgame.h"
 #include "percent/percent.h"
 #include "rounds/rounds.h"
 #include <stdint.h>
 #include <stdio.h>

 // private function prototypes
 double rounded_to_tenth(const double raw);

 // public function bodies
 /*!
  * @brief clears the tally for postgame results
  *
  * @param[in] tally[] the array to hold our results
  *
  * @return void
  */
  void
  clear_tally(results_t tally[])
  {
    for (uint8_t index = 0; index < STOPPING_RANGE; ++ index)
    {
        tally[index].total_points = 0;
        tally[index].num_busts = 0;
        tally[index].cards_flipped = 0;
        tally[index].flip_7s = 0;
    }

  }
 
 /*!
  * @brief Prints notes about my aproach to the results.
  *
  * @param[in] void
  *
  * @return void.
  */
 void
 notes()
 {
  printf("Optimal stopping is determined by sum of the NUMBER cards.\n");
  printf("The test ends at the highest flip 7 line before bonus.\n");
  printf("Each stopping point is tested %d times.\n", NUM_ROUNDS);
  printf("Assuming action cards and x2 do nothing.\n");
  printf("\n");
 }

 /*!
  * @brief Prints a table of results
  *
  * @param void.
  *
  * @return void.
  */
 void
 print_result_analysis(const results_t tally[])
 {
    printf("%12s %8s %8s %12s %8s\n", 
      "stopping", "yeild", "bust", "avg cards", "flip 7");
    printf("\n");

    for (uint8_t index = 0; index < STOPPING_RANGE; ++index)
    {

        printf("%10d", index + MIN_STOPPING);

        const double yeild = 1.0 * tally[index].total_points / NUM_ROUNDS;
        printf("%10.1f", rounded_to_tenth(yeild));

        const double bust_ratio = 1.0 * tally[index].num_busts / NUM_ROUNDS;
        printf("%9.1f%%", to_percent(bust_ratio));

        const double avg_cards = 1.0 * tally[index].cards_flipped / NUM_ROUNDS;
        printf("%10.1f", rounded_to_tenth(avg_cards));

        const double avg_flip_7s = 1.0 * tally[index].flip_7s / NUM_ROUNDS;
        printf("%9.1f%%", to_percent(avg_flip_7s));

        printf("\n");
    }

    printf("\n");
 }
 
 // private function bodies
 /*!
 * @brief Rounds input to one tenth percision for printing
 *
 * @param[in] raw, the data to be rounded.
 *
 * @return the rounded data
 */
 double rounded_to_tenth(const double raw)
 {
    const double scaled_up = raw * 1000 + 5;
    const uint32_t truncated = scaled_up;
    return (truncated / 1000.0);
 }
 /*** end of file ***/