# Cinema Booking System
## Project Description
The Cinema Booking System provides the ability to simulate ordering tickets for a specific movie on a specified date. It also allows administrators to set up appropriate schedules and movies.

## User Instructions
To use the project as an administrator, you must first enter the word "admin". If you enter anything else, you will be using it as a user who can place orders.

## Compilation
Simple compilation is sufficient.

## Source Files
The project consists of the following source files:
- Cinema Booking System.cpp – this is the entire program.

## Dependencies
- None

## Description of Classes
In this section, a description of all classes created in the project should be included. Provide what the class is for and information about its public methods. Optionally, code snippets can be included. For example:
The following classes were created in the project:
- Movie – represents a movie by providing its name, genre, and duration.
  - `string get_movie_name()` returns the movie's name.
  - `string get_genre()` returns the genre(s) of the movie.
  - `int get_duration() const` returns the duration of the movie.
- Room – represents a room in the cinema hall.
  - `string get_room_name()` returns the room's name.
  - `int get_capacity()` returns the capacity of the room.
  - `int get_row()` returns the number of rows in the room.
  - `int get_column()` returns the number of vertical rows in the room.
- Track – represents which movie is playing in which room at what time.
  - `Movie get_movie()` returns an object of the Movie class.
  - `Room get_room()` returns the room where the screening will take place.
  - `string get_day()` returns the day of the screening.
  - `string get_start_time()` returns the start time of the screening.
- User – represents a user.
  - `string get_user_name()` returns the user's name.
  - `string get_email()` returns the user's email.
  - `string get_password()` returns the user's password.
- Seat – represents a seat in the room.
  - `int get_seat()` returns the seat number.
  - `bool get_avaliable()` returns the availability of the seat.
- Order – represents an order placed by a user.
  - `User GetUser()` returns an object of the User class who placed the order.
  - `Track GetTrack()` returns the track for which the ticket was purchased.
  - `vector<Seat>` returns a vector of ordered seats.

## Resources
- The program uses .txt files for storage:
  - Users.txt
  - Tracks.txt
  - Movies.txt
  - Rooms.txt
  - Orders.txt

## Further Development and Enhancements
- Implement a login system with password protection.
- Allow administrators to add movies via the console.

## Other
- None
