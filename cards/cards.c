/** @file cards.c
 *
 * @brief Contains fonctions for the dealing with card types in
 * setting up the game.
 *
 * @par
 * Kasey Clarke June 10 2025
 */

 #include "cards.h"
 #include <stdio.h>

 // private function prototypes
 static inline void init_action_cards (card_t deck[]);
 static inline void init_score_mod_cards (card_t deck[]);
 static inline void init_number_cards (card_t deck[]);
 static inline void init_card_quantities (uint8_t card_quantities[]);
 

 // public function body
 /*!
  * @brief Given a card returns what of the three types it is.
  * Assumes a valid card is given.
  *
  * @param[in] card, The card in question.
  *
  * @return The type of card.
  */
 card_type_t
 get_card_type(const card_t card)
 {
    card_type_t type;

    switch (card)
    {
        
        case PLUS_2:
        case PLUS_4:
        case PLUS_6:
        case PLUS_8:
        case PLUS_10:
        case TIMES_2:
        {
            type = MOD_CARD;
            break;
        }
        
        case FREEZE:
        case FLIP_3:
        case SECOND_CHANCE:
        {
            type = ACTION_CARD;
            break;
        }
        
        default:
        {
            type = NUMBER_CARD;
        break;
        }
    }
    
    return (type);
 }

 /*!
  * @brief This function returns a string that is the name of
  * the given cards type for the purpose of printing
  *
  * @param[in] card The card i question
  *
  * @return the name of the cad's type.
  */
 char *
 get_type_name(const card_t card)
 {
    char * type_names[] =
    {
        "number",
        "mod",
        "action"
    };

    return (type_names[get_card_type(card)]);
 }

 /*!
  * @brief Given a card number will return its name as a string.
  *
  * @param[in] card the card in question.
  *
  * @return the name of a card as a string as written on the physical cards.
  */
 char *
 get_card_name(const card_t card)
 {
  char * names[UNIQUE_CARDS] =
  {
   "ZERO",
   "ONE",
   "TWO",
   "THREE",
   "FOUR",
   "FIVE",
   "SIX",
   "SEVEN",
   "EIGHT",
   "NINE",
   "TEN",
   "ELEVEN",
   "TWELVE",
   "+2",
   "+4",
   "+6",
   "+8",
   "+10",
   "x2",
   "FREEZE",
   "FLIP THREE",
   "SECOND CHANCE"
  };

  return (names[card]);
 }


 /*!
  * @brief This functions fills an array with how many of each unique card
  * type there is. For example card_quantities[TWELVE] should = 12.
  * Assumes the deck is initialized.
  *
  * @param[in] quantities[] the array to be filled
  * @param[in] list[], could be the whole deck, could be the player's line
  * @param[in] length, if the deck is sent we probably need NUM_CARDS
  *             if its the player's list of cards we need their num_cards
  *
  * @return void
  */
 void
 fill_quantities 
 (uint8_t quantities[], const card_t list[], const uint8_t length)
 {
    init_card_quantities (quantities);
    
    for (uint8_t index = 0; index < length; ++index)
    {
        const card_t card = list[index];
        ++quantities[card];
    }
 }

 /*!
  * @brief This function initializes the deck of cards.
  *
  * @param[in] deck[] the array of type card_t from main.
  *
  * @return void
  */
 void
 init_deck (card_t deck[])
 {  
    init_number_cards(deck);
    init_score_mod_cards(deck);
    init_action_cards(deck);
 }

 
 //private function bodies
 /*!
  *
  * @brief fills the quantities array with 0 0 0 0 0
  * 
  * @param[in] card_quantities the number of each type of card in the array
  *
  * @return void
  */
 static inline void
 init_card_quantities(uint8_t card_quantities[])
 {
   for (uint8_t index = 0; index < UNIQUE_CARDS; ++index)
   {
       card_quantities[index] = 0;
   }
 }
 
 /*!
  * @brief This function initializes the action cards.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 init_action_cards (card_t deck[])
 {
    uint8_t index = NUM_NUMBER_CARDS + NUM_MOD_CARDS;
    card_t card = FREEZE;
    const uint8_t num_each = 3;
 
    while (card <= SECOND_CHANCE)
    {
        for(uint8_t num = 0; num < num_each; ++num)
        {
            deck[index] = card;
            ++index;
        }
 
        ++card;
    }
 }

 
 /*!
  * @brief This function initializes the score modifier cards.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 init_score_mod_cards (card_t deck[])
 {
    uint8_t index = NUM_NUMBER_CARDS;
    card_t card = PLUS_2;
 
    while (card <= TIMES_2)
    {
        deck[index] = card;
        ++card;
        ++index;
    }
 }


 /*!
  * @brief This function initializes the number cards.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 init_number_cards (card_t deck[])
 {
    uint8_t index = 0;

    deck[index]  = ZERO;

    card_t card  = ONE;

    while (card <= TWELVE)
    {
        for (uint8_t num_cards = 0; num_cards < card; ++num_cards)
        {
            ++index;
            deck[index] = card;
        }

        ++card;
    }

 }

 /*** end of file ***/