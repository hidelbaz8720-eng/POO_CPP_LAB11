#include <iostream>
#include <vector>
using namespace std;

// ===== Classe abstraite =====
class Animal {
public:
    // Méthode virtuelle pure → classe abstraite
    virtual void crier() const = 0;

    // Méthode concrète (héritée telle quelle)
    virtual void info() const {
        cout << "Je suis un animal." << endl;
    }

    // Destructeur virtuel (bonne pratique)
    virtual ~Animal() {}
};

// ===== Chien =====
class Chien : public Animal {
public:
    void crier() const override {
        cout << "Wouf !" << endl;
    }
};

// ===== Chat =====
class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou !" << endl;
    }
};

// ===== Vache =====
class Vache : public Animal {
public:
    void crier() const override {
        cout << "Meuh !" << endl;
    }
};

// ===== Programme principal =====
int main() {
    // Vecteur de pointeurs vers la classe abstraite
    vector<Animal*> animaux;

    // Instanciation des différents animaux
    animaux.push_back(new Chien());
    animaux.push_back(new Chat());
    animaux.push_back(new Vache());
    animaux.push_back(new Chien());
    animaux.push_back(new Chat());

    // Appels polymorphes
    cout << "=== CRI DES ANIMAUX ===" << endl;
    for (size_t i = 0; i < animaux.size(); i++) {
        cout << "Animal " << i + 1 << " : ";
        animaux[i]->crier();
    }

    // Appel de la méthode concrète héritée
    cout << "\n=== INFO (methode heritee) ===" << endl;
    for (Animal* a : animaux) {
        a->info();
    }

    // Libération mémoire
    for (Animal* a : animaux) {
        delete a;
    }
    animaux.clear();

    return 0;
}
