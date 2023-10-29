#ifndef DECK_H
#define DECK_H
#include <stdlib.h>
#include <string.h>

/**
 * enum kind_e - enumeration values of symbols in deck cards
 * @SPADE: symbol
 * @HEART: symbol
 * @CLUB: symbol
 * @DIAMOND: symbol
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - info  card
 * @value: pointer to char value of card
 * @kind: pointer to kind enum type
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - list cards
 * @card: pointer to card
 * @prev: previous pointer to current card
 * @next: next pointer to current card
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct card_map_val_s - dictionary code/numeric_value card
 * @code: string value
 * @value: numeric value
 */
typedef struct card_map_val_s
{
	const char *code;
	char value;
} card_map_val_t;

void sort_deck(deck_node_t **deck);
#endif
