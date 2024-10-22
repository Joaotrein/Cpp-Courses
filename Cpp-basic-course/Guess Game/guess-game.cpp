#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
     // cout envia valores (<<) De valor para out
     cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;

     srand(time(NULL));  
     const int SECRET_NUMBER = rand() % 100;
     int counter_try = 0;
     double points = 1000.0;

     cout << "Escolha io nivel de dificuldade: " << endl;
     cout << "Facil (F), Medio(M), dificil(D)" << endl;
     char difficult;
     cin >> difficult;
     int try_number;
     bool not_correct = true;

     if (difficult == 'F')
     {
          try_number = 15;
     }
     else if (difficult == 'M')
     {
          try_number = 10;
     }
     else
     {
          try_number = 5;
     }

     for (counter_try = 1; try_number > counter_try; counter_try++){
          // Para separar a variável basta colocar entre <<
          int guess;
          cout << "Qual o seu chute?" << endl;
          // cin recebe valores (>>) De in pra valor
          cin >> guess;

          double points_lost = abs(guess - SECRET_NUMBER) / 2.0;
          points -= points_lost;

          cout << "chute:" << guess << endl;

          bool correct = guess == SECRET_NUMBER;
          bool bigger = guess > SECRET_NUMBER;

          if (correct)
          {
               cout << "Parabens, voce acertou o numero" << endl;
               not_correct = false;
               break;
          }
          else if (bigger)
          {
               cout << "O valor do seu chute e maior do que a o numero secreto" << endl;
          }
          else
          {
               cout << "O valor do seu chute e menor do que o numero secreto" << endl;
          }
     }

     if(not_correct){
          cout << "Voce perdeu, tente novamente" << endl;
     }
     else{
          cout << "O numero de tentativas totais foi(ram) de: " << counter_try << endl;
          cout.precision(2);
          cout << fixed;
          cout << "Sua pontuacao foi de: " << points << endl;
     }
}