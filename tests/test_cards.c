/** @file card_tests.c
 *
 * @brief The purpose of this file is to test the cards and their setup.
 *
 * @par
 * Kasey Clarke June 9 2025
 */
 

 // include statements
 #include "test_cards.h"
 #include <stdint.h>
 #include <assert.h>
 #include <stdio.h>
 #include <string.h>


 // private function prototypes
 static inline void test_init_action_cards (const card_t deck[]);
 static inline void test_init_mod_cards (const card_t deck[]);
 static inline void test_init_number_cards (const card_t deck[]);
 static inline void test_check_totals ();
 static inline void test_card_definition ();
 static inline void test_card_names ();
 static inline void test_card_types ();
 static inline void test_type_names();
 
 
 // Public function bodies
 /*!
  * @brief This Function checks the quantities of each unique
  * kind of card.
  * 
  * @param[in] deck[] the deck of cards o be checked.
  *
  * @return void
  */
 void
 test_quantities(const card_t deck[])
 {
    uint8_t card_quantities[UNIQUE_CARDS];

    fill_quantities(card_quantities, deck, NUM_CARDS);

    assert(1  == card_quantities[ZERO]);
    assert(1  == card_quantities[ONE]);
    assert(2  == card_quantities[TWO]);
    assert(3  == card_quantities[THREE]);
    assert(4  == card_quantities[FOUR]);
    assert(5  == card_quantities[FIVE]);
    assert(6  == card_quantities[SIX]);
    assert(7  == card_quantities[SEVEN]);
    assert(8  == card_quantities[EIGHT]);
    assert(9  == card_quantities[NINE]);
    assert(10 == card_quantities[TEN]);
    assert(11 == card_quantities[ELEVEN]);
    assert(12 == card_quantities[TWELVE]);

    assert(1 == card_quantities[PLUS_2]);
    assert(1 == card_quantities[PLUS_4]);
    assert(1 == card_quantities[PLUS_6]);
    assert(1 == card_quantities[PLUS_8]);
    assert(1 == card_quantities[PLUS_10]);
    assert(1 == card_quantities[TIMES_2]);

    assert(3 == card_quantities[FREEZE]);
    assert(3 == card_quantities[FLIP_3]);
    assert(3 == card_quantities[SECOND_CHANCE]);
    
    printf("Passed %s.\n", __func__);
 }

 /*!
  * @brief This function is responsible for running
  * test to see if the deck of cards in initialized
  * properly.
  *
  * @param[in] deck[] the array of type card_t from main.
  *
  * @return void
  */
 void
 test_init_deck (const card_t deck[])
 {
   test_check_totals();
   test_card_definition();
   
   test_init_number_cards(deck);
   test_init_mod_cards(deck);
   test_init_action_cards(deck);

   test_card_names();
   test_card_types();
   test_type_names();
   
   printf("Passed %s.\n", __func__);
 }
 
 /*!
  * @brief Prints the deck of cards as integers to the terminal.
  *
  * @param[in] deck[] deck of cards
  *
  * @return void
  */
 void
 print_deck(const card_t deck[])
 {
    for(uint8_t index = 0; index < NUM_CARDS; ++index)
    {
        printf("%2d ", deck[index]);
        
        if (deck[index] != deck[1 + index])
        {
            printf("\n");
        }
    }
 }


 // private function bodies
 /*!
  * @brief This function checks the names of the card types.
  *
  * @param void
  *
  * @return void 
  */
 static inline void
 test_type_names()
 {
  // Assert there is 0 difference.
  assert(0 == strcmp("number", get_type_name(ZERO)));
  assert(0 == strcmp("number", get_type_name(ONE)));
  assert(0 == strcmp("number", get_type_name(TWO)));
  assert(0 == strcmp("number", get_type_name(THREE)));
  assert(0 == strcmp("number", get_type_name(FOUR)));
  assert(0 == strcmp("number", get_type_name(FIVE)));
  assert(0 == strcmp("number", get_type_name(SIX)));
  assert(0 == strcmp("number", get_type_name(SEVEN)));
  assert(0 == strcmp("number", get_type_name(EIGHT)));
  assert(0 == strcmp("number", get_type_name(NINE)));
  assert(0 == strcmp("number", get_type_name(TEN)));
  assert(0 == strcmp("number", get_type_name(ELEVEN)));
  assert(0 == strcmp("number", get_type_name(TWELVE)));

  assert(0 == strcmp("mod", get_type_name(PLUS_2)));
  assert(0 == strcmp("mod", get_type_name(PLUS_4)));
  assert(0 == strcmp("mod", get_type_name(PLUS_6)));
  assert(0 == strcmp("mod", get_type_name(PLUS_8)));
  assert(0 == strcmp("mod", get_type_name(PLUS_10)));
  assert(0 == strcmp("mod", get_type_name(TIMES_2)));

  assert(0 == strcmp("action", get_type_name(FREEZE)));
  assert(0 == strcmp("action", get_type_name(FLIP_3)));
  assert(0 == strcmp("action", get_type_name(SECOND_CHANCE)));
 }


 /*!
  * @brief This function checks to see if the names are sent correctly
  * from their home function.
  *
  * @param void
  *
  * @return void
  */
  static inline void
  test_card_names()
  {
    assert(0 == strcmp("ZERO",   get_card_name(ZERO)));
    assert(0 == strcmp("ONE",    get_card_name(ONE)));
    assert(0 == strcmp("TWO",    get_card_name(TWO)));
    assert(0 == strcmp("THREE",  get_card_name(THREE)));
    assert(0 == strcmp("FOUR",   get_card_name(FOUR)));
    assert(0 == strcmp("FIVE",   get_card_name(FIVE)));
    assert(0 == strcmp("SIX",    get_card_name(SIX)));
    assert(0 == strcmp("SEVEN",  get_card_name(SEVEN)));
    assert(0 == strcmp("EIGHT",  get_card_name(EIGHT)));
    assert(0 == strcmp("NINE",   get_card_name(NINE)));
    assert(0 == strcmp("TEN",    get_card_name(TEN)));
    assert(0 == strcmp("ELEVEN", get_card_name(ELEVEN)));
    assert(0 == strcmp("TWELVE", get_card_name(TWELVE)));
  
    assert(0 == strcmp("+2",  get_card_name(PLUS_2)));
    assert(0 == strcmp("+4",  get_card_name(PLUS_4)));
    assert(0 == strcmp("+6",  get_card_name(PLUS_6)));
    assert(0 == strcmp("+8",  get_card_name(PLUS_8)));
    assert(0 == strcmp("+10", get_card_name(PLUS_10)));
    assert(0 == strcmp("x2",  get_card_name(TIMES_2)));
  
    assert(0 == strcmp("FREEZE",        get_card_name(FREEZE)));
    assert(0 == strcmp("FLIP THREE",    get_card_name(FLIP_3)));
    assert(0 == strcmp("SECOND CHANCE", get_card_name(SECOND_CHANCE)));
 }

 /*!
  * @brief This function test to see if the action cards are initialized.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 test_init_action_cards (const card_t deck[])
 {
  uint8_t index = NUM_NUMBER_CARDS + NUM_MOD_CARDS;

  card_t card = FREEZE;
  const uint8_t num_each = 3;

  while (card <= SECOND_CHANCE)
  {
      for(uint8_t num = 0; num < num_each; ++num)
      {
          assert(card == deck[index]);
          ++index;
      }

      ++card;
  }

  assert(NUM_CARDS == index);
 }

 /*!
  * @brief This function test the initialization of the score modifier cards.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 test_init_mod_cards (const card_t deck[])
 {
    uint8_t index = NUM_NUMBER_CARDS;
    card_t card = PLUS_2;

    while (card <= TIMES_2)
    {
        assert(card == deck[index]);
        ++index;
        ++card;
    }

    assert(NUM_NUMBER_CARDS + NUM_MOD_CARDS == index);
 }

 /*!
  * @brief This function test to see if we have the correct aount of
  * each number card.
  *
  * @param[in] deck[] the array of type card_t from init number cards.
  *
  * @return void
  */
 static inline void
 test_init_number_cards (const card_t deck[])
 {
    uint8_t index = 0;
    assert(ZERO == deck[index]);
    
    card_t card = ONE;
    while(card <= TWELVE)
    {
        for (uint8_t num = 0; num < card; ++num)
        {
            ++index;
            assert(card == deck[index]);
        }
 
        ++card;
    }
 
    assert(NUM_NUMBER_CARDS == 1 + index);
 }

 /*!
  * @brief This function test to see if the files are connected properly
  * by way of seeing if we can read the #defines from the card.h file.
  * We also sanity check that the number of each category is indeed
  * equal to the total number of cards
  *
  * @param void
  *
  * @return void
  */
 static inline void
 test_check_totals ()
 {
    const uint8_t numbers   = NUM_NUMBER_CARDS;
    const uint8_t modifiers = NUM_MOD_CARDS;
    const uint8_t actions   = NUM_ACTION_CARDS;
    assert(NUM_CARDS == numbers + modifiers + actions);
 }

 /*!
  * @brief This function test the value of each card type.
  *
  * @param void
  *
  * @return void
  */
  static inline void
  test_card_definition ()
  {
    // An enum begins indexing at 0.
    assert(0  == ZERO);
    assert(1  == ONE);
    assert(2  == TWO);
    assert(3  == THREE);
    assert(4  == FOUR);
    assert(5  == FIVE);
    assert(6  == SIX);
    assert(7  == SEVEN);
    assert(8  == EIGHT);
    assert(9  == NINE);
    assert(10 == TEN);
    assert(11 == ELEVEN);
    assert(12 == TWELVE);

    assert(13 == PLUS_2);
    assert(14 == PLUS_4);
    assert(15 == PLUS_6);
    assert(16 == PLUS_8);
    assert(17 == PLUS_10);
    assert(18 == TIMES_2);
   
    assert(19 == FREEZE);
    assert(20 == FLIP_3);
    assert(21 == SECOND_CHANCE);
 }
 
 /*!
  * @brief Manual tests to ensure the function that determines
  * a cards type is working correctly.
  * 
  * @param void
  *
  * @return void
  */
  static inline void
  test_card_types ()
  {
    assert(NUMBER_CARD == get_card_type(ZERO));
    assert(NUMBER_CARD == get_card_type(ONE));
    assert(NUMBER_CARD == get_card_type(TWO));
    assert(NUMBER_CARD == get_card_type(THREE));
    assert(NUMBER_CARD == get_card_type(FOUR));
    assert(NUMBER_CARD == get_card_type(FIVE));
    assert(NUMBER_CARD == get_card_type(SIX));
    assert(NUMBER_CARD == get_card_type(SEVEN));
    assert(NUMBER_CARD == get_card_type(EIGHT));
    assert(NUMBER_CARD == get_card_type(NINE));
    assert(NUMBER_CARD == get_card_type(TEN));
    assert(NUMBER_CARD == get_card_type(ELEVEN));
    assert(NUMBER_CARD == get_card_type(TWELVE));

    assert(MOD_CARD == get_card_type(PLUS_2));
    assert(MOD_CARD == get_card_type(PLUS_4));
    assert(MOD_CARD == get_card_type(PLUS_6));
    assert(MOD_CARD == get_card_type(PLUS_8));
    assert(MOD_CARD == get_card_type(PLUS_10));
    assert(MOD_CARD == get_card_type(TIMES_2));

    assert(ACTION_CARD == get_card_type(FREEZE));
    assert(ACTION_CARD == get_card_type(FLIP_3));
    assert(ACTION_CARD == get_card_type(SECOND_CHANCE));
 }
 
 /*** end of file ***/