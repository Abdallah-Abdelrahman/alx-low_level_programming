#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory,
 * or `NULL`
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr)
		return (0);
	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (_malloc(new_size));
	return (adjust_book((char *)ptr, old_size, new_size));

}

/**
 * adjust_book - adjust the book-keeping
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer
 */
void *adjust_book(char *ptr, unsigned int old_size, unsigned int new_size)
{
	size_t min, max, idx, i;
	char *new_ptr;

	if (new_size < old_size)
	{
		min = new_size;
		max = old_size;
	}
	else
	{
		min = old_size;
		max = new_size;
	}
	new_ptr = malloc(max);
	for (; i < min; i++)
		new_ptr[i] = ptr[i];
	return (new_ptr);


}

/**
 * _malloc - allocates memory using malloc.
 * @b: bytes to allocates
 *
 * Return: a pointer of void
 */
void *_malloc(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
		return (0);
	return (ptr);
}
