////
// Created by Michele Dioli on 1/22/25.
//
#include "Articolo.h"
#include "Rivista.h"
#include <iostream>

int main(){
    Rivista r = Rivista::Builder("RIV001", "Rivista Informatica", "Informatica", "Rivista Informatica", 2025)
        .setEditore("Monduzzi")
        .setPagine(100)
        .setPubblicatore("Sala")
        .setIntervalloPubblicazione(30)
        .setEdizione(1)
        .setDifficolta(3)
        .build();
    std::cout << r.informazioniArticolo(&r) << std::endl;

    Rivista::Builder builder("RIV001", "Rivista Informatica", "Informatica", "Rivista Informatica", 2025);
    builder.setPagine(200);
}