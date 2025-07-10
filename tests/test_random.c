/** @file test_random.c
 *
 * @brief A file to test the random number generator.
 *
 * @par
 * Kasey Clarke June 25 2025
 */

//include statements
#include "test_random.h"
#include "random/random.h"
#include <stdint.h>
#include <stdio.h>

// private function prototypes
// public function bodies
/*!
 * @brief Check connectivity, call from main to see ouput.
 *
 * @param void
 *
 * @return void
 */
void
hello_random ()
{
printf("%s\n", __func__);
for (uint8_t line = 0; line < 10; ++line)
{
  for (uint8_t index = 0; index < 10; ++index)
  {
    printf(" %d", random_number(10));
  }

  printf("\n");
}

}

// private function bodies

/*** end of file ***/