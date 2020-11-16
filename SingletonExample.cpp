#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#pragma warning(disable:4996)

using namespace std;

class DataStore {

private:
	static DataStore* instance;
	string data;


	DataStore() {
		data = "";
	}

public:
	static DataStore* getInstance() {
		if (!instance) {
			instance = new DataStore;
		}
		return instance;
	}

	string getData() {
		return data;
	}

	void setData(string newData) {
		data = newData;
	}
};


DataStore* DataStore::instance = nullptr;

int main() {

	string userEntry = "";

	DataStore* dsObject = dsObject->getInstance();
	dsObject->setData(userEntry);

	ofstream textFileWrite;
	textFileWrite.open("cppLog.txt", ios_base::app); //opens the file in append mode

	cout << "Use this program to modify the singleton." << endl << endl;
	cout << "Enter in data. Submit with Enter key. Quit with 0 key. " << endl;



	while (true)
	{
		getline(cin, userEntry);


		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);


		if (userEntry != "0")
		{
			dsObject->setData(userEntry);
			textFileWrite << asctime(timeinfo) << ", " << dsObject->getData() << endl;
		}
		else
		{
			break;
		}
	}

	string f = "";
	ifstream textFileRead("cppLog.txt");

	cout << "New contents written to the file:" << endl << endl;

	while (getline(textFileRead, f))
	{
		cout << f << endl;
	}

	textFileWrite.close();
	textFileRead.close();
	return 0;
}