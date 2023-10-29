#include "deck.h"

/**
* value_deck_card - get the value of card in deck cards
* @deck: deck card
* Return: void
*/
char value_deck_card(deck_node_t *deck)
{
	const char *val_card;
	int size_arr, i;
	/* Mapping for card values*/
	card_map_val_t val_cards[] = {
	{"Ace", 0},
	{"1", 1},
	{"2", 2},
	{"3", 3},
	{"4", 4},
	{"5", 5},
	{"6", 6},
	{"7", 7},
	{"8", 8},
	{"9", 9},
	{"10", 10},
	{"Jack", 11},
	{"Queen", 12},
	{"King", 13}
	};

	val_card  = deck->card->value;
	size_arr  = sizeof(val_cards) / sizeof(val_cards[0]);
	for (i = 0; i < size_arr; i++)
	{
		if (strcmp(val_card, val_cards[i].code) == 0)
		{
			return (val_cards[i].value);
		}
	}

	/*default*/
	return (13);
}
/**
* cmp_deck_cards - compare two deck cards
*@a: deck card1
*@b: deck card2
*Return: void
*/
int cmp_deck_cards(const void *a, const void *b)
{
	deck_node_t *decka, *deckb;
	int value_a, value_b;

	decka = *(deck_node_t **)a;
	deckb = *(deck_node_t **)b;

	/*compare kind of decks*/
	if (decka->card->kind != deckb->card->kind)
	{
		return (decka->card->kind - deckb->card->kind);
	}

	/*same decks kinds compare values*/
	value_a = value_deck_card(decka);
	value_b = value_deck_card(deckb);

	return (value_a - value_b);
}

/**
* sort_deck -  sorts a deck of cards
* @deck: list of deck cards
* Return: void
*/
void sort_deck(deck_node_t **deck)
{
	int deck_size = 52;
	deck_node_t **deckArray;
	deck_node_t *node_cur;
	int i;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	deckArray = malloc(deck_size * sizeof(deck_node_t *));

	node_cur = *deck;

	/* list to array */
	for (i = 0; i < deck_size; i++)
	{
		deckArray[i] = node_cur;
		node_cur = node_cur->next;
	}

	/*qsort to sort the array of cards*/
	qsort(deckArray, deck_size, sizeof(deck_node_t *), cmp_deck_cards);

	/* array to list*/
	for (i = 0; i < deck_size - 1; i++)
	{
		deckArray[i]->next = deckArray[i + 1];
		deckArray[i + 1]->prev = deckArray[i];
	}
	deckArray[0]->prev = NULL;
	deckArray[deck_size - 1]->next = NULL;
	*deck = deckArray[0];
	free(deckArray);
}

