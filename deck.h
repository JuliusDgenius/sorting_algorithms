#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - kinds of cards
 * @SPADE: spade
 * @HEART: heart
 * @CLUB: club
 * @DIAMOND: diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace of the king"
 * @kinf: kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the end card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the node of the list
 */
typedef struct deck_node_s
{
	const coard_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int card_value(deck_node_t *node);
int _strcmp(const char *s1, const char *s2);
size_t list_len_deck(deck_node_t *list);

#endif /* DECK_H */
