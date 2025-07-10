/** @file cards.h
 *
 * @brief Defines what a card is and its public function prototypes
 *
 * @par
 * Kasey Clarke June 9 2025
 */

 #ifndef CARDS_H
 #define CARDS_H

 #define NUM_CARDS           94
 #define NUM_NUMBER_CARDS    79
 #define NUM_MOD_CARDS        6
 #define NUM_ACTION_CARDS     9
 #define UNIQUE_CARDS        22
 #define CARD_NAME_LENGTH    20

 #include <stdint.h>
 
 typedef enum
 {
  ZERO,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  ELEVEN,
  TWELVE,

  PLUS_2,
  PLUS_4,
  PLUS_6,
  PLUS_8,
  PLUS_10,
  TIMES_2,
  
  FREEZE,
  FLIP_3,
  SECOND_CHANCE
 } card_t;

 typedef enum
 {
  NUMBER_CARD,
  MOD_CARD,
  ACTION_CARD,
 } card_type_t; 

 void init_deck(card_t deck[]);
 void fill_quantities
    (uint8_t quantities[], const card_t list[], const uint8_t length);
 char * get_card_name(const card_t card);
 card_type_t get_card_type(const card_t card);
 char * get_type_name(const card_t card);

 #endif /* CARDS_H */

 /*** end of file ***/