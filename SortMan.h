#pragma once
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

template <class Container>
static void sort_man
(	Container	fwCont,
	const	std::string source,
	const	std::string target)
{
	// Declare a list to store result
	std::list<std::string> resultCont;

	// Make a backward container base on the container type coming in
	Container bwCont = Container();

	// take the source in and load into searchable container
	// Load file data into searchable container
	std::ifstream sosFile;
	sosFile.open(source);

	//// Insert data into searchable container
	std::string line;
	while (std::getline(sosFile, line))
	{
		std::istringstream iss(line);
		std::string delimiter = ",";

		std::string name = line.substr(0, line.find(delimiter));
		line.erase(0, line.find(delimiter) + delimiter.length());
		std::string next = line;

		fwCont.insert(make_pair(name, next));
		bwCont.insert(make_pair(next, name));
	}

	// Do algorithm
	// Pick an arbitrary starting point
	// By selecting from first of the container
	Container::iterator start = fwCont.begin();

	// Add the name into back of result container
	resultCont.push_back(start->first);

	// Find west neighbour and add to back of result
	for (int i = 0; i < fwCont.size(); i++)
	{
		Container::iterator it = fwCont.find(resultCont.back());
		if (it != fwCont.end())
			resultCont.push_back(it->second);
		else
			break;
	}

	// Continue find east neighbour and add to front of result
	for (int i = 0; i < bwCont.size(); i++)
	{
		Container::iterator it = bwCont.find(resultCont.front());
		if (it != bwCont.end())
			resultCont.push_front(it->second);
		else
			break;
	}

	// Output the file into target
	// Open target file
	std::ofstream tgtFile;
	tgtFile.open(target);

	// Write from list into target file
	while (!resultCont.empty())
	{
		std::string name = resultCont.front();
		resultCont.pop_front();
		tgtFile << name << std::endl;
	}
}