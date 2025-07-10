/** @file percent.c
 *
 * @brief Contains the implementation of to_percent function.
 *
 * @par
 * Kasey Clarke June 19 2025
 */

 //include statements
 #include "percent.h"
 #include <stdint.h>

 // private function prototypes

 // public function bodies
 /*!
  * @brief Turns a ratio into a percent.
  *
  * @param[in] ratio The floating point value wa want as a percent
  *
  * @return A percent rounded to one tenth
  */
 double
 to_percent (const double ratio)
 {
    // Truncates insignificant digits
    const uint32_t ratio_scaled = ratio * SCALE; 
    const uint16_t rounded_truncated = (ratio_scaled + 5) / 10;

    const double percent = rounded_truncated / 10.0;
    
    return (percent);
 }
 
 /*** end of file ***/