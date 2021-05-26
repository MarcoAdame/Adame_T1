# Adame_T1


El proposito de la presente actividad es realizar la siguiente secuencia con el led RGB de la freedom k64:

        Azul
            Retardo
        Rojo
            Retado
        Verde
            Retardo
            
Donde "Retardo" significa un tiempo de espera entre encender y apagar uno y otro color. Una vez que se muestra el color ver se vuelve a mostrar el color azul, se
retarda, se muestra rojo y así de manera consecutiva. Para generar el retardo se puede usar la función delay: SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
