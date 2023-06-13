#pragma once
#include <string>

struct InfoWidget {
	std::string widgetName;
	std::string widgetData;
	int padding;

	void setName(std::string name) {
		widgetName = name + ": ";
	}
};