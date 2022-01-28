#include <iostream>
using namespace std;

int main (void)
{
    //Declaration des variables
    int nb1;
    int nb2;
    int nb3;
    int max;
    bool iteration;

    //Saisie des trois nombres
    cout << "Saisissez le nombres 1 : ";
    cin >> nb1;
    cout << "Saisissez le nombres 2 : ";
    cin >> nb2;
    cout << "Saisissez le nombres 3 : ";
    cin >> nb3;

    //Comparaison des trois nombres pour trouver le max
    iteration = false;

    if(nb1 > nb2)
    {
        if(nb1 > nb3)
        {
            max = nb1;
        }
        else if (nb1 < nb3)
        {
            max = nb3;
        }
        else
        {
            iteration = true;
            max = nb1;
        }
    }
    else if (nb1 < nb2)
    {
        if(nb2 > nb3)
        {
            max = nb2;
        }
        else if(nb2 < nb3)
        {
            max = nb3;
        }
        else
        {
            iteration = true;
            max = nb2;
        }
    }
    else
    {
        iteration = true;
        max = nb1;
    }
      
    
    //Afficher le resultat
    if (iteration == true)
    {
        cout << "Le maximum des trois nombres est " << max << " mais il a ete saisi plusieurs fois." <<endl;
    }
    else 
    {
        cout << "Le maximum des trois nombres est " << max << endl;
    }

    return 0;
}