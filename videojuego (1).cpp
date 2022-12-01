// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;


//Atributos del Enemigo1
string EnemyName1 = "Malo";
int enemyHP1 = 3000;
int enemyDamage1 = 0;
bool enemyIsALive1 = true;
​
//Atributos del Enemigo2
string EnemyName2 = "bueno";
int enemyHP2 = 2500;
int enemyDamage2 = 0;
bool enemyIsALive2 = true;
​
//Atributos del Héroe
string heroName;
int heroDamage;
int dano = 0;
int heroHP = 6000;
bool heroIsAlive = true;
​
​
​
int rel(int min, int max) {
    srand((unsigned int)time(NULL));
    return rand() % (max - min + 1) + min;
}

    void gamestart() {
        cout << "El enemigo 1 " << EnemyName1 << " que tiene " << enemyHP1 << " puntos de vida \n el enemigo 2 " << EnemyName2 << " que tiene " << enemyHP2 << " puntos de vida acaban de aparecer \n";
        cout << "pon el nombre del heroe que lo va a derrotar\n";
        cin >> heroName;
        cout << "El nombre del heroe es " << heroName << "\n";
    }

    void attack() {
        switch (option) {
        case 1:
            cout << "Has usado la espalda\n";
            dano = generateattack(300, 400);
            break;
        case 2:
            cout << "Has usado el arco\n";
            dano = generateattack(500, 700);
            break;
        case 3:
            cout << "Has usado el punetazo\n";
            dano = generateattack(150, 400);
            break;
        case 4:
            cout << "Has usado la magia\n";
            dano = generateattack(500, 900);
            break;

        default:
            break;
        }
    }


    void chooseattack() {
         cout << "Escoge ataque\n[1] ESPAlDA \n[2] ARCO";
         cout << "[3] PUÑETAZO \n[4] MAGIA\n";
         cin >> option;
    }

    bool checkEnemyStatus() {
        if (EnemyHP1 <= 0) {
            cout << "Te has cargado al enemigo " << EnemyName1<< " \n";
            enemyHP = 0;
            return false;
            
        }
        else {
            cout << "El enemigo " << EnemyName1 << " tiene " << EnemyHP1 << " puntos de vida\n";
            return true;



        }
    }
​
int main()
{
    gamestart();
    ​
        while ((enemyIsALive2 || enemyIsALive1) && heroIsAlive) {

            cout << "Escoge enemigo para atacar\n";
            cout << " [1] Malo\n";
            cout << " [2] bueno\n";
            int option = 0;
            cin >> option;
            int enemy = option;
            string enemyName = enemy == 1 ? EnemyName1 : EnemyName2;
            if ((enemy == 1 && enemyIsALive1) || (enemy == 2 && enemyIsALive2))
            {
                chooseattack();
                attack();

                int enemyDamage = 0;
                int enemyHP = 0;
                bool currentEnemyALive = true;

                if (enemy == 1) {
                    enemyHP1 = enemyHP1 - dano;
                    enemyIsALive1 = enemyHP1 > 0;
                    enemyHP = enemyHP1;
                    currentEnemyALive = enemyIsALive1;

                    enemyDamage = enemyIsALive1 ? genera(0, 950) : 0;
                    ​
                }
                else {
                    enemyHP2 = enemyHP2 - danotmp;
                    enemyIsALive2 = enemyHP2 > 0;
                    enemyHP = enemyHP2;
                    currentEnemyALive = enemyIsALive2;
                    enemyDamage = enemyIsALive2 ? genera(0, 1500) : 0;


                }
                heroHP = heroHP - enemyDamage;
                heroIsAlive = heroHP > 0;
                cout << "Le has hecho " << danotmp << " puntos de dano.\n";
                ​
                    if (currentEnemyALive && heroIsAlive)
                    {
                        cout << "Le quedan " << enemyHP << " puntos de vida\n";
                        cout << "El enemigo te  ataca! te ha hecho " << enemyDamage << " puntos de dano, te quedan " << heroHP << " puntos de vida\n";
                        ​
                    }
                    else if (!currentEnemyALive) {
                        cout << "El enemigo " << enemyName << " ha fallecido\n";
                    }
                    else if{
                        cout << "Nuestro heroe esta muerto\n";
                    }
                ​
                    }
                    else
                    {
                cout << "El enemigo " << enemyName << " ha muerto, selecciona otro enemigo\n";
                     }




        }
    if (heroIsAlive) {
        cout << "has derrotado a los enemigos\n";
    }
    else {
        cout << " has muerto\n";
    }
    ​
        return 0;
    ​
        ​
}