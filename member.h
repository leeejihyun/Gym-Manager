#include <iostream>
using namespace std;

class Member
{
private:
	int id;
	string name;
	int trainerID;
	string rsvCondition;
public:
	Member() : id{}, name{}, trainerID{}, rsvCondition{ "Not yet" }{}
	void setID(int _id);
	int getID() { return id; }
	void setName(string _name);
	string getName() { return name; }
	void setTrainerID(int _trainerID);
	int getTrainerID() { return trainerID; }
	void setRsvCondition(string _rsvCondition);
	string getRsvCondition() { return rsvCondition; }
};
