#include "Member.h"

void Member::setID(int _id)
{
	id = _id;

}

void Member::setName(string _name)
{
	name = _name;
}

void Member::setTrainerID(int _trainerID)
{
	trainerID = _trainerID;
}

void Member::setRsvCondition(string _rsvCondition)
{
	if (_rsvCondition == "y")
	{
		rsvCondition = "OK!";
	}
}