/** @file points.h
 *
 * @brief Contains the public function prototypes for handling points.
 *
 * @par
 * Kasey Clarke June 24 2025
 */

 #ifndef POINTS_H
 #define POINTS_H

 #include "cards/cards.h"
 #include <stdint.h>

 #define TOTAL_POINTS 680

 const uint8_t get_points(const card_t card);
 const uint16_t get_total_points(const card_t list[], const uint8_t length);

 #endif /* POINTS_H */

 /*** end of file ***/