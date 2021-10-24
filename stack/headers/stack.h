/*
 * Auteur: BICZO Samuel
 * Date : 23/10/2021 
 *
 *
 * Description: Implémentation de la structure de donnée de piles
 * 		Le premier élement ajouter a la structure sera le dernier a être supprimer.
 * */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


// Description de la structure de donné
struct stack
{
	void* data; // La donnée 
	struct stack* node; // Pointeur sur le prochain élément de la structure 
};

// Prototype 
struct stack* init_stack(void); // Initialize une pile vide
struct stack* free_stack(struct stack* p_stack); // Libére chaque 'node' en mémoire 

struct stack* push_stack(struct stack* p_stack, void* data); // Ajoute un nouveau élément a la pile 
struct stack* pop_stack(struct stack* p_stack); // Supprime un élément de la pile

#endif
