#ifndef _MYLIB_HPP_
#define _MYLIB_HPP_

#include <iostream>
#include <vector>

#include "Point2D.hpp"

/// @brief Générer un nombre entier grâce à un moteur pseudo-aléatoire
/// @remark Voir le header <random>
/// @param min Valeur minimale du nombre aléatoire
/// @param max Valeur maximale du nombre aléatoire
/// @return Un nombre entier généré de façon pseudo-aléatoire
int randomInt(int min, int max);

/// @brief Permet de générer sur terminal une forme rectangulaire creuse
/// @remark Utilisation du caractère "étoile" soit *
/// @param x Le nombre de colonnes
/// @param y Le nombre de lignes
void formeCreuse(int x, int y);

/// @brief Calcule la distance dite euclidienne entre deux points de type Point2D
/// @param p1 Un objet de type Point2D
/// @param p2 Un objet de type Point2D
/// @return La distance euclidienne entre les points p1 et p2 en valeur flotante
float distanceEuclidienne(Point2D p1, Point2D p2);

/// @brief Calcule la distance dite de Manhattan entre deux points de type Point2D
/// @param p1 Un objet de type Point2D
/// @param p2 Un objet de type Point2D
/// @return La distance de Manhattan entre les points p1 et p2 en valeur flotante
float distanceManhattan(Point2D p1, Point2D p2);

/// @brief Affiche les plus proches voisins, étant à une certaine distance maximale, d'un Point2D parmi une liste de points
/// @param points Une liste de points
/// @param P Un Point2D quelconque qui est dans la liste
/// @param dist La distance maximale jusqu'à laquelle un point est considéré comme voisin de P
void plusProcheVoisin(std::vector<Point2D> points, Point2D P, int dist);

/// @brief Célèbre jeu du Plus ou Moins invitant l'utilisateur à devenir un nombre mystère en un nombre limité de tentatives.
void plusOuMoins();

#endif // _MYLIB_HPP_