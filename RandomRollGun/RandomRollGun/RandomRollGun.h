#pragma once
#include <string>
#include <iostream>
using namespace std;

class RandomRollGun
{
private:
	// Name Variables
	string m_name = "";
	string m_barrelName = "";
	string m_magName = "";
	string m_perk1Name = "";
	string m_perk2Name = "";

	// Int Variables for Random Generator
	int m_barrel = 0;
	int m_mag = 0;
	int m_perk1 = 0;
	int m_perk2 = 0;

public:
	// String Setters/Getters
	void SetName(string name) { m_name = name; }
	string GetName() { return m_name; }

	void SetBarrelName(string barrelName) { m_barrelName = barrelName; }
	string GetBarrelName() { return m_barrelName; }

	void SetMagName(string magName) { m_magName = magName; }
	string GetMagName() { return m_magName; }

	void SetPerk1Name(string perk1Name) { m_perk1Name = perk1Name; }
	string GetPerk1Name() { return m_perk1Name; }

	void SetPerk2Name(string perk2Name) { m_perk2Name = perk2Name; }
	string GetPerk2Name() { return m_perk2Name; }

	// Int Setters/Getters
	void SetBarrel(int barrel) { m_barrel = barrel; }
	int GetBarrel() { return m_barrel; }

	void SetMag(int mag) { m_mag = mag; }
	int GetMag() { return m_mag; }

	void SetPerk1(int perk1) { m_perk1 = perk1; }
	int GetPerk1() { return m_perk1; }

	void SetPerk2(int perk2) { m_perk2 = perk2; }
	int GetPerk2() { return m_perk2; }

	// Selects the name of the barrel through RNG
	void RandomBarrel(int barrel)
	{
		switch (barrel)
		{
		case 1:
			SetBarrelName("Corkscrew Rifling");
			break;
		case 2:
			SetBarrelName("Full Bore");
			break;
		case 3:
			SetBarrelName("Hammered Forge");
			break;
		case 4:
			SetBarrelName("Arrowhead Brake");
			break;
		case 5:
			SetBarrelName("Fluted Barrel");
			break;
		}
	}

	void RandomMag(int mag)
	{
		switch (mag)
		{
		case 1:
			SetMagName("Flared Magwell");
			break;
		case 2:
			SetMagName("Tactical Mag");
			break;
		case 3:
			SetMagName("Extended Mag");
			break;
		case 4:
			SetMagName("Light Mag");
			break;
		case 5:
			SetMagName("Appended Mag");
			break;
		}
	}

	void RandomPerk1(int perk1)
	{
		switch (perk1)
		{
		case 1:
			SetPerk1Name("Threat Detector");
			break;
		case 2:
			SetPerk1Name("Moving Target");
			break;
		case 3:
			SetPerk1Name("Grave Robber");
			break;
		case 4:
			SetPerk1Name("Unrelenting");
			break;
		case 5:
			SetPerk1Name("Slideways");
			break;
		}
	}

	void RandomPerk2(int perk2)
	{
		switch (perk2)
		{
		case 1:
			SetPerk2Name("Disruption Break");
			break;
		case 2:
			SetPerk2Name("Surrounded");
			break;
		case 3:
			SetPerk2Name("Feeding Frenzy");
			break;
		case 4:
			SetPerk2Name("Eye of the Storm");
			break;
		case 5:
			SetPerk2Name("Incandescent");
			break;
		}
	}

	void FindingCorrectWeaponRoll()
	{
		int counters = 0;

		srand((unsigned int)time(NULL));


		cout << "Type your desired roll for the Calus Mini-Tool: " << endl << endl;
		string desiredBarrel = DesiredBarrel();
		string desiredMag = DesiredMag();
		string desiredPerk1 = DesiredPerk1();
		string desiredPerk2 = DesiredPerk2();

		while ( Convert(GetBarrelName()) != Convert(desiredBarrel) || 
				Convert(GetMagName()) != Convert(desiredMag) || 
				Convert(GetPerk1Name()) != Convert(desiredPerk1) || 
				Convert(GetPerk2Name()) != Convert(desiredPerk2))
		{
			int randomBarrel = rand() % 5 + 1;
			int randomMag = rand() % 5 + 1;
			int randomPerk1 = rand() % 5 + 1;
			int randomPerk2 = rand() % 5 + 1;

			RandomBarrel(randomBarrel);
			RandomMag(randomMag);
			RandomPerk1(randomPerk1);
			RandomPerk2(randomPerk2);
			counters++;
			cout << "Counters: " << counters << endl;
			Print();
		}
	}

	// Prints the Random Roll
	void Print()
	{
		SetName("Calus Mini-Tool");
		cout << "Name: " + GetName() << endl;
		cout << "Barrel: " + GetBarrelName() << endl;
		cout << "Magazine: " + GetMagName() << endl;
		cout << "Perk 1: " + GetPerk1Name() << endl;
		cout << "Perk 2: " + GetPerk2Name() << endl;
	}

	void TestingRoll()
	{
		int counters = 0;

		RandomBarrel(5);
		RandomMag(1);
		RandomPerk1(1);
		RandomPerk2(5);

		if (GetBarrelName() != "Fluted Barrel")
		{
			cout << "Barrel Name Testing failed!" << endl;
			throw new exception;
		}
		if (GetMagName() != "Flared Magwell")
		{
			cout << "Mag Name Testing failed!" << endl;
			throw new exception;
		}
		if (GetPerk1Name() != "Threat Detector")
		{
			cout << "Perk 1 Name Testing failed!" << endl;
			throw new exception;
		}
		if (GetPerk2Name() != "Incandescent")
		{
			cout << "Perk 2 Name Testing failed!" << endl;
			throw new exception;
		}
	}


	string DesiredBarrel()
	{
		string barrel;

		cout << "Barrel Options: " << endl;
		cout << "Corkscrew Rifling" << endl;
		cout << "Full Bore" << endl;
		cout << "Hammered Forge" << endl;
		cout << "Arrowhead Brake" << endl;
		cout << "Fluted Barrel" << endl << endl;

		cout << "Barrel: ";
		getline(cin, barrel);
		cout << endl;

		return barrel;
	}

	string DesiredMag()
	{
		string mag;
	
		cout << "Magazine Options: " << endl;
		cout << "Flared Magwell" << endl;
		cout << "Tactical Mag" << endl;
		cout << "Extended Mag" << endl;
		cout << "Light Mag" << endl;
		cout << "Appended Mag" << endl << endl;

		cout << "Magazine: ";
		getline(cin, mag);
		cout << endl;

		return mag;
	}

	string DesiredPerk1()
	{
		string perk1;

		cout << "1st Perk Options: " << endl;
		cout << "Threat Detector" << endl;
		cout << "Moving Target" << endl;
		cout << "Grave Robber" << endl;
		cout << "Unrelenting" << endl;
		cout << "Slideways" << endl << endl;

		cout << "Perk 1: ";
		getline(cin, perk1);
		cout << endl;

		return perk1;
	}

	string DesiredPerk2()
	{
		string perk2;

		cout << "2nd Perk Options: " << endl;
		cout << "Disruption Break" << endl;
		cout << "Surrounded" << endl;
		cout << "Feeding Frenzy" << endl;
		cout << "Eye of the Storm" << endl;
		cout << "Incandescent" << endl << endl;

		cout << "Perk 2: ";
		getline(cin, perk2);
		cout << endl;

		return perk2;
	}

	string Convert(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return s;
	}

};


