#pragma once

#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <openservice.h>

class StarWarsApp {
	httplib::Client* Cli;
	int person;
	std::string requestPerson;
	std::string requestPlanet;
	std::string* requestFilm;
	nlohmann::json resultPerson;
	nlohmann::json resultPlanet;
public:
	StarWarsApp();

	StarWarsApp(std::string Cli);

	void setPerson(int person);

	void setRequestPerson();

	void setRequestPlanet();

	void setRequestFilm();

	nlohmann::json getResultPerson();

	nlohmann::json getResultPlanet();

	nlohmann::json getResultFilm(int i);
};