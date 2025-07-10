/** @file test_percent.c
 *
 * @brief Holds the function to turn a floating point number
 * into a percent.
 *
 * @par
 * Kasey Clarke June 19 2025
 */

 #include "test_percent.h"
 #include "cards/cards.h"
 #include "percent/percent.h"
 #include <assert.h>

 // public function bodies
 /*!
  * @brief Tests our to_percent function.
  *
  * @param void
  *
  * @return void
  */
 void
 test_percent ()
 {
    assert(   0  == to_percent(0));
    assert(  1.1 == to_percent(1.0 / NUM_CARDS));
    assert( 33.3 == to_percent(1.0 / 3));
    assert(100   == to_percent(1));
 }
 
 /*** end of file ***/