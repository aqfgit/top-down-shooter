# SFML Shooter
## Uruchomienie
- Należy pobrać pliki źródłowe z tego repozytorium
- Następnie w programie Visual Studio (ja używałem wersji 2019 community) 
wybrać z menu Plik->Nowy->Projekt z istniejących źródeł...
- Typ projektu ustawić na Visual C++, jako lokalizację należy wybrać folder z plikami źródłowymi, który został pobrany z tego repozytorium. Po nadaniu projektowi nazwy, można zakończyc kreator projektu
- Projekt działa na bazie biblioteki SFML, dlatego należy ją zainstalować -  [poradnik z oficjalnej strony SFML]([https://www.sfml-dev.org/tutorials/2.5/start-vc.php](https://www.sfml-dev.org/tutorials/2.5/start-vc.php))

## Zagadnienia

 - [x] **Klasy** - każdy plik
 - [x] **Konstruktory, destruktory** - każdy plik
 - [x] **Dziedziczenie** - większość plików, np.  `Player.h`
 - [x] **Polimorfizm** - np. plik `Game.ccp` w funkcji `void Game::update()`
 - [x]  **Klasa abstrakcyjna**, **czysto wirtualne metody** - np. plik `Unit.h`
 - [x]  **STL** - `std::stack` w pliku `State.h`
 - [x] **Zakresowa pętla for** - np. plik `GameState.cpp` w funkcji `void GameState::deleteDeadEnemies()`
 - [x] **Własny szablon funkcji** - np. plik `Unit.h` w funkcji ` void Unit::checkForBulletsCollision(Object& object)`
 - [x] **Plik .h z teklaracje i .cpp z definicją metod** - każdy plik

### Sterowanie
- **WSAD** poruszanie się
- **LPM** strzelanie
