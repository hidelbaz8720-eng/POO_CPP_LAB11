#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===== Classe abstraite =====
class NoeudFichier {
protected:
    string m_nom;   // nom commun aux fichiers et dossiers

public:
    NoeudFichier(const string& nom) : m_nom(nom) {}

    // Méthode concrète : retourne le nom
    string nom() const { return m_nom; }

    // Méthode pure : chaque type calcule sa taille à sa façon
    virtual int taille() const = 0;

    // Affichage (utile pour visualiser l'arbre)
    virtual void afficher(int indent = 0) const = 0;

    // Destructeur virtuel
    virtual ~NoeudFichier() {}
};

// ===== Fichier =====
class Fichier : public NoeudFichier {
private:
    int m_taille;

public:
    Fichier(const string& nom, int taille)
        : NoeudFichier(nom), m_taille(taille) {}

    int taille() const override { return m_taille; }

    void afficher(int indent = 0) const override {
        cout << string(indent, ' ') << "📄 " << nom()
             << " (" << m_taille << " Ko)" << endl;
    }
};

// ===== Dossier =====
class Dossier : public NoeudFichier {
private:
    vector<NoeudFichier*> m_enfants;

public:
    Dossier(const string& nom) : NoeudFichier(nom) {}

    // Ajouter un enfant (fichier ou sous-dossier)
    void ajouter(NoeudFichier* enfant) {
        m_enfants.push_back(enfant);
    }

    // Taille = somme récursive des tailles des enfants
    int taille() const override {
        int total = 0;
        for (const auto& e : m_enfants) {
            total += e->taille();
        }
        return total;
    }

    void afficher(int indent = 0) const override {
        cout << string(indent, ' ') << " " << nom()
             << " (" << taille() << " Ko)" << endl;
        for (const auto& e : m_enfants) {
            e->afficher(indent + 4);
        }
    }

    // Destructeur : libère récursivement les enfants
    ~Dossier() {
        for (auto* e : m_enfants) delete e;
    }
};

// ===== Programme principal =====
int main() {


    Dossier* root = new Dossier("root");

    root->ajouter(new Fichier("document.pdf", 500));
    root->ajouter(new Fichier("photo.jpg", 1200));

    Dossier* projets = new Dossier("projets");
    projets->ajouter(new Fichier("main.cpp", 10));
    projets->ajouter(new Fichier("util.cpp", 15));

    Dossier* archives = new Dossier("archives");
    archives->ajouter(new Fichier("backup.zip", 3000));
    projets->ajouter(archives);

    root->ajouter(projets);

    // ===== Affichage de la structure =====
    cout << "=== STRUCTURE DE FICHIERS ===" << endl;
    root->afficher();
    cout << endl;

    // ===== Taille totale du dossier racine =====
    cout << "Taille totale de '" << root->nom()
         << "' : " << root->taille() << " Ko" << endl;

    // ===== Taille de chaque sous-dossier =====
    cout << "\n=== TAILLE DES SOUS-DOSSIERS ===" << endl;
    cout << "Taille de 'projets'  : " << projets->taille() << " Ko" << endl;
    cout << "Taille de 'archives' : " << archives->taille() << " Ko" << endl;

    // Libération récursive (root supprime projets → supprime archives...)
    delete root;

    return 0;
}
