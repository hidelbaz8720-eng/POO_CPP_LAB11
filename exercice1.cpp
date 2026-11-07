#include <iostream>
#include <cmath>
using namespace std;

// ===== Classe abstraite =====
class Forme {
public:
    // Méthode virtuelle pure → rend la classe abstraite
    virtual double aire() const = 0;

    // Destructeur virtuel (bonne pratique pour l'héritage)
    virtual ~Forme() {}
};

// ===== Cercle =====
class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(double r) : rayon(r) {}

    double aire() const override {
        return M_PI * rayon * rayon;
    }
};

// ===== Rectangle =====
class Rectangle : public Forme {
private:
    double longueur;
    double largeur;
public:
    Rectangle(double l, double L) : longueur(l), largeur(L) {}

    double aire() const override {
        return longueur * largeur;
    }
};

// ===== Programme principal =====
int main() {
    double rayon, longueur, largeur;

    // --- Cercle ---
    cout << "=== CERCLE ===" << endl;
    cout << "Entrez le rayon : ";
    cin >> rayon;
    Cercle c(rayon);

    // --- Rectangle ---
    cout << "\n=== RECTANGLE ===" << endl;
    cout << "Entrez la longueur : ";
    cin >> longueur;
    cout << "Entrez la largeur  : ";
    cin >> largeur;
    Rectangle r(longueur, largeur);

    // --- Affichage via polymorphisme ---
    cout << "\n=== RESULTATS ===" << endl;
    cout << "Aire du cercle    : " << c.aire() << endl;
    cout << "Aire du rectangle : " << r.aire() << endl;

    // Bonus : utilisation via pointeur de base (polymorphisme)
    Forme* formes[2] = { &c, &r };
    cout << "\n=== AFFICHAGE POLYMORPHE ===" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Forme " << i + 1 << " : aire = " << formes[i]->aire() << endl;
    }

    return 0;
}