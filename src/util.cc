#include <string>
#include <vector>
#include <ctime>
#include <cstring>
using std::string;
using std::vector;

string currentTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}

bool strIsNum(string str) { // made by reinhold
	for (const char& ch : str)
		if (ch < '0' && ch > '9')
			return false;
	return true;
}

bool settingsExist(const INI::Structure &settings) {
	vector <string> appearance_props = {
		"editor_b",
		"editor_f",
		"titlebar_b",
		"titlebar_f",
		"alert_b",
		"alert_f"
	};
	vector <string> editor_props = {
		"tab-width"
	};
	if (settings.Contains("appearance") && settings.Contains("editor")) {
		for (int i = 0; i<appearance_props.size(); ++i) {
			if (!settings.Contains("appearance", appearance_props[i]))
				return false;
		}
		for (int i = 0; i<editor_props.size(); ++i) {
			if (!settings.Contains("editor", editor_props[i]))
				return false;
		}
	}
	else
		return false;
	return true;
}
