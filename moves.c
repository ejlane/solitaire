void draw_three(deck *draw, deck *reference)
{
	
}

void reverse(deck *target)
{
	if (target->first = NULL)
		return target;

	deck *dummy = null_deck;
	card *current = NULL;
	for (current = target->first; current != NULL; current = current->next)
	{
		add_top(dummy, current);
	}

	target->first = dummy->first;
	return;
}

// returns null if index is out of bounds
card *get_by_index(deck *target, int index)
{
	int i = 0;
	card *current = NULL;
	for (current = target->first; current != NULL; current = current->next)
	{
		if (index == i)
			return current;
		i++;
	}

	return NULL;
}

// obviously, addition should not be null
// this only supports adding a single card
void add_top(deck *target, card *addition)
{
	card *dummy = target->first;
	target->first = addition;
	addition->next = dummy;
	return;
}

// this only supports adding a single card
void add_bottom(deck *target, card *addition)
{
	if (target->first == NULL)
	{
		target->first = addition;
		return;
	}

	card *current = NULL;
	for (current = deck->first; current->next != NULL; current = current->next);

	current->next = addition;
	return;
}

// add deck addition to the top of deck target
// the deck being added will lose its deck struct (memory will be freed) and any
// metadata held in it
void add_deck_top(deck *target, deck *addition)
{
	if (addition->first == NULL) {
		free(addition);
		return;
	}

	if (target->first == NULL) {
		target->first = addition->first;
		free(addition);
		return;
	}

	card *dummy = target->first;
	target->first = addition->first;
	free(addition);
	
	card *current = NULL;
	for (current = target->first; current->next != NULL; current = current->next);
	current->next = dummy;
	return;
}

// add deck addition to the bottom of deck target
// the deck being added will lose its deck struct (memory will be freed) and any
// metadata held in it
void add_deck_bottom(deck *target, deck *addition)
{
}
