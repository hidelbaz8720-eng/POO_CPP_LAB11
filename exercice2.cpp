#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ===== Classe abstraite (interface) =====
class Paiement {
public:
    // Méthode virtuelle pure → interface
    virtual void effectuerPaiement(double montant) = 0;

    // Destructeur virtuel (obligatoire avec polymorphisme)
    virtual ~Paiement() {}
};

// ===== Paiement par carte =====
class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << fixed << setprecision(2)
             << montant << " DH par carte bancaire." << endl;
    }
};

// ===== Paiement en espèces =====
class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << fixed << setprecision(2)
             << montant << " DH en especes." << endl;
    }
};

// ===== Programme principal =====
int main() {
    // Tableau de pointeurs vers la classe abstraite
    Paiement* paiements[4];

    // Remplissage avec différentes instances
    paiements[0] = new PaiementCarte();
    paiements[1] = new PaiementEspece();
    paiements[2] = new PaiementCarte();
    paiements[3] = new PaiementEspece();

    // Simulation de plusieurs paiements via polymorphisme
    double montants[] = { 150.50, 200.00, 75.25, 500.00 };

    cout << "=== SIMULATION DE PAIEMENTS ===" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Transaction " << i + 1 << " : ";
        paiements[i]->effectuerPaiement(montants[i]);
    }

    // Libération mémoire (grâce au destructeur virtuel)
    for (int i = 0; i < 4; i++) {
        delete paiements[i];
    }

    return 0;
}
