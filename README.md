# Calatoria Cafelei in Romania

## Descriere generala

Acest proiect reprezinta o aplicatie C++ orientata pe obiecte, dezvoltata pentru a gestiona activitatea unei retele de cafenele din Romania.  
Scopul proiectului este simularea functionarii reale a unei afaceri de tip "coffee chain", acoperind aspecte precum organizarea personalului, gestiunea stocurilor, administrarea comenzilor si planificarea evenimentelor speciale.

---

## Functionalitati principale

Aplicatia permite:
- Gestionarea angajatilor (adaugare, stergere, modificare ture)
- Administrarea produselor si a stocurilor
- Inregistrarea comenzilor clientilor si calcularea costurilor totale
- Aplicarea reducerilor pentru clientii fideli
- Organizarea evenimentelor speciale si calcularea costurilor aferente
- Generarea de rapoarte financiare zilnice

---

## Structura retelei

Reteaua de cafenele include cinci orase principale:
- Bucuresti  
- Cluj-Napoca  
- Timisoara  
- Iasi  
- Brasov  

Fiecare cafenea dispune de:
- **Angajati:** barista, manageri, ospatari  
- **Produse:** cafea, ceai, deserturi, sandwichuri  
- **Evenimente:** degustari, muzica live, campanii promotionale  

---

## Detalii tehnice

Proiectul a fost realizat in C++ si include urmatoarele concepte OOP:
- Clase si obiecte
- Constructori si destructori
- Incapsulare
- Mostenire
- Polimorfism
- Abstractizare
- Templates
- Exceptions
- Design patterns

---

## Structura fisierelor CSV

Aplicatia utilizeaza fisiere CSV pentru stocarea datelor persistente:

| Fisier | Continut |
|--------|-----------|
| **angajati.csv** | Lista angajatilor, functia si orele de lucru |
| **produse.csv** | Produsele disponibile si preturile aferente |
| **comenzi.csv** | Comenzile plasate de clienti |
| **evenimente.csv** | Evenimentele si costurile asociate |
| **raport.csv** | Rapoartele financiare zilnice generate automat |

Aplicatia suporta import si export CSV atat in **romana**, cat si in **engleza**.

---

## Arhitectura aplicatiei

Proiectul este organizat modular, respectand principiile de separare a responsabilitatilor:

```plaintext
Calatoria-Cafelei-in-Romania/
├── headere/              # fisiere header cu clase si interfete
├── cafea/                # implementare produse si tipuri de cafea
├── cafenea/              # clase si logica de gestionare a cafenelei
├── main.cpp              # fisier principal de executie
├── Makefile              # script de compilare automata
├── *.csv                 # fisierele de date
├── diagram.png           # diagrama arhitecturii
├── demo video.mp4        # video demonstrativ al proiectului
└── Matrice_Testare.xlsx  # matricea de testare
```

---

## Cerinte de implementare

- Codul este comentat corespunzator, cu explicatii in dreptul conceptelor OOP folosite.  
- Aplicatia respecta principiile de incapsulare, mostenire si polimorfism.  
- Toate clasele sunt implementate in fisiere separate (`.h` si `.cpp`).  
- Programul permite gestionarea datelor printr-un meniu interactiv.  
- Datele sunt importate si exportate automat la pornire si inchidere.  

---

## Instructiuni de compilare si rulare

1. Asigura-te ca ai un compilator C++ instalat (ex: `g++`).
2. Cloneaza repository-ul:
   ```bash
   git clone https://github.com/LSStefan/Calatoria-Cafelei-in-Romania.git
3. Acceseaza directorul proiectului:
   ```bash
   cd Calatoria-Cafelei-in-Romania
4. Compileza proiectul:
   ```bash
   make
5. Ruleaza aplicatia:
   ```bash
   ./main

