/** @file percent.h
 *
 * @brief Contains the public function prototype
 * for converting a floating point number into a percent
 * rounded to one tenth.
 * 
 * Contains the SCALE macro, may be usefull for 
 * avoiding floating point comparisons later in the program.
 *
 * @par
 * Kasey Clarke June 19 2025
 */

 #ifndef PERCENT_H
 #define PERCENT_H

 #define SCALE 10000

 double to_percent(const double ratio);

 #endif /* PERCENT_H */

 /*** end of file ***/