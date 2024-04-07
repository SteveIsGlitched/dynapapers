#include <json.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include <string>
using namespace std;
using json = nlohmann::json;

int getTime() {
	const time_t now = time(nullptr);
  const tm calendar_time = *localtime(addressof(now)) ;
        
  int val = calendar_time.tm_hour;
	return val;
}

void update(string filepath, string exec, string fileExt, bool silentval, int updInter) {
	while (true) {
		int hour = getTime();
		
		if (silentval == false) {
			cout << "Updating wallpapers..." << '\n';
		}
		//ifstream file("/home/$USER/.config/dynapapers/config.json");

		string hourString = to_string(hour);
		string fileName = hourString + fileExt;
		string path = filepath + fileName;

		system((exec + path).c_str());

		sleep(updInter);
	}
}

int main() {
	string version = "v0.0.1";
	cout << "Running dynapapers " << version << " (C++ rewrite)." << '\n';

	char* env = getenv("USER");
	string user = env;

	string fileName{"/home/" + user + "/.config/dynapapers/config.json"};
	ifstream file(fileName);

	if (!file)
	{
		cout << "\033[1;31m";
		cout << "File " << quoted(fileName) << " not found." << '\n';
		cout << "\033[0m";
		return 1;
	}

	json jf = json::parse(file);
	
	bool silent = jf["silent"];
	string path = jf["path"];
	string cmd = jf["cmd"];
	string fileExten = jf["fileExtensions"];
	int updInt = jf["updateInterval"];

	if (silent == false) {
		cout << "Using config information:" << '\n';
		cout << "\033[1;32m";
		cout << "- Path: " + path << '\n';
		cout << "- Exec: " + cmd << '\n';
		cout << "- File extension: " + fileExten << '\n';
		cout << "\033[0m";

		cout << "\033[0;33m";
		cout << "- Silent: " + to_string(silent) << '\n';
		cout << "- Update interval: " + to_string(updInt) << '\n';
		cout << "\033[0m";
	}

	sleep(2); // Ensure swww have been initialised  
	update(path, cmd, fileExten, silent, updInt);

	return 0;
} 
