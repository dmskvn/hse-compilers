#pragma once

class Basic {
public:
	void newProgram();	
	static Basic *instance();
	
private:
	static Basic *b;									// singleton instance
};
