#include <iostream>
using namespace std;

int main()
{
     // cout envia valores (<<) De valor para out
     cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;

     const int SECRET_NUMBER = 40;
     int counter_try = 0;

     double points = 1000.0;

     bool not_correct = true;

     while(not_correct){
          counter_try++;
          // Para separar a variável basta colocar entre <<
          int guess;
          cout << "Qual o seu chute?" << endl;
          // cin recebe valores (>>) De in pra valor
          cin >> guess;

          double points_lost = abs(guess - SECRET_NUMBER) / 2.0;
          points = points - points_lost;

          cout << "chute:" << guess << endl;

          bool correct = guess == SECRET_NUMBER;
          bool bigger = guess > SECRET_NUMBER;

          if (correct)
          {
               cout << "Parabens, voce acertou o numero" << endl;
               not_correct = false;
               cout << "O numero de tentativas totais foi(ram) de: " << counter_try << endl;
               cout.precision(2);
               cout.fixed;
               cout << "Sua pontuacao foi de: " << points << endl;
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
}