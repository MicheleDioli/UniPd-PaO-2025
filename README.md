# Progetto-QT

## Compilazione

La compilazione è facilitata dalla presenza di uno script `make.sh` nella cartella `src`.  
Per compilare il progetto, è necessario avere Qt installato. Verifica la presenza di Qt con il comando:

```sh
qmake --version
```

Per compilare, eseguire lo script con:

```sh
sh make.sh
```

Lo script è stato testato su **Debian 12** e **macOS Sequoia 15.3.2**.  
In caso di problemi, procedere con la compilazione manuale.

## Compilazione manuale

1. Accedere alla cartella `src` ed eseguire il comando:

    ```sh
    qmake -project
    ```

    Questo comando creerà il file `src.pro`.

2. Aprire `src.pro` e aggiungere la seguente riga (preferibilmente alla riga 8):

    ```sh
    QT += widgets
    ```

3. Salvare il file e tornare al terminale.  
   Eseguire quindi i seguenti comandi per completare la compilazione:

    ```sh
    qmake
    make
    ```

Se tutto è andato a buon fine, verrà generato il file eseguibile `applicazione`.

## Esecuzione

Dopo la compilazione, nella cartella `src` verrà creato il file eseguibile `src`.  
È possibile eseguirlo in due modi:

- Facendo doppio clic su di esso
- Da terminale con il comando:

    ```sh
    ./src
    ```

## Problemi con `globalPos()`

L'uso di `globalPos()` è attualmente deprecato.  
Se si verificano problemi, modificare il file `cliccabile.cpp` situato in:

```
src/view/sensoriqt/cliccabile.cpp
```

Alla riga 8, individuare la seguente riga:

```cpp
MostraMenu(event->globalPos());
```

E sostituirla con:

```cpp
// MostraMenu(event->globalPos());  // Versione deprecata
MostraMenu(event->globalPosition().toPoint());  // Versione aggiornata
```
