#include <iostream>
using namespace std;

class Trainer
{
private:
	int id;
	string name;
public:
	Trainer():id{}, name{}{}
	void setID(int _id);
	int getID() { return id; }
	void setName(string _name);
	string getName() { return name; }
};
