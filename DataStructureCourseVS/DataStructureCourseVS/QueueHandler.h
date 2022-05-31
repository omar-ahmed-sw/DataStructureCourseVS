#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>


using namespace std;





class clsQueueHandler {

public:

	//default constructor
	clsQueueHandler()
	{
		DoInitialise();
	}


	void Enqueue(int16 Value);
	int16 Dequeue(void);
	void DoInitialise(void);
	bool isEmpty(void);
	bool isFull(void);
	int16 GetSize(void);
	int16 Peek(uint16 Index);
	void Change(uint16 Index, int16 Value);
	void Display(void);

	int16 QueueArray[100];
	int16 Last = -1;
	int16 Fisrt = 0;

protected:

private:


};

