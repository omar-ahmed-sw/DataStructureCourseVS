#include "stdafx.h"
#include "StackHandler.h"


void clsStackHandler::DoInitialise(void)
{
	for (uint16_t i = 0U; i < stacksize; i++)
	{
		clsStackHandler::StackArray[i] = 0;
	}
}


void clsStackHandler::Push(int16_t Value)
{
	if (!clsStackHandler::isFull())
	{
		clsStackHandler::Top++;
		clsStackHandler::StackArray[Top] = Value;
	}

	else
	{
		std::cout << "The Stack is full, Can't push anymore\n";
	}
}

int16_t clsStackHandler::Pop(void)
{
	if (!clsStackHandler::isEmpty())
	{
		int16_t TempValue = clsStackHandler::StackArray[Top];        //to clear the value after poping it
		clsStackHandler::StackArray[Top] = 0;
		Top--;
		return 	TempValue;
	}

	else
	{
		std::cout << "\nThe stack is empty\n";
		return 0;
	}
}


bool clsStackHandler::isEmpty()
{
	if (Top < 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool clsStackHandler::isFull()
{
	if (Top == (stacksize - 1U))
	{
		return true;
	}

	else
	{
		return false;
	}
}


int16_t clsStackHandler::GetSize(void)
{
	return Top + 1;
}


//get a certain element by its index
int16_t clsStackHandler::Peek(uint16_t Index)
{
	if (Index > (stacksize - 1U))    //greater than the size of the stack
	{
		std::cout << "\nThe index is outside the stack\n";
		return std::nan("NAN");
	}

	else if (isEmpty())
	{
		std::cout << "\nThe stack is empty\n";
		return StackArray[Index];
	}

	else
	{
		return StackArray[Index];
	}
}

void clsStackHandler::Change(uint16_t Index, int16_t Value)
{
	if (Index < (stacksize - 1U))
	{
		StackArray[Index] = Value;
	}

	else
	{
		std::cout << "\nThe index is outside the stack\n";
	}
}

void clsStackHandler::Display(void)
{
	if (!clsStackHandler::isEmpty())
	{
		for (int16_t i = Top; i >= 0; i--)
		{
			std::cout << "Index " << i << " = " << StackArray[i] << "\n";
		}
	}

	else
	{
		std::cout << "The stack is empty, nothing to display\n";
	}
}