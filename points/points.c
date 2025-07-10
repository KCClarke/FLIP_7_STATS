
/** @file points.c
 *
 * @brief Contains the function bodies for handling points.
 *
 * @par
 * Kasey Clarke June 24 2025
 */

 #include "points.h"

 // public function bodies
 /*!
  * @brief Returns the total points for the whole deck.
  *
  * @param[in] The whole deck of cards.
  *
  * @return the sum total of points
  */
 const uint16_t
 get_total_points(const card_t deck[], const uint8_t length)
 {
    uint16_t sum = 0;

    for (uint8_t index = 0; index < length; ++index)
    {
        sum += get_points(deck[index]);
    }

    return (sum);
 }


 /*!
  * @brief Returns the value of points for a single card.
  *
  * @param[in] card the card in question.
  *
  * @return The point value of the card.
  */
 const uint8_t
 get_points(const card_t card)
 {
    uint8_t points;

    switch (card)
    {
        case PLUS_2:
        {
            points = 2;
            break;
        }
        case PLUS_4:
        {
            points = 4;
            break;
        }
        case PLUS_6:
        {
            points = 6;
            break;
        }
        case PLUS_8:
        {
            points = 8;
            break;
        }
        case PLUS_10:
        {
            points = 10;
            break;
        }
        default:
        {
            points = 0;
            break;
        }
    }

    if(get_card_type(card) == NUMBER_CARD)
    {
        points = card;
    }

    return (points);
 }
 
 /*** end of file ***/