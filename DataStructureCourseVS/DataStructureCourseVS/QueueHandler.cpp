#include "stdafx.h"
#include "QueueHandler.h"


void clsQueueHandler::DoInitialise(void)
{
	for (uint16 i = 0U; i < 100U; i++)
	{
		clsQueueHandler::QueueArray[i] = 0;
	}
}


void clsQueueHandler::Enqueue(int16 Value)
{
	if (!clsQueueHandler::isFull())
	{
		clsQueueHandler::Last++;
		clsQueueHandler::QueueArray[Last] = Value;
	}

	else
	{
		std::cout << "The Queue is full, Can't Enqueue anymore\n";
	}
}

int16 clsQueueHandler::Dequeue(void)
{
	if (!clsQueueHandler::isEmpty())
	{
		int16 TempValue = clsQueueHandler::QueueArray[0];        //to clear the value after popping it

																 //shift the queue forward one step
		for (uint16 i = 0U; i <= Last; i++)
		{
			clsQueueHandler::QueueArray[i] = clsQueueHandler::QueueArray[i + 1];
		}
		Last--;

		return 	TempValue;
	}

	else
	{
		std::cout << "\nThe queue is empty\n";
		return 0;
	}
}


bool clsQueueHandler::isEmpty()
{
	if (Last < 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool clsQueueHandler::isFull()
{
	if (Last == 99)
	{
		return true;
	}

	else
	{
		return false;
	}
}


int16 clsQueueHandler::GetSize(void)
{
	return Last + 1;
}

int16 clsQueueHandler::Peek(uint16 Index)
{

	if (Index > 99)    //greater than the size of the stack
	{
		std::cout << "\nThe index is outside the queue\n";
		return std::nan("NAN");
	}

	else if (isEmpty())
	{
		std::cout << "\nThe queue is empty\n";
		return QueueArray[Index];   //will return 0 as this index is empty and initialised
	}

	else
	{
		return QueueArray[Index];
	}
}

void clsQueueHandler::Change(uint16 Index, int16 Value)
{
	if (Index < 99U)
	{
		QueueArray[Index] = Value;
	}

	else
	{
		std::cout << "\nThe index is outside the queue\n";
	}
}

void clsQueueHandler::Display(void)
{
	if (!clsQueueHandler::isEmpty())
	{
		for (int16 i = Last; i >= 0; i--)
		{
			std::cout << "Index " << i << " = " << QueueArray[i] << "\t";
		}
	}

	else
	{
		std::cout << "The queue is empty, nothing to display\n";
	}
}
