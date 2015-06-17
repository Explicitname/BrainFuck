#include "interp.h"
#include <string>
#include <iostream>
using std::cout;

BrainF::BrainF(const std::string &init_program)
{
	tape.push_back(0);
	rwHeadIndex = 0;
	program = init_program;
	programCount = 0;
	std::cout << "Creating BrainF Instance" << std::endl;

}

void BrainF::processInstruct()
{
	std::cout << "Made it inside processInstruct" << std::endl;

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
	std::cout << "Made it inside runProgram" << std::endl;
	while(programCount < program.size())
	{

		processInstruct();
		programCount++;
	}


	return;
}

void BrainF::increment_rwHeadIndex()
{
	std::cout << "Made it inside increment" << std::endl;
	rwHeadIndex++;
	if (rwHeadIndex >= tape.size())
	{
		tape.push_back(0);
	}


}

void BrainF::decrement_rwHeadIndex()
{
	std::cout << "Made it inside decrement" << std::endl;
	rwHeadIndex--;
		if (rwHeadIndex < 0)
		{
			throw std::string("Negative Tape Index");
		}

}

int BrainF::matchBracket(int index)
{
	std::cout << "Made it inside matchBracket" << std::endl;
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
	return index;
}

int main()
{
	BrainF test(",.");
	test.runProgram();




	return 0;

}
