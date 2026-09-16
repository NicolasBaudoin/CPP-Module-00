# CPP-Module-00

![C++](https://img.shields.io/badge/C++-98-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Top language](https://img.shields.io/github/languages/top/NicolasBaudoin/CPP-Module-00?style=flat-square)
![Last commit](https://img.shields.io/github/last-commit/NicolasBaudoin/CPP-Module-00?style=flat-square)
[![Notes](https://img.shields.io/badge/ _Notes-suivi-blue?style=flat-square)](NOTES.md)
[![ex01](https://img.shields.io/badge/ex01-en_cours-yellow?style=flat-square)](NOTES.md)

> Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.

Point de départ du parcours C++ à 42. Introduction à la **programmation orientée objet (OOP)**. Tout le code suit la norme **C++98**.

## État d'avancement

| Exercice | Statut | Remarque |
|---|---|---|
| ex00 — Megaphone | ✅ Fonctionnel | Manipulation `char**` en style C ; envisager `std::string`/`std::toupper` pour rester « C++-ish » |
| ex01 — My Awesome PhoneBook | 🟡 Incomplet | `Contact` est fait ; `PhoneBook` n'a aucune méthode et `main.cpp` n'implémente pas la boucle `ADD`/`SEARCH`/`EXIT` ni l'affichage en colonnes (`iomanip`) |
| ex02 — The Job Of Your Dreams | ⬜ Non commencé | Optionnel — seuls les fichiers fournis (`Account.hpp`, `tests.cpp`, log) sont présents, `Account.cpp` reste à écrire |

---

- [C++ — Module 00](#c--module-00)
	- [Règles générales](#règles-générales)
		- [Compilation](#compilation)
		- [Nommage et formatage](#nommage-et-formatage)
		- [Autorisé / Interdit](#autorisé--interdit)
		- [Exigences de conception](#exigences-de-conception)
	- [Exercice 00 — Megaphone](#exercice-00--megaphone)
	- [Exercice 01 — My Awesome PhoneBook](#exercice-01--my-awesome-phonebook)
		- [Commandes acceptées : `ADD`, `SEARCH`, `EXIT` (le reste est ignoré)](#commandes-acceptées--add-search-exit-le-reste-est-ignoré)
	- [Exercice 02 — The Job Of Your Dreams](#exercice-02--the-job-of-your-dreams)
	- [Rendu et évaluation](#rendu-et-évaluation)
	- [Rappels de bon sens](#rappels-de-bon-sens)
- [TUTO](#tuto)



## Règles générales

### Compilation

- Compiler avec `c++` et les flags `-Wall -Wextra -Werror`
- Le code doit **encore** compiler avec le flag `-std=c++98`

### Nommage et formatage

- Les dossiers d'exercices sont nommés `ex00`, `ex01`, ..., `exn`
- Noms de classes en **UpperCamelCase**
- Un fichier de classe porte le nom de la classe : `ClassName.hpp` / `ClassName.cpp` / `ClassName.tpp`
  (ex. classe `BrickWall` → `BrickWall.hpp`)
- Sauf indication contraire, chaque message de sortie se termine par un `\n` et va sur la **sortie standard**
- **Plus de Norminette** : aucun style imposé. Mais du code illisible = code non notable par les pairs. Reste propre.

### Autorisé / Interdit

| ✅ Autorisé | ❌ Interdit |
|---|---|
| Presque toute la bibliothèque standard | Toute autre lib externe |
| Les versions « C++-ish » des fonctions C | C++11 (et dérivés), Boost |
| — | `*printf()`, `*alloc()`, `free()` → **note = 0** |
| — | `using namespace <ns>` et `friend` → **note = -42** |
| STL **uniquement** aux Modules 08 et 09 | Containers (`vector`/`list`/`map`...) et `<algorithm>` avant → **note = -42** |

### Exigences de conception

- Pas de fuites mémoire quand tu utilises `new`
- Du Module 02 au Module 09 : classes en **Orthodox Canonical Form** (sauf mention contraire)
- Toute implémentation de fonction dans un header (hors templates) → **note = 0**
- Chaque header doit être **utilisable indépendamment** (il inclut ses propres dépendances) et protégé contre la **double inclusion** (include guards) → sinon **note = 0**
- Makefile : mêmes règles qu'en C (voir chapitre Norm sur le Makefile)

---

## Exercice 00 — Megaphone

| | |
|---|---|
| **Dossier** | `ex00/` |
| **Fichiers à rendre** | `Makefile`, `megaphone.cpp` |
| **Interdit** | Aucun |

Écrire un programme qui met en **MAJUSCULES** les arguments passés et les affiche.

```
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

> Résous l'exercice « à la manière C++ ».

---

## Exercice 01 — My Awesome PhoneBook

| | |
|---|---|
| **Dossier** | `ex01/` |
| **Fichiers à rendre** | `Makefile`, `*.cpp`, `*.{h, hpp}` |
| **Interdit** | Aucun |

Un répertoire téléphonique en ligne de commande. **Deux classes** :

- **PhoneBook**
  - Contient un tableau de contacts
  - Maximum **8 contacts**. Au 9ᵉ ajout, on **remplace le plus ancien**
  - **Allocation dynamique interdite**
- **Contact**
  - Représente un contact du répertoire

Le phonebook est instancié comme un objet `PhoneBook`, chaque contact comme un objet `Contact`. Ce qui est toujours utilisé en interne est `private`, ce qui est utilisé de l'extérieur est `public`.

### Commandes acceptées : `ADD`, `SEARCH`, `EXIT` (le reste est ignoré)

- **ADD** — saisir un nouveau contact, champ par champ, puis l'ajouter
  - Champs : *first name, last name, nickname, phone number, darkest secret*
  - Aucun champ ne peut être **vide**
- **SEARCH** — afficher les contacts
  - Liste en **4 colonnes** : index, first name, last name, nickname
  - Chaque colonne fait **10 caractères**, séparée par un `|`, texte **aligné à droite**
  - Si le texte dépasse : **tronqué**, dernier caractère affiché remplacé par un `.`
  - Ensuite, demander l'**index** à afficher ; gérer un index hors limites / invalide de façon pertinente
  - Utiliser **`<iomanip>`** pour reproduire l'affichage attendu
- **EXIT** — quitter, contacts perdus à jamais

> Donne un nom pertinent à ton exécutable.
> Références : `<string>` et `<iomanip>` sur cplusplus.com.

---

## Exercice 02 — The Job Of Your Dreams

| | |
|---|---|
| **Dossier** | `ex02/` |
| **Fichiers à rendre** | `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp` |
| **Interdit** | Aucun |

> `Account.hpp`, `tests.cpp` et le fichier de log sont téléchargeables sur la page intranet du module.

Recréer le fichier **`Account.cpp`** disparu, à partir de `Account.hpp`, de `tests.cpp` et du **log** fourni. La sortie de ton programme doit correspondre **exactement** à celle du log (aux timestamps près).

> - L'ordre d'appel des destructeurs peut varier selon le compilateur/OS (ordre inverse possible).
> - **L'exercice 02 n'est pas obligatoire** pour valider le module.

---

## Rendu et évaluation

- Rendu sur le dépôt Git habituel ; seul le contenu du repo est évalué
- Vérifie bien le **nom de tes fichiers**
- Une **petite modification** peut être demandée pendant la soutenance (changement de comportement mineur, quelques lignes à écrire/réécrire, feature simple) — pour vérifier ta réelle compréhension

---

## Rappels de bon sens

- Lis **tout le module** avant de commencer.
- Les exemples révèlent parfois des exigences non écrites explicitement dans les consignes.
- N'hésite pas à te documenter sur les concepts théoriques.
- *By Odin, by Thor! Use your brain!!!*


# RESSOURCES

## TUTO
- [CPP Reference](https://en.cppreference.com/Main_Page)
- [Importants pint CPP 98](https://www.youtube.com/watch?v=78Y_LRZPVRg)
- [SheetCheat CPP](https://www.geeksforgeeks.org/cpp/cpp-cheatsheet/)
- [Class & object CPP](https://www.geeksforgeeks.org/cpp/c-classes-and-objects/)
- [Ecapsulation CPP](https://www.geeksforgeeks.org/cpp/encapsulation-in-cpp/)
- [iomanip for menu](https://www.geeksforgeeks.org/cpp/iomanip-in-cpp/)

## TOOL
- [GDB online](https://www.onlinegdb.com/edit/eIQr7ju98x)

## INSPIRATION
- [Phonebook management style](https://t4tutorials.com/phonebook-management-system-c-project/)
- [Circular buffer exemple](https://stackoverflow.com/questions/53942355/trying-to-create-a-circular-buffer-in-c-using-struct)
