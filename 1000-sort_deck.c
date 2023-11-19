#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2

 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value
 * @card: A pointer to a deck_node_t card
 * Return: The numerical value of the card

 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds
 * @deck: A pointer to the head of a deck_node_t doubly-linked list

 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *itr, *enter, *tmp;

	for (itr = (*deck)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		enter = itr->prev;
		while (enter != NULL && enter->card->kind > itr->card->kind)
		{
			enter->next = itr->next;
			if (itr->next != NULL)
				itr->next->prev = enter;
			itr->prev = enter->prev;
			itr->next = enter;
			if (enter->prev != NULL)
				enter->prev->next = itr;
			else
				*deck = itr;
			enter->prev = itr;
			enter = itr->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from spades
 * @deck: A pointer to the head of list

 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itr, *enter, *tmp;

	for (itr = (*deck)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		enter = itr->prev;
		while (enter != NULL &&
		       enter->card->kind == itr->card->kind &&
		       get_value(enter) > get_value(itr))
		{
			enter->next = itr->next;
			if (itr->next != NULL)
				itr->next->prev = enter;
			itr->prev = enter->prev;
			itr->next = enter;
			if (enter->prev != NULL)
				enter->prev->next = itr;
			else
				*deck = itr;
			enter->prev = itr;
			enter = itr->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 * @deck: A pointer to the head of a deck_node_t doubly-linked list
 
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}

