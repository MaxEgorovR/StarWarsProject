#include <StarWarsApp.h>


void StarWarsApp::setPerson(int person) {
	this->person = person;
}

void StarWarsApp::setRequestPerson() {
	this->requestPerson = "/api/people/" + std::to_string(this->person) + "/";
}

void StarWarsApp::setRequestPlanet() {
	this->requestPlanet = "/api/planets/" + (this->resultPerson["homeworld"][this->resultPerson["homeworld"].size() - 1]).get<std::string>() + "/";
}

void StarWarsApp::setRequestFilm() {
	if (requestFilm != 0) {
		delete[] requestFilm;
		this->requestFilm = new std::string[this->resultPerson["films"].size()];
		for (int i = 0; i < this->resultPerson["films"].size(); i++) {
			this->requestFilm[i] = "/api/planets/" + (this->resultPerson["homeworld"][this->resultPerson["homeworld"].size() - 1]).get<std::string>() + "/";
		}
	}
	else {
		this->requestFilm = new std::string[this->resultPerson["films"].size()];
		for (int i = 0; i < this->resultPerson["films"].size(); i++) {
			this->requestFilm[i] = "/api/planets/" + (this->resultPerson["homeworld"][this->resultPerson["homeworld"].size() - 1]).get<std::string>() + "/";
		}
	}
}

nlohmann::json StarWarsApp::getResultPerson() {
	if (auto response = Cli->Get(requestPerson)) {
		if (response->status == 200) {
			this->resultPerson = nlohmann::json::parse(response->body);
			return nlohmann::json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
}

nlohmann::json StarWarsApp::getResultPlanet() {
	if (auto response = Cli->Get(requestPlanet)) {
		if (response->status == 200) {
			this->resultPlanet = nlohmann::json::parse(response->body);
			return nlohmann::json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
}

nlohmann::json StarWarsApp::getResultFilm(int i) {
	if (auto response = Cli->Get(requestFilm[i])) {
		if (response->status == 200) {
			return nlohmann::json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
}
