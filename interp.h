/*
 * interp.h
 *
 *  Created on: Jun 10, 2015
 *      Author: explicitness
 */

#ifndef INTERP_H_
#define INTERP_H_

#include <string>
#include <vector>

class BrainF {

	public:
		BrainF(const std::string &init_program);
		void runProgram();

	private:
		void processInstruct();
		int matchBracket(int index);
		std::vector<int> tape;
		int rwHeadIndex = 0;
		std::string program;
		int programCount = 0;
		void increment_rwHeadIndex();
		void decrement_rwHeadIndex();

};

BrainF::BrainF(const std::string &init_program)
{
	tape.push_back(0);
	rwHeadIndex = 0;
	program = "";
	programCount = 0;

}

void BrainF::processInstruct()
{

	char instruction = program[programCount];
	switch(instruction)
	{
		case '+':
			tape[rwHeadIndex]++;
			break;

		case '-':
			tape[rwHeadIndex] = tape[rwHeadIndex] - 1;
			break;

		case '.':
			std::cout << "Number at index " << rwHeadIndex << ' ' << tape[rwHeadIndex] << std::endl;
			break;

		case ',':
			std::cin >> tape[rwHeadIndex];
			break;

		case '>':
			increment_rwHeadIndex();
			break;

		case '<':
			decrement_rwHeadIndex();
			break;

		default:
			throw std::string("Invalid Operation!");
	}
	programCount++;
	return;
}

void BrainF::runProgram()
{
	while(programCount < program.size())
	{

	}

	processInstruct();
	return;
}

void BrainF::increment_rwHeadIndex()
{
	rwHeadIndex++;
	if (rwHeadIndex >= tape.size())
	{
		//Do thangz!
	}


}

void BrainF::decrement_rwHeadIndex()
{
	rwHeadIndex--;
		if (rwHeadIndex < 0)
		{
			throw std::string("Negative Tape Index");
		}

}

int BrainF::matchBracket(int index)
{
	/*if (program[index] != '[')
		throw std::string("Not an open bracket");
	//int balance = 0;
	return 0;*/

	char instruction = program[index];
	bool forward;
	int balance;
	switch (instruction)
	{
	case '[':
		forward = true;
		balance = -1;
		break;

	case ']':
		forward = false;
		balance = 1;
		break;
	default:
		throw std::string("Not a loop instruction!");
	}
	while (balance != 0)
	{
		if (forward) {index++;}
		else {index--;}
		if (program[index] == '[') {balance--;}
		if (program[index] == ']') {balance++;}
	}
	return 0;
}




#endif /* INTERP_H_ */
