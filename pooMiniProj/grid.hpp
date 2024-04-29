#pragma once
#include <vector>
#include <random>
#include <utility>
using namespace std;

// Auteur : Noé

/*
La classe gère le jeu en lui-même. Elle sert à gérer la mise à jour de la grille au fur et à mesure des tours en faisant la destruction des bonbons, le fait qu’ils tombent, la génération aléatoire des bonbons suivants et l’incrémentation du score.
*/

class Grid
{
    public:
    Grid(){};                                                                           // Constructeur
    ~Grid(){};                                                                          // Destructeur
    bool isValid(vector<vector<int>> g, pair<int, int> c1, pair<int, int> c2);          // Elle prend les positions des deux bonbons sélectionnés et vérifié si c'est un coup valide.
    vector<vector<int>> destructGrid(vector<vector<int>> g , int & score);              // Prend la grille en paramètre et le score puis détruit les bonbons et augmente le score.
    vector<vector<int>> fallGrid(vector<vector<int>> g);                                // Prend la grille en paramètre et fait tomber les bonbons là ou les bonbons ont été détruits.
    vector<vector<int>> fillGrid(vector<vector<int>> g);                                // Prend la grille en paramètre et remplit les espaces vides après fallGrid avec des bonbons aléatoires.
    bool canBeDestruct(vector<vector<int>> g);                                          // Prend la grille en paramètre et renvoie un booléen selon si des bonbons peuvent être détruits dans la grille.
    bool isSolvable(vector<vector<int>> g);                                             // Prend la grille ne paramètre et renvoie un booléen selon si il existe encore un coup possible dans la grille ou si la partie est terminée.
};

void displayMat2d(vector<vector<int>> g);                                               // Affiche dans le terminal la matrice. Fonction qui servait au debug.
int getRandomInt(int min, int max);                                                     // Elle sert à renvoyer un int random pour choisir la couleur aléatoire des bonbons. 