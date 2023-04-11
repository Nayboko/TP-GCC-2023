#include "mylib.hpp"

#include <random>


int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis (gen);
}

void formeCreuse(int x, int y)
{
    std::string str = "";

    if(x <= 0 || y <= 0)
    {
        std::cerr << "Attention, le nombre de colonne ou de ligne doit être strictement positif !" << std::endl;
        return;
    }

    // Pour chaque colonne
    for(int i = 0; i < x; ++i)
    {   
        // Pour chaque ligne
        for (int j = 0; j < y; ++j)
        {
            // Si la colonne ou la ligne est la première ou la dernière, on affiche le caractère
            if((i == 0 || i == x - 1) || (j == 0 || j == y - 1)){
                str += "*";
            }else{
                // Sinon un espace vide
                str+= " ";
            }
        }
        // On s'assure qu'à la fin de la ligne, on fasse bien un retour à la ligne
        str += "\n";
    }

    std::cout << str << std::endl;
}

float distanceManhattan(Point2D p1, Point2D p2)
{
    return 0.0f;
}


float distanceEuclidienne(Point2D p1, Point2D p2)
{
    return 0.0f;
}

void plusProcheVoisin(std::vector<Point2D> points, Point2D P, int dist)
{

}

void plusOuMoins()
{

}