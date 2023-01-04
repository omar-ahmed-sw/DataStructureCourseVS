#include "stdafx.h"
#include "QueueHandler.h"


void clsQueueHandler::DoInitialise(void)
{
	for (uint16_t i = 0U; i < (queuesize - 1U); i++)
	{
		clsQueueHandler::QueueArray[i] = 0;
	}
}


void clsQueueHandler::Enqueue(int16_t Value)
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

int16_t clsQueueHandler::Dequeue(void)
{
	if (!clsQueueHandler::isEmpty())
	{
		int16_t TempValue = clsQueueHandler::QueueArray[0];        //to clear the value after popping it

																 //shift the queue forward one step
		for (uint16_t i = 0U; i <= Last; i++)
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
	if (Last == (queuesize - 1U))
	{
		return true;
	}

	else
	{
		return false;
	}
}


int16_t clsQueueHandler::GetSize(void)
{
	return Last + 1;
}

int16_t clsQueueHandler::Peek(uint16_t Index)
{
	if (Index > (queuesize - 1U))    //greater than the size of the stack
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

void clsQueueHandler::Change(uint16_t Index, int16_t Value)
{
	if (Index < (queuesize - 1U))
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
		for (int16_t i = Last; i >= 0; i--)
		{
			std::cout << "Index " << i << " = " << QueueArray[i] << "\t";
		}
	}

	else
	{
		std::cout << "The queue is empty, nothing to display\n";
	}
}
