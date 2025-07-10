/** @file test_player.c
 *
 * @brief A source file for testing player related functions.
 *
 * @par
 * Kasey Clarke June 6 2025
 */

//include statements
#include "test_player.h"
#include <assert.h>

// private function prototypes

// public function bodies
/*!
 * @brief tests player initialization
 *
 * @param[in] void
 *
 * @return void
 */
void
test_player ()
{
    player_t player;
    init_player(&player, 0);
    assert(0 == player.stopping_point);
    
    init_player(&player, 5);
    assert(5 == player.stopping_point);
    assert(0 == player.num_cards);
    assert(false == player.b_busted);
    assert(false == player.b_stayed);

    hit_player(&player, ONE);
    assert(1 == player.num_cards);
    assert(ONE == player.line[0]);

    hit_player(&player, SIX);
    assert(2 == player.num_cards);
    assert(SIX == player.line[1]);

    uint8_t quantities[UNIQUE_CARDS];

    fill_quantities(quantities, player.line, player.num_cards);
    assert(1 == quantities[ONE]);
    assert(1 == quantities[SIX]);
    assert(false == b_player_busted(&player));

    init_player(&player, 0);
    fill_quantities(quantities, player.line, player.num_cards);
    assert(0 == quantities[ONE]);
    assert(0 == quantities[SIX]);
    assert(false == b_player_busted(&player));

    hit_player(&player, TWELVE);
    hit_player(&player, TWELVE);
    assert(true == b_player_busted(&player));

    init_player(&player, 0);
    hit_player(&player, FREEZE);
    hit_player(&player, FREEZE);
    hit_player(&player, FREEZE);
    fill_quantities(quantities, player.line, player.num_cards);
    assert(3 == quantities[FREEZE]);
    assert(false == b_player_busted(&player));

    init_player(&player, 0);
    hit_player(&player, ONE);
    hit_player(&player, TWO);
    hit_player(&player, THREE);
    hit_player(&player, FOUR);
    hit_player(&player, FIVE);
    hit_player(&player, SIX);
    hit_player(&player, SEVEN);

    init_player(&player, 14);
    assert(false == player.b_stayed);
    hit_player(&player, SEVEN);
    hit_player(&player, EIGHT);
    b_player_stays(&player);
    assert(true == player.b_stayed);

    
}

 
// private function bodies

/*** end of file ***/