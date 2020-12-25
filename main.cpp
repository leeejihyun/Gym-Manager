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

		// Trainer Menu(1. �����Է�	2. ��ü Ʈ���̳� ����Ȯ��	3. ����Ȯ��	4. exit)
		if (mainNum == 1)
		{
			while (true)
			{
				cout << "-----------------------------Trainer Menu-----------------------------" << endl;
				cout << "1. �����Է�\t2. ��ü Ʈ���̳� ����Ȯ��\t3. ����Ȯ��\t4. exit" << endl;
				cin >> trainerNum;

				// 1. �����Է�
				if (trainerNum == 1)
				{
					if (trainerCnt < 2)
					{
						cout << "�̸�: ";
						cin >> name;
						trainer[trainerCnt].setName(name);
						trainer[trainerCnt].setID(100 + trainerCnt);
						trainerCnt += 1;
					}
					else
					{
						cout << "Trainer�� 2����� �Է��� �� �ֽ��ϴ�." << endl;
					}
				}
				// 2. ��ü Ʈ���̳� ����Ȯ��
				else if (trainerNum == 2)
				{
					for (int i = 0; i < trainerCnt; i++)
					{
						cout << trainer[i].getID() << '\t' << trainer[i].getName() << endl;
					}
				}

				// 3. ����Ȯ��
				else if (trainerNum == 3)
				{
					cout << "Ʈ���̳� ID: ";
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
								cout << "������ �������� �ʾҽ��ϴ�." << endl;
							}
							else
							{
								cout << "y �Ǵ� n�� �Է����ּ���." << endl;
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

		// Member Menu(1. �����Է�	2. ��ü ȸ�� ����Ȯ��	3. ����	4. exit)
		else if (mainNum == 2)
		{
			while (true)
			{
				cout << "----------------------Member Menu----------------------" << endl;
				cout << "1. �����Է�\t2.��ü ȸ�� ����Ȯ��\t3.����\t4.exit" << endl;
				cin >> memberNum;

				// 1. �����Է�
				if (memberNum == 1)
				{
					if (memberCnt < 5)
					{
						cout << "�̸�: ";
						cin >> name;
						member[memberCnt].setName(name);
						member[memberCnt].setID(200 + memberCnt);
						memberCnt += 1;
					}
					else
					{
						cout << "Member�� 5����� �Է��� �� �ֽ��ϴ�." << endl;
					}
				}
				// 2. ��ü ȸ�� ����Ȯ��
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

				// 3. ����
				else if (memberNum == 3)
				{
					cout << "ȸ�� ID: ";
					cin >> id;
					cout << "[���� ������ Ʈ���̳�]" << endl;
					for (int i = 0; i < trainerCnt; i++)
					{
						cout << trainer[i].getID() << '\t' << trainer[i].getName() << endl;
					}
					cout << "�����ϰ� ���� Ʈ���̳� ID: ";
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
			cout << "1, 2, 3 �߿� �Է����ּ���." << endl;
		}
	}

	return 0;
}