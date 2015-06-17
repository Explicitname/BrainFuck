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






#endif /* INTERP_H_ */
