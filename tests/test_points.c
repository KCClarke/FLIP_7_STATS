/** @file test_points.c
 *
 * @brief Contains the function bodies for testing the functions
 * that deal with points.
 *
 * @par
 * Kasey Clarke June 24 2025
 */

 #include "test_points.h"
 #include "points/points.h"
 #include <assert.h>
 #include <stdio.h>
 
 /*!
 * @brief Test the total amount of points in the deck.
 *
 * @param[in] deck the deck of all cards
 *
 * @return void
 */
 void
 test_total_points (const card_t deck[])
 {
    assert(TOTAL_POINTS == get_total_points(deck, NUM_CARDS));
    printf("Passed %s.\n", __func__);
 }

 /*!
  * @brief Tests the point value of each unique card.
  *
  * @param void
  *
  * @return void
  */
 void
 test_points ()
 {
    assert(0  == get_points(ZERO));
    assert(1  == get_points(ONE));
    assert(2  == get_points(TWO));
    assert(3  == get_points(THREE));
    assert(4  == get_points(FOUR));
    assert(5  == get_points(FIVE));
    assert(6  == get_points(SIX));
    assert(7  == get_points(SEVEN));
    assert(8  == get_points(EIGHT));
    assert(9  == get_points(NINE));
    assert(10 == get_points(TEN));
    assert(11 == get_points(ELEVEN));
    assert(12 == get_points(TWELVE));

    assert(2  == get_points(PLUS_2));
    assert(4  == get_points(PLUS_4));
    assert(6  == get_points(PLUS_6));
    assert(8  == get_points(PLUS_8));
    assert(10 == get_points(PLUS_10));
    assert(0  == get_points(TIMES_2));
 }
 
 /*** end of file ***/