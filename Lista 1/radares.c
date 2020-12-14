int calculaVelocidadeMedia(double tempoA, double tempoB, double distancia){
    double hora;
    double velH;

    hora = (tempoB - tempoA)/3600;
    velH = distancia/hora;

    return velH;
}

int levouMulta(int tempoA, int tempoB, double distancia, double velocidadeMax){
    float velocidade=0;
    velocidade = calculaVelocidadeMedia(tempoA, tempoB, distancia);

    if(velocidade > velocidadeMax){
        return 1;
    }
    else{
        return 0;
    }
}