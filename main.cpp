#include <iostream>
#include "Data.cpp"

void introduir_dates(Data &data_n, Data &data_act)
{
    int dia_n = 0, mes_n = 0, any_n = 0;
    int dia_a = 0, mes_a = 0, any_a = 0;
    std::cout << "Examen per obtenir el titol de viatger del temps\nIntrodueix la teva data de naixement (dd mm aaaa): " << endl;
    std::cin >> dia_n >> mes_n >> any_n;

    data_n = Data(dia_n, mes_n, any_n);

    std::cout << "Examen per obtenir el titol de viatger del temps\nIntrodueix la teva data de naixement (dd mm aaaa): " << endl;
    std::cin >> dia_a >> mes_a >> any_a;

    data_act = Data(dia_a, mes_a, any_a);
}
int primer_dia_cs(Data data_v)
{
    data_v.set_dia(1);
    while (!data_v.es_cap_de_setmana())
    {
        data_v.avanca_un_dia();
    }
    return data_v.get_dia();
}

int comptar_dimarts_13(Data data_v)
{
    int num_dimarts_trovats = 0;
    for (int i = 1; i < 12; i++)
    {
        data_v.set_dia(13);
        data_v.set_mes(i);
        if (data_v.get_dia_setmana() == "dimarts"){
            num_dimarts_trovats++;
        }
    }
    return num_dimarts_trovats;
}

void comprovar_calendari(Data data_v)
{
    string opcio;
    std::cout << "Vols veure el calendari per comprovar les teves respostes? (s/n)" << std::endl;
    std::cin >> opcio;

    if (opcio == "s")
    {
        data_v.escriure_calendari(data_v.get_any());
    }
}
void preguntes_examen()
{
    int dia_v = 0, mes_v = 0, any_v = 0;
    double puntuacio = 0;
    int primer_dia_cs_r = 0, dies_mes_actual = 0, dimarts_13_r = 0, dies_any_r = 0;
    std::cout << "Introdueix la data a on vols viatjar (dd mm aaaa): " << endl;
    std::cin >> dia_v >> mes_v >> any_v;
    Data data_v = Data(dia_v, mes_v, any_v);

    std::cout << "Quin dia comenca el primer cap de setmana d'aquest mes?" << endl;
    std::cin >> primer_dia_cs_r;

    if (primer_dia_cs_r == primer_dia_cs(data_v))
    {
        std::cout << "Correcte! (+2.5 punts)" << endl;
        puntuacio += 2.5;
    } else std::cout << "Incorrecte!" << endl;

    std::cout << "Quants dies te aquest mes?" << endl;
    std::cin >> dies_mes_actual;

    if (dies_mes_actual == data_v.dies_mes(data_v.get_mes(), data_v.get_any()))
    {
        std::cout << "Correcte! (+2.5 punts)" << endl;
        puntuacio += 2.5;
    } else std::cout << "Incorrecte!" << endl;

    std::cout << "Quants dimarts 13 hi ha aquest any?" << endl;
    std::cin >> primer_dia_cs_r;

    if (dimarts_13_r == comptar_dimarts_13(data_v))
    {
        std::cout << "Correcte! (+2.5 punts)" << endl;
        puntuacio += 2.5;
    } else std::cout << "Incorrecte!" << endl;

    std::cout << "Quants dies te aquest any?" << endl;
    std::cin >> dies_any_r;

    int dies_any_act;
    if (data_v.es_any_de_traspas(data_v.get_any()))
    {
        dies_any_act = 366;
    } else dies_any_act = 365;

    if (dies_any_r == dies_any_act)
    {
        std::cout << "Correcte! (+2.5 punts)" << endl;
        puntuacio += 2.5;
    } else std::cout << "Incorrecte!" << endl;

    std::cout << "Examen finalitzat amb " << puntuacio << "7 punts" << endl;
    if (puntuacio >= 5)
    {
        std::cout << "Enhorabona! Has obtingut el titol de viatger del temps" << endl;
    } else std::cout << "Millor que no t'apropis a cap maquina del temps" << endl;
    comprovar_calendari(data_v);
}

void iniciar_examen(Data &data_n, Data &data_act)
{
    int edat = int(data_n.edat(data_act));
    std::cout << "Tens " << edat << " anys" << endl;
    if (edat >= 18)
    {
        std::cout << "Comencem l'examen" << endl;
    } else
    {
        std::cout << "No pots conduir una maquina del temps!" << endl;
    }
    preguntes_examen();
}

int main()
{
    Data data_n = Data();
    Data data_act = Data();

    introduir_dates(data_n, data_act);

    iniciar_examen(data_n, data_act);

    return 0;
}