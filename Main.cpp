#include <iostream>
#include <map>
#include <unordered_map>
#include <ctime>
#include "SortMan.h"

int main()
{
	// Start clock to measure time of std::map

	clock_t mapTime = clock();

	std::map<std::string, std::string> map;
	sort_man(map, "messyData.txt", "mapResult.txt");

	std::cout << "Container used: std::map " << std::endl;
	std::cout << "Time elapsed: " << float(clock() - mapTime) / CLOCKS_PER_SEC << std::endl;

	// -------------------------------------------------------------------------------------

	// Start clock to measure time of std::unordered_map

	clock_t umapTime = clock();

	std::unordered_map<std::string, std::string> umap;
	sort_man(umap, "messyData.txt", "umapResult.txt");

	std::cout << "Container used: std::unordered_map" << std::endl;
	std::cout << "Time elapsed: " << float(clock() - umapTime) / CLOCKS_PER_SEC << std::endl;

	system("pause");
}