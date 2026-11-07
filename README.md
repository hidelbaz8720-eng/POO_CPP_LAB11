# TP 11 : Classes Abstraites et Interfaces — C++

##  Description

Ce TP explore les concepts avancés de la **programmation orientée objet en C++**, notamment les **classes abstraites**, les **méthodes virtuelles pures** et les **interfaces**. À travers quatre exercices progressifs, l'objectif est de maîtriser le polymorphisme et la conception orientée objet.

##  Objectifs pédagogiques

- Comprendre et implémenter des **classes abstraites**
- Utiliser des **méthodes virtuelles pures** (`= 0`)
- Manipuler des **pointeurs vers la classe de base** pour le polymorphisme
- Concevoir des **interfaces** (classes 100% abstraites)
- Gérer la **mémoire dynamique** (allocation/libération)
- Appliquer le principe de **substitution de Liskov**

##  Contenu du TP

### Exercice 1 : Formes géométriques
Implémentation d'une hiérarchie de formes avec calcul d'aires.
- Classe abstraite `Forme` avec méthode pure `double aire() const`
- Classes dérivées : `Cercle` (rayon) et `Rectangle` (longueur, largeur)
- Stockage dans un tableau de pointeurs `Forme*` et affichage polymorphe des aires
<img width="1366" height="768" alt="ex1" src="https://github.com/user-attachments/assets/087d671d-abfa-4b1b-b913-c98043f33e38" />

### Exercice 2 : Interface de paiement
Conception d'une interface `Paiement` avec différentes implémentations concrètes.
<img width="1366" height="768" alt="ex2" src="https://github.com/user-attachments/assets/e7b7b415-ebc8-40e8-a1d3-1e48866bcfe9" />

### Exercice 3 : Gestion d'animaux
Hiérarchie d'animaux illustrant les méthodes virtuelles pures et le polymorphisme.
<img width="1366" height="768" alt="ex3" src="https://github.com/user-attachments/assets/7b79d5fe-6e93-435a-8e3f-9b9b0c7b3d2b" />

### Exercice 4 : Système de fichiers virtuel
Modélisation d'un système de fichiers via une classe abstraite commune.
<img width="1366" height="768" alt="ex4" src="https://github.com/user-attachments/assets/b11b1685-8acc-4f67-bfcd-05d0d58d3a3e" />

##  Technologies & Prérequis

- **Langage** : C++ (C++11 ou supérieur)
- **Compilateur** : g++ / clang++ / MSVC
- **Concepts requis** :
  - Héritage et polymorphisme
  - Pointeurs et références
  - Constructeurs / destructeurs (et destructeurs virtuels)
  - Allocation dynamique (`new` / `delete`)


