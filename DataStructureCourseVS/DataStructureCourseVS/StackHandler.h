#pragma once

#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>


using namespace std;


class clsStackHandler {

public:

	//default constructor
	clsStackHandler()
	{
		DoInitialise();
	}


	void Push(int16 Value);
	int16 Pop(void);
	void DoInitialise(void);
	bool isEmpty(void);
	bool isFull(void);
	int16 GetSize(void);
	int16 Peek(uint16 Index);
	void Change(uint16 Index, int16 Value);
	void Display(void);

	int16 StackArray[100];
	int16 Top = -1;

protected:

private:


};
