/** @file test_rounds.c
 *
 * @brief A c file to test to see if our functions
 * relatedd to playing a round is working correctly.
 *
 * @par
 * Kasey Clarke July 7 2025
 */

//include statements
#include "test_rounds.h"
#include "results/postgame.h"
#include "rounds/rounds.h"
#include <assert.h>
#include <stdio.h>

// private function prototypes

// public function bodies
/*!
 * @brief drives the tests for plating a round
 *
 * @param void.
 *
 * @return void
 */
void
test_rounds()
{
  assert(STOPPING_RANGE == 1 + MAX_STOPPING - MIN_STOPPING);
  
  printf("Passed %s.\n", __func__);
}
 
// private function bodies

/*** end of file ***/