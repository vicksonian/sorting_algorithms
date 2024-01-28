#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
/**
* compare_cards - Comparison function to be used with qsort.
* @a: Pointer to the first card.
* @b: Pointer to the second card.
*
* Return: Positive value if a is greater, negative if b is greater, 0 if equal.
*/
int compare_cards(const void *a, const void *b)
{
const card_t *card_a = *(const card_t **)a;
const card_t *card_b = *(const card_t **)b;
if (card_a->kind != card_b->kind)
return (card_a->kind - card_b->kind);
return (get_value_index(card_a->value) - get_value_index(card_b->value));
}
/**
* get_value_index - Get the index of the card value in a sorted deck.
* @value: The value of the card.
*
* Return: The index of the card value.
*/
int get_value_index(const char *value)
{
const char *sorted_values[] = {"Ace", "2", "3", "4", "5", "6", "7",
"8", "9", "10", "Jack", "Queen", "King"};
for (int i = 0; i < 13; i++)
{
if (strcmp(value, sorted_values[i]) == 0)
return i;
}
return -1; // Shouldn't happen if input is valid.
}
/**
* sort_deck - Sorts a deck of cards.
* @deck: Pointer to the head of the deck.
*/
void sort_deck(deck_node_t **deck)
{
size_t count = 0;
deck_node_t *current = *deck;
card_t **cards;
if (deck == NULL || *deck == NULL)
return;
while (current != NULL)
{
count++;
current = current->next;
}
cards = malloc(count * sizeof(card_t *));
if (cards == NULL)
exit(EXIT_FAILURE);
current = *deck;
for (size_t i = 0; i < count; i++)
{
cards[i] = (card_t *)current->card;
current = current->next;
}
qsort(cards, count, sizeof(card_t *), compare_cards);
current = *deck;
for (size_t i = 0; i < count; i++)
{
current->card = cards[i];
current = current->next;
}
free(cards);
}
