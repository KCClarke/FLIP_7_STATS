/** @file postgame.h
 *
 * @brief The header for postgame.c
 *
 * @par
 * Kasey Clarke July 1 2025
 */

 #ifndef POSTGAME_H
 #define POSTGAME_H

 /*
 * MIN_STOPPING and MAX_STOPPING define the range of values we will be testing
 * to find the optimal stopping point of flip 7.
 *
 * If each card averages 7 points seems apropriate to start tallying
 * the result of stopping at 14 pooints.
 * The maximum stopping point is the largest flip 7 before the bonus score
 * 6 + 7 + 8 + 9 + 10 + 11 + 12 = 63
 */
 #define MIN_STOPPING 14
 #define MAX_STOPPING 63
 #define STOPPING_RANGE (1 + MAX_STOPPING - MIN_STOPPING)

 #include <stdint.h>

 typedef struct
 {
    uint32_t total_points;
    uint32_t num_busts;
    uint32_t cards_flipped;
    uint16_t flip_7s;
 } results_t;

 void notes();
 void print_result_analysis(const results_t tally[]);
 void clear_tally(results_t tally[]);


 #endif /* POSTGAME_H */

 /*** end of file ***/