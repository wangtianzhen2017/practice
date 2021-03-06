// practice-c.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myVector.h"
#include "malloc.h"



void initMyVector(my_vector *vector) 
{
	vector->size = 0;
	vector->capacity = MY_VECTOR_DEF_SIZE;
	vector->data = (int*)malloc(sizeof(int)*vector->capacity);
}

int size(my_vector *vector) 
{
	return vector->size;
}

int capacity(my_vector *vector)
{
	return vector->capacity;
}

int is_empty(my_vector *vector)
{
	return vector->size == 0 ? 1 : 0;
}

void push(my_vector *vector, int value)
{
	if (vector->size == vector->capacity)
	{
		resize(vector);
	}
	vector->data[vector->size++] = value;
}

int pop(my_vector *vector)
{
	if (vector->size == 0)
	{
		printf("the vector is empty\n");
		return ERROR;
	}
	return vector->data[vector->size--];
}

int getValue(my_vector *vector, int index)
{
	if (index < 0 || index >= vector->size)
	{
		printf("index out of bounds!\n");
		return ERROR;
	}
	return vector->data[index];
}

int getIndex(my_vector *vector, int value)
{
	for (int i = 0; i < vector->size; i++)
	{
		if (vector->data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void insertValue(my_vector *vector, int index, int value)
{
	if (index<0 || index>vector->size)
	{
		printf("illegal index\n");
		return ;
	}
	if (vector->size == vector->capacity)
	{
		resize(vector);
	}
	for (int i = vector->size; i > index; i--)
	{
		vector->data[i] = vector->data[i - 1];
	}
	vector->data[index] = value;
	vector->size ++;
	return ;
}

void deleteValue(my_vector *vector, int index)
{
	if (index < 0 || index >= vector->size)
	{
		printf("illegal index\n");
		return;
	}
	for (int i = index; i < vector->size - 1; i++)
	{
		vector->data[i] = vector->data[i + 1];
	}
	vector->size--;
	return;
}

void resize(my_vector *vector)
{
	int *newdata = (int*)malloc(sizeof(int)*vector->capacity * 2);
	for (int i = 0; i < vector->size; i++)
	{
		newdata[i] = vector->data[i];
	}
	freeMyVector(vector);
	vector->data = newdata;
	newdata = NULL;	
	vector->capacity *= 2;
	return;
}

void freeMyVector(my_vector * vector)
{
	free(vector->data);
}

void traversalMyVector(my_vector *vector)
{
	for (int i = 0; i < vector->size; i++)
	{
		printf("%d\n", vector->data[i]);
	}
}

int main()
{
	my_vector v;
	my_vector *vector = &v;
	initMyVector(vector);

	push(vector, 12);
	push(vector, 3);
	//traversalMyVector(vector);
	insertValue(vector, 2, 2);
	push(vector, 7);
	push(vector, 10);
	deleteValue(vector, 3);
	
	insertValue(vector, 2, 17);
	push(vector, 15);
	printf("size of vector:%d\n", vector->size);
	printf("capacity of vector:%d\n", vector->capacity);
	printf("%d\n", getIndex(vector, 5));
	printf("%d\n", getValue(vector, 5));
	pop(vector);
	traversalMyVector(vector);
	printf("size of vector:%d\n", vector->size);
	printf("is empty?%d\n", is_empty(vector));

    return 0;

}

