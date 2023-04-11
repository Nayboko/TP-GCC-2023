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
    return std::abs(p2.x - p1.x) + std::abs(p2.y - p1.y);
}


float distanceEuclidienne(Point2D p1, Point2D p2)
{
    return std::sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

bool areEquals(const Point2D& A, const Point2D& B)
{
    return A.x == B.x && A.y == B.y && A.label == B.label; 
}

void plusProcheVoisin(std::vector<Point2D> points, Point2D P, int dist)
{
    std::vector<Point2D> ppv;
    //Pour chaque point dans la liste des points (c'est comme ça qu'on fait un 'foreach' le plus souvent en C++)
    for(Point2D point : points)
    {
        // On exclut le point P de la liste des point à visiter
        if(areEquals(P,)) continue;
        if(distanceEuclidienne(P, point) <= dist)
        {
            // On rajoute point dans la liste des Plus Proche Voisins (ppv)
            ppv.push_back(point);
        }
    }

    // On vérifie que la liste des plus proches voisins n'est pas vide
    if(ppv.size() > 0)
    {   
        std::cout << "Liste des voisins les plus proches de " << P << " :" << std::endl;
        for(Point2D point : ppv)
        {
            // Grace à la surcharge opérateur de << (Point2D operator<<(const Point2D& P)), on peut afficher directement le contenu de notre objet point
            dist = distanceEuclidienne(P, point);
            std::cout << "\t" << point << " dist : " << dist << std::endl;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Aucun point n'est suffisament proche d'une distance de " << dist << " pour être considéré comme un voisin de " << P << std::endl;
    }
}

void plusOuMoins()
{

}