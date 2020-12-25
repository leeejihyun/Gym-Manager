#include "Trainer.h"
#include "Member.h"
#include <iostream>
using namespace std;

int main()
{
	int mainNum{};
	int trainerNum{};
	int memberNum{};

	Trainer trainer[2];
	Member member[5];
	string name{};
	int id{};
	int trainerID{};
	int trainerCnt{};
	int memberCnt{};
	string rsvCondition{ "Not yet" };

	// Main Menu(1. trainer	2. member	3. exit)
	while (true)
	{
		cout << "---------GymManager is running---------" << endl;
		cout << "1. trainer\t2. member\t3. exit" << endl;
		cout << "---------------------------------------" << endl;
		cin >> mainNum;

		// Trainer Menu(1. 정보입력	2. 전체 트레이너 정보확인	3. 예약확인	4. exit)
		if (mainNum == 1)
		{
			while (true)
			{
				cout << "-----------------------------Trainer Menu-----------------------------" << endl;
				cout << "1. 정보입력\t2. 전체 트레이너 정보확인\t3. 예약확인\t4. exit" << endl;
				cin >> trainerNum;

				// 1. 정보입력
				if (trainerNum == 1)
				{
					if (trainerCnt < 2)
					{
						cout << "이름: ";
						cin >> name;
						trainer[trainerCnt].setName(name);
						trainer[trainerCnt].setID(100 + trainerCnt);
						trainerCnt += 1;
					}
					else
					{
						cout << "Trainer는 2명까지 입력할 수 있습니다." << endl;
					}
				}
				// 2. 전체 트레이너 정보확인
				else if (trainerNum == 2)
				{
					for (int i = 0; i < trainerCnt; i++)
					{
						cout << trainer[i].getID() << '\t' << trainer[i].getName() << endl;
					}
				}

				// 3. 예약확인
				else if (trainerNum == 3)
				{
					cout << "트레이너 ID: ";
					cin >> trainerID;
					for (int i = 0; i < memberCnt; i++)
					{
						if (member[i].getTrainerID() == trainerID)
						{
							cout << member[i].getID() << '\t' << member[i].getName() << '\t' << member[i].getTrainerID() << '\t' << member[i].getRsvCondition() << endl;
							cout << "y(yes) / n(no)? ";
							cin >> rsvCondition;
							if (rsvCondition == "y")
							{
								member[i].setRsvCondition(rsvCondition);
								cout << member[i].getID() << '\t' << member[i].getName() << '\t' << member[i].getTrainerID() << '\t' << member[i].getRsvCondition() << endl;

							}
							else if (rsvCondition == "n")
							{
								cout << "예약을 승인하지 않았습니다." << endl;
							}
							else
							{
								cout << "y 또는 n만 입력해주세요." << endl;
							}
						}
					}
				}
				// 4. exit
				else if (trainerNum == 4)
				{
					break;
				}
			}
		}

		// Member Menu(1. 정보입력	2. 전체 회원 정보확인	3. 예약	4. exit)
		else if (mainNum == 2)
		{
			while (true)
			{
				cout << "----------------------Member Menu----------------------" << endl;
				cout << "1. 정보입력\t2.전체 회원 정보확인\t3.예약\t4.exit" << endl;
				cin >> memberNum;

				// 1. 정보입력
				if (memberNum == 1)
				{
					if (memberCnt < 5)
					{
						cout << "이름: ";
						cin >> name;
						member[memberCnt].setName(name);
						member[memberCnt].setID(200 + memberCnt);
						memberCnt += 1;
					}
					else
					{
						cout << "Member는 5명까지 입력할 수 있습니다." << endl;
					}
				}
				// 2. 전체 회원 정보확인
				else if (memberNum == 2)
				{
					for (int i = 0; i < memberCnt; i++)
					{
						if (member[i].getTrainerID()) {
							cout << member[i].getID() << '\t' << member[i].getName() << '\t' << member[i].getTrainerID() << '\t' << member[i].getRsvCondition() << endl;
						}
						else
						{
							cout << member[i].getID() << '\t' << member[i].getName() << '\t' << member[i].getTrainerID() << '\t' << "Not yet" << endl;
						}
					}
				}

				// 3. 예약
				else if (memberNum == 3)
				{
					cout << "회원 ID: ";
					cin >> id;
					cout << "[예약 가능한 트레이너]" << endl;
					for (int i = 0; i < trainerCnt; i++)
					{
						cout << trainer[i].getID() << '\t' << trainer[i].getName() << endl;
					}
					cout << "예약하고 싶은 트레이너 ID: ";
					cin >> trainerID;
					member[id - 200].setTrainerID(trainerID);
				}
				// 4. exit
				else if (memberNum == 4)
				{
					break;
				}
			}
		}
		// Exit
		else if (mainNum == 3)
		{
			break;
		}
		// Exception
		else {
			cout << "1, 2, 3 중에 입력해주세요." << endl;
		}
	}

	return 0;
}