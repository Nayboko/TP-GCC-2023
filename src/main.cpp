#include <iostream>
#include <vector>

#include "mylib.hpp"

constexpr int MAX_POINTS = 25;
constexpr int MIN_COORD_POINTS = -10;
constexpr int MAX_COORD_POINTS = 10;

void Exercice1();

void Exercice2();

void Exercice3();

int main (int argc, char** argv)
{
    int numExo(0);
    if(argc > 1 && argc < 3)
    {
        numExo = std::stoi(argv[1]);
    }

    switch (numExo)
    {
    case 1:
        Exercice1();
        break;

    case 2:
        Exercice2();
        break;
    case 3:
        Exercice3();
        break;
    default:
        std::cout << "Le numéro de l'exercice n'a pas été reconnu." << std::endl;
        break;
    }

    return 0;
}

void Exercice1()
{
    std::cout << "# Exercice 1 : Forme creuse" << std::endl;

    int col, lin  = 0;
    std::cout << "Veuillez saisir le nombre de colonnes : ";
    std::cin >> col;

    std::cout << "Veuillez saisir le nombre de lignes : ";
    std::cin >> lin;

    formeCreuse(col, lin);
}

void Exercice2()
{
    std::cout << "# Exercice 2 : Une question de distance" << std::endl;
    int x(0), y(0), dist(0);
    std::string label = "";

    
    std::vector<Point2D> points;

    std::cout << "## Generation de " << MAX_POINTS << " points"<< std::endl;
    for(int i = 0; i < MAX_POINTS; ++i){
        
        x = randomInt(MIN_COORD_POINTS, MAX_COORD_POINTS);
        y = randomInt(MIN_COORD_POINTS, MAX_COORD_POINTS);
        label = 'A' + randomInt(0, 25);
        label.append(std::to_string(randomInt(0, 25)));

        points.push_back(Point2D(x, y, label));
    }

    Point2D P = points.at(0);

    do{
        std::cout << "Veuillez saisir une distance maximale entre les voisins : ";
        std::cin >> dist;
    }while(dist <= 0);
    
    plusProcheVoisin(points, P, dist);
}

void Exercice3()
{
    plusOuMoins();
}