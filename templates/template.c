/** @file template.c
 *
 * @brief A template for a .c file.
 *
 * @par
 * Kasey Clarke June 6 2025
 */

//include statements
#include "template.h"

// private function prototypes

// public function bodies
/*!
 * @brief An example of a function comment.
 * Identify the larger of two 8-bit integers.
 *
 * @param[in] num1 The first number to be compared.
 * @param[in] num2 The second number to be compared.
 *
 * @return The value of the larger integer.
 */
int8_t
max8 (int8_t num1, int8_t num2)
{
  return ((num1 > num2) ? num1 : num2);
}
 
// private function bodies

/*** end of file ***/