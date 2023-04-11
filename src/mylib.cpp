#include "mylib.hpp"

#include <random>

constexpr int MIN_NUMBER_TO_GUESS = 1;
constexpr int MAX_NUMBER_TO_GUESS = 100;

constexpr int MIN_ATTEMPTS = 5;
constexpr int MAX_ATTEMPTS = 15;

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
        if(areEquals(P,point)) continue;
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
    bool isRunning(true), hasWin(false);
    int numToGuess(0), remainingAttempts(0), attempt(0);
    std::string userInput("");

    // On rentre dans la boucle générale de jeu
    do{
        hasWin = false;
        attempt = 0;
        /* Ici, j'ai choisi de créer des constantes (en haut du fichier) 
        pour mes min et max. J'aurai pu créer des variables locales const
        mais par flemme de devoir changer ici les valeurs, ce qui implique
        de ma personne à devoir scroller jusqu'ici, j'ai préféré les mettre
        en haut pas pure convenance.
        
        La règle générale : Si une valeur ne doit pas changer, qu'elle est employée en plusieurs endroits différents, ça peut valoir le coup de la mettre en constexpr en haut du fichier et en global "local". Sinon, si c'est utilisé qu'une seule fois, la laisser en constante locale est de rigueur.
        */
        numToGuess = randomInt(MIN_NUMBER_TO_GUESS, MAX_NUMBER_TO_GUESS);
        remainingAttempts = randomInt(MIN_ATTEMPTS, MAX_ATTEMPTS);

        std::cout << "Vous avez " << remainingAttempts << " tentatives pour deviner le nombre mystère !" << std::endl << std::endl;

        // On rentre dans la boucle d'une partie
        do{

            // Boucle pour redemander une entrée utilisateur
            // Tant que l'entrée n'est pas conforme
            do{
                std::cout << "Veuillez saisir un nombre entre " << MIN_NUMBER_TO_GUESS << " et " << MAX_NUMBER_TO_GUESS << " : ";
                std::cin >> userInput;

                // J'ai choisi de ne PAS FAIRE CONFIANCE À l'UTILISATEUR (JAMAIS)
                // Donc je récupère l'input via std::cin sous forme de string que je convertis ensuite en int grâce à la méthode std::stoi (qui veut dire string to int, btw)
                attempt = std::stoi(userInput);
            }while(attempt < MIN_NUMBER_TO_GUESS || attempt > MAX_NUMBER_TO_GUESS);

            if(attempt == numToGuess)
            {
                // Rendu à 0 à la fin de la boucle courante ligne 147
                remainingAttempts = 1;
                hasWin = true;
            }else if (attempt < numToGuess) {
                std::cout << "PLUS ! " << std::endl;
            }
            else {
                std::cout << "MOINS ! " << std::endl;
            }

            std::cout << "Tentatives restantes : " << --remainingAttempts << std::endl;
                        
        }while(!hasWin || remainingAttempts > 0);

        if(hasWin)
        {
            std::cout << "Félicitation ! Vous avez trouvé le nombre mystère : " << numToGuess << std::endl;
        }
        else
        {
            std::cout << "Dommage ! Vous n'avez pas trouvé le nombre mystère qui était " << numToGuess << std::endl;
        }

        userInput = "";
        std::cout << "Souhaitez-vous retenter [y | n] ? ";
        std::cin >> userInput;

        if(std::tolower(userInput.at(0)) != 'y')
        {
            std::cout << "FIN DE PARTIE !" << std::endl;
            isRunning = false;
        }
        
    }while(isRunning);
}