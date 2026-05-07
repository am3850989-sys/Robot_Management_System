#include <iostream>
using namespace std;

class Robot {
protected:
	int id;
	string name;
	string status;
	string lastMaintenance;
	string maintenanceSchedule;

public:
	//*********************** Constructor *********************
	Robot(int i, string n, string s = "Working", string mDate = "N/A") {
		id = i;
		name = n;
		status = s;
		lastMaintenance = mDate;
		maintenanceSchedule = "Not set";
	}

	//************************ Getters ************************
	int getID() { return id; }
	string getName() { return name; }
	string getStatus() { return status; }
	string getMaintenance() { return lastMaintenance; }
	string getMaintenanceSchedule() { return maintenanceSchedule; }

	//************************ Setters **************************
	void setStatus(string s) {
		if (s == "Working" || s == "Charging" || s == "In maintenance" || s == "Stopped") {
			status = s;
		}
		else {
			cout << "Error: This status is not recognized!" << endl;
		}
	}

	void setMaintenance(string mDate, string time) {
		lastMaintenance = "Date: " + mDate + " at " + time;
	}

	void setMaintenanceSchedule(string schedule) {
		maintenanceSchedule = schedule;
	}

	//*************************** Display ********************
	void display() {
		cout << "   ****************   " << endl;
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Status: " << status << endl;
		cout << "Last Maintenance : " << lastMaintenance << endl;
		cout << "Maintenance Schedule: " << maintenanceSchedule << endl;
		cout << "   ****************   " << endl;
	}

	//************************** Default task  ************************
	virtual void task() {
		cout << "Robot " << name << " has no specific task assigned." << endl;
	}

	//************************** Update Maintenance **********************
	virtual void updateMaintenance() {
		cout << "No maintenance update available." << endl;
	}
};

//**************************** Cleaning Robot *******************
class CleaningRobot : public Robot {
public:
	CleaningRobot(int i, string n, string s = "Working", string mDate = "N/A")
		: Robot(i, n, s, mDate) {
	}

	void task() override {
		cout << "Task Assigned: Robot " << name << " is vacuuming and mopping floors." << endl;
	}

	void updateMaintenance() override {
		setMaintenanceSchedule("Daily: Clean brushes and empty dust bin.");
		cout << "Maintenance Schedule updated for: " << name << endl;
	}
};

//**************************** Security Robot ********************
class SecurityRobot : public Robot {
public:
	SecurityRobot(int i, string n, string s = "Working", string mDate = "N/A")
		: Robot(i, n, s, mDate) {
	}

	void task() override {
		cout << "Task Assigned: Robot " << name << " is scanning the perimeter for intruders." << endl;
	}

	void updateMaintenance() {
		setMaintenanceSchedule("Weekly: Check camera sensors and night vision.");
		cout << "Maintenance Schedule updated for: " << name << endl;
	}
};

//*************************** Delivery Robot ***********************
class DeliveryRobot : public Robot {
public:
	DeliveryRobot(int i, string n, string s = "Working", string mDate = "N/A")
		: Robot(i, n, s, mDate) {
	}

	void task() override {
		cout << "Task Assigned: Robot " << name << " is navigating to deliver the package." << endl;
	}

	void updateMaintenance() {
		setMaintenanceSchedule("Every 50 miles: Check wheel alignment and battery health.");
		cout << "Maintenance Schedule updated for: " << name << endl;
	}
};
//************************ Main function **************************
int main() {
	Robot* robots[100];
	int count = 0;
	int choice;
	do {
		cout << "==============================================\n";
		cout << "|           Robot Managment System           |\n";
		cout << "==============================================\n";
		cout << "1. Add New Robot\n";
		cout << "2. Display All Robots\n";
		cout << "3. Assign Task\n";
		cout << "4. Set Maintenance Schedule\n";
		cout << "5. Charge & Status Update\n";
		cout << "6. Emergency Shutdown\n";
		cout << "0. Exit\n";
		cout << "===============================================\n";
		cout << "Enter Choice: ";
		cin >> choice;
		//******************** Add *********************
		switch (choice) {
		case 1: {
			int type, id;
			string name;
			cout << "Choose Type: 1-Cleaning 2-Security 3-Delivery: ";
			cin >> type;

			cout << "Enter ID: ";
			cin >> id;

			cout << "Enter Name: ";
			cin >> name;

			if (type == 1)
				robots[count++] = new CleaningRobot(id, name, "Working");
			else if (type == 2)
				robots[count++] = new SecurityRobot(id, name, "Working");
			else
				robots[count++] = new DeliveryRobot(id, name, "Working");
			break;
		}

			  //****************** Display ******************
		case 2:
			for (int i = 0; i < count; i++) {
				robots[i]->display();
				cout << "-------------------------------\n";
			}
			break;

			//****************** Tasks *********************				
		case 3:
			for (int i = 0; i < count; i++) {
				robots[i]->task();
				cout << "-------------------------------\n";
			}
			break;

			//****************** Maintenance **************
		case 4: {
			int id;
			string date;
			string time;

			cout << "Enter ID: ";
			cin >> id;

			cout << "Date: ";
			cin >> date;

			cout << "Time: ";
			cin >> time;

			for (int i = 0; i < count; i++) {
				if (robots[i]->getID() == id) {
					robots[i]->setMaintenance(date, time);
					robots[i]->updateMaintenance();
				}
			}
			cout << "Maintenance Updated!\n";
			break;
		}

			  //***************** Charge *******************
		case 5:
			for (int i = 0; i < count; i++) {
				robots[i]->setStatus("Charging");
			}
			cout << "All Robots Charging!\n";
			break;

			//***************** Shutdown ******************
		case 6:
			for (int i = 0; i < count; i++) {
				robots[i]->setStatus("Stopped");
			}
			cout << "All Robots Stopped!\n";
			break;

		default:
			cout << "Invalid choice! Please enter a number from 0 to 6.\n";

		}
	} while (choice != 0);

	return 0;
}
