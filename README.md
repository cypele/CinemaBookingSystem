# CinemaBookingSystem
1. Opis projektu
Cinema Booking System udostępnia możliwość symulowania składania zamówień na bilet na określony
film w odpowiedniej dacie. Umożliwia również ustalanie odpowiednich terminów i filmów w panelu
administratora.
2. Project description
Cinema Booking System is a project that provides possibilities such as making track for movies in
specified room and time, adding new movies and saving that data. User can also order ticket for specified
movie, date, time and chosen seat.
3. Instrukcja użytkownika
Aby korzystać z projektu jako administrator należy na początku wpisać słowo „admin”, jeżeli napiszemy
cokolwiek innego będziemy korzystać z niego jako użytkownik, który może złożyć zamówienie.
4. Kompilacja
Wystarczy zwykła kompilacja.
5. Pliki źródłowe
Projekt składa się z następujących plików źródłowych:
⚫ Cinema Booking System.cpp – jest to cały program.
6. Zależności
⚫ brak
7. Opis klas
W tym punkcie należy umieścić opis wszystkich stworzonych w projekcie klas. Należy podać do czego
służy dana klasa oraz informację o jej publicznych metodach. Opcjonalnie można załączyć fragmenty kodu
źródłowego. Na przykład:
W projekcie utworzono następujące klasy:
⚫ Movie – reprezentuje film podając jego nazwę, gatunek oraz czas trwania.
◼ string get_movie_name() zwraca nazwę filmu.
◼ string get_genre() zwraca gatunek/gatunki filmu.
◼ int get_duration() const zwraca czas trwania filmu.
⚫ Room-reprezentuje pomieszczenie w Sali kinowej
◼ string get_room_name() zwraca nazwę pomieszczenia
◼ int get_capacity() zwraca pojemność pomieszczenia
◼ int get_row() zwraca liczbę rzędów w pomieszczeniu
◼ int get_column() zwraca liczbę pionowych rzędów w pomieszczeniu
⚫ Track-reprezentuje w której Sali o której i kiedy leci dany film
◼ Movie get_movie() zwraca obiekt klasy movie
3
◼ Room get_room() zwraca pomieszczenie w którym odbywać się będzie seans
◼ string get_day() zwraca dzień seansu
◼ string get_start_time() zwraca godzine rozpoczęcia seansu
⚫ User – reprezentuje użytkownika
◼ string get_user_name() zwraca imię uzytkownika
◼ string get_email() zwraca email uzytkownika
◼ string get_password() zwraca hasło użytkownika
⚫ Seat- reprezentuje miejsce siedzące w Sali
◼ Int get_seat() zwraca numer miejsca
◼ Bool get_avaliable() zwraca dostepnosc miejsca
⚫ Order- reprezentuje zamówienie składane przez użytkownika
◼ User GetUser() zwraca obiekt klasy user który zamowil produkt
◼ Track GetTrack() Zwraca na jaki seans został zakupiony bilet
◼ Vector<Seat> Zwraca wektor zamówionych miejsc
8. Zasoby
⚫ Plik wykorzystuje pliki txt jako miejsca zapisu:
⚫ Users.txt
⚫ Tracks.txt
⚫ Movies.txt
⚫ Rooms.txt
⚫ Orders.txt
9. Dalszy rozwój i ulepszenia
Można wprowadzić system logowania z zabezpieczeniem haseł. Możliwość dodawania filmów przez
administratora za pomocą konsoli.
10. Inne
brak
