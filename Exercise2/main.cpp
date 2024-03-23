//Includiamo le librerie necessarie
#include <iostream>
#include <fstream>
#include <iomanip>


double mappa(double valore)  //Si crea una funzione del tipo y = mx+q che mandi i valori dall'intervallo [1,5] a [-1,2]
{
    double a1 = 1;
    double b1 = 5;
    double a2 = -1;
    double b2 = 2;
    double m = (b2-a2)/(b1-a1); //Coefficiente angolare
    double q = a2-m*a1; //Termine noto
    double valore_mappato = m*valore+q;

    return valore_mappato;
}


int main()
{
    std::string nameFile = "data.csv";
    std::ifstream input(nameFile);
    std::ofstream output("C:/Users/davep/PCS2024_Exercises/Esercitazione_1_IO/Exercise2/result.txt"); //Crea un file di output
    //(Ho utilizzato una estensione .txt perchè in .csv il file excel dà problemi di visualizzazione della virgola, probabilmente a causa
    // di una cattiva ottimizzazione di quest'ultimo)

    //Si controlla se non ci sono problemi con i file di input e output
    if(input.fail() || output.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    output << std::scientific;  //Notazione scientifica dell'output
    output << std::setprecision(16);
    output << "#\tN Mean" << std::endl; // Intestazione

    double val;
    double mean = 0; //Inizializziamo la media a 0
    unsigned int N = 1; //Inizializziamo un contatore

    while(input>>val) //Ciclo while che scorre sulle righe del file di input e fa la media per ogni iterazione
    {
        double val_mappato = mappa(val);
        mean += val_mappato;
        output << N << "\t" << mean / N << std::endl;
        N++;
    }

    //Chiudiamo i due file
    input.close();
    output.close();

    return 0;
}
