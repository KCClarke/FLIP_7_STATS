This program is based on, and uses the rules and ideas from the game
FLIP 7, A 2025 game by Eric Olsen.

The purpose of this program is to determine optimal play of the game FLIP 7

Definitions & Abreviations
    Throughout this project I will use...

    mod or MOD:
    As an abreviation for modifier. The category of modifier cards
    will be refered to as mod_cards or MOD_CARDS. Any use of mod/MOD
    wil not refer to modulo the % operator in C. Any use of % or modulo
    will be spelled in full as needed.

    stats:
    An abreviation for statistics.

    ratio:
    The raw result of floating point division
    for example: 1 / 94 = 0.010638298
    
    percent:
    The result of rounding and scaling a ratio for readability.
    One decimal place will be sufficient for this project.
    For example: 1 out of 94 = 1.1%

    scale:
    A power of 10 number I will use to multiply the ratio by
    so we may avoid floating point comparison in our logic.
    We will be scaling our ratio by 10^4 = 10,000
    for example: 
    if ratio == 0.0106... then ratio_scaled = 106

    unique:
    There are 22 unique types of cards, 13 number cards, 6 mod cards and 
    3 action cards.
