// StarWarsProject.cpp: определяет точку входа для приложения.
//
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "StarWarsProject.h"

using namespace std;

int main()
{
	using json = nlohmann::json;

	StarWarsApp Cli("https://swapi.dev");
	int choise, choise1, num;
	bool flag = true;
	json resultPerson, resultPlanet, resultFilm;


	while (flag) {
		cout << "1 - Character search by number\n2 - The character's planet\n3 - Movies with the character\n4 - Exit\n";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "\nEnter the character's number:\n";
			cin >> choise1;
			Cli.setPerson(choise1);
			Cli.setRequestPerson();
			resultPerson = Cli.getResultPerson();
			cout << "\nName of person: " << resultPerson["name"] << "\nHeight of person: " << resultPerson["height"] << "\nMass of person: " << resultPerson["mass"] << "\nHair color of person: " << resultPerson["hair_color"] << "\nSkin color of person: " << resultPerson["skin_color"] << "\nEye color of person: " << resultPerson["eye_color"] << "\nBirth year of person: " << resultPerson["birth_year"] << "\nGender of person: " << resultPerson["gender"] << "\n\n";

		case 2:
			resultPlanet = Cli.getResultPlanet();
			cout << "\nName of planet: " << resultPlanet["name"] << "\nRotation period of planet: " << resultPlanet["rotation_period"] << "\nOrbital period of planet: " << resultPlanet["orbital_period"] << "\nDiameter of planet: " << resultPlanet["diameter"] << "\nClimate of planet: " << resultPlanet["climate"] << "\nGravity of planet: " << resultPlanet["gravity"] << "\nTerrain of planet: " << resultPlanet["terrain"] << "\nSurface water: " << resultPlanet["surface_water"] << "\nPopulation in planet: " << resultPlanet["population"];
		case 3:
			for (num = 0; num < resultPerson["films"].size(); num++) {
				resultFilm = Cli.getResultFilm(num);
				cout << "\nFilm's name:" << resultFilm["title"] << "\nFilm's release date:" << resultFilm["release_date"] << "\n\n";
			}
		case 4:
			flag = false;
		}
	}


	return 0;
}
