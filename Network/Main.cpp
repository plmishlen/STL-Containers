#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<direct.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define WAL //Wake On LAN

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef WAL
	string source_file_name;
	string destination_file_name;
	string ext = ".txt";

	cout << "¬ведите им€ исходного файла: "; getline(cin, source_file_name);
	cout << "¬ведите им€ конечного файла: "; getline(cin, destination_file_name);

	if (source_file_name.find(ext) == string::npos)	source_file_name += ext;
	if (destination_file_name.find(ext) == string::npos) destination_file_name += ext;

	//ofstream fout("201 ready.txt");
	//ifstream fin("201 RAW.txt");

	string IP;
	string MAC;

	//ofstream fout(destination_file_name);
	ifstream fin(source_file_name);
	if (fin.is_open())
	{
		ofstream fout(destination_file_name);
		//while (!fin.eof())
		while (fin >> IP >> MAC)
		{
			cout << MAC << tab << IP << endl;
			fout << MAC << tab << IP << endl;
		}
		fout.close();
		string cmd = "notepad" + destination_file_name;
		system(cmd.c_str());
	}
	else
	{
		cerr << "\nFile not found" << endl;
	}

	fin.close();
#endif // WAL

	string room_number;
	cout << "¬ведите номер аудитории: "; cin >> room_number;

	string directory = "Files";
	_chdir(directory.c_str());

	string source_file_name = room_number + "RAW.txt";
	string dhcpd_file_name = room_number + ".dhcpd";
	string wal_file_name = room_number + ".wal";
	string mac, ip;

	ifstream fin(source_file_name);
	if (fin.is_open())
	{
		ofstream dhcpd_fout(dhcpd_file_name);
		ofstream wal_fout(wal_file_name);
		for (int i = 1; fin >> ip >> mac; i++)
		{
			fin >> ip >> mac;
			wal_fout << mac << tab << ip << endl;
			std::replace(mac.begin(), mac.end(),'-', ':');
			cout << "host 201-" << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << mac << ";\n";
			cout << "\tfixed-address\t\t" << ip << ";\n";
			cout << "}\n";
			cout << endl;

			dhcpd_fout << "host 201-" << i << endl;
			dhcpd_fout << "{\n";
			dhcpd_fout << "\thardware ethernet\t" << mac << ";\n";
			dhcpd_fout << "\tfixed-address\t\t" << ip << ";\n";
			dhcpd_fout << "}\n";
			dhcpd_fout << endl;
		}
		//string cmd = "notepad " + destination_file_name;
		string cmd = "start notepad ";
		system((cmd + wal_file_name).c_str());
		system((cmd + dhcpd_file_name).c_str());
	}
	else
	{
		cout << "File not found!" << endl;
	}
	fin.close();
}

