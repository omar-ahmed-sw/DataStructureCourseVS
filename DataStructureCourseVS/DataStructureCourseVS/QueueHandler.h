#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;



constexpr uint32_t queuesize = 100U;

class clsQueueHandler {

public:

	//default constructor
	clsQueueHandler()
	{
		DoInitialise();
	}


	void Enqueue(int16_t Value);
	int16_t Dequeue(void);
	void DoInitialise(void);
	bool isEmpty(void);
	bool isFull(void);
	int16_t GetSize(void);
	int16_t Peek(uint16_t Index);
	void Change(uint16_t Index, int16_t Value);
	void Display(void);

	int16_t QueueArray[queuesize];
	int16_t Last = -1;
	int16_t Fisrt = 0;

protected:

private:


};

