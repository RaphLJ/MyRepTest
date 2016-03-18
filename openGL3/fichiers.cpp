#include <iostream>
#include <fstream>
#include <string>
#include "fichiers.h"
#include "point.h"

using namespace std;

//télécharge données du fichier .txt
void loadData(vector <point> &lpoints, string fileName)
{
	//int numeroPoint = 5;
	//ouverture fichier en mode lecture
	ifstream fichier(fileName);

	int i = 0;
	string sa = "0", sb = "0", sc = "0", sd = "0";
	int a, b, c, d;

	if (fichier)
	{
		string ligne;
		string delimiter = ",";
		cout << "file opened: " << fileName << endl;

		//zapper première ligne
		getline(fichier, ligne);

		while (getline(fichier, ligne))
		{
			sa = ligne.substr(0, ligne.find(delimiter));
			a = stoi(sa);
			ligne.erase(0, sa.size() + 1);
			sb = ligne.substr(0, ligne.find(delimiter));
			b = stoi(sb);
			ligne.erase(0, sb.size() + 1);
			sc = ligne.substr(0, ligne.find(delimiter));
			c = stoi(sc);
			ligne.erase(0, sc.size() + 1);
			sd = ligne.substr(0, ligne.find(delimiter));
			d = stoi(sd);
			ligne.erase(0, sd.size() + 1);

			lpoints.push_back(point(a, b, c, d));
			//cout << sa << " " << sb << " " << sc << " " << sd << endl;
			
			

			//cout << lpoints[5].getAx();
			//
			
		}

		for (int i = 0; i < (int)lpoints.size(); i++)
		{
			cout << "Ecriture dans vecteur : " << lpoints[i].getAx() << "\n";
			cout << "Size : " << lpoints.size() << "\n";

		}

		cout << "TestLecture 0 : " << lpoints[0].getAx() << "\n";

		

	}
	else
	{
		cout << "Error: opening file didn't succeeded" << endl;
	}
	
}






