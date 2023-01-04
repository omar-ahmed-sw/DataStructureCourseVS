#pragma once

#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

constexpr uint32_t stacksize = 100U;


class clsStackHandler {

public:

	//default constructor
	clsStackHandler()
	{
		DoInitialise();
	}


	void Push(int16_t Value);
	int16_t Pop(void);
	void DoInitialise(void);
	bool isEmpty(void);
	bool isFull(void);
	int16_t GetSize(void);
	int16_t Peek(uint16_t Index);
	void Change(uint16_t Index, int16_t Value);
	void Display(void);

	int16_t StackArray[stacksize];
	int16_t Top = -1;

protected:

private:


};
