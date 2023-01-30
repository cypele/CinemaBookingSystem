#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <fstream>
#include <map>


using namespace std;




class Movie 
{
private:
	string fname;
	string fgenre;
	int fduration;

public:


	Movie(const string& name = "", const string& genre = "", int duration = 0) :
	fname{ name }, fgenre{ genre }, fduration{ duration } {}

	string get_movie_name() const { return fname; }
	string get_genre() const { return fgenre; }
	int get_duration() const { return fduration; }
		
	void set_name(const string& name) { fname = name; }
	void set_genre(const string& genre) { fgenre = genre; }
	void set_duration(int duration) { fduration = duration; }

};

ostream& operator<< (ostream& out, const Movie& rhs)
{
	out << rhs.get_movie_name() << endl << rhs.get_genre() << endl <<
		"Czas trwania: "<<rhs.get_duration() << "min" << endl;
	return out;

}




class Room 
{
private:
	string fname;
	int frow;
	int fcolumn;
	int fcapacity;

public:


	Room(const string& name = "", int row = 0, int column = 0) :
		fname{ name }, frow{ row }, fcolumn{ column } {};

	string get_room_name() const { return fname; }
	int get_capacity() const { return frow*fcolumn; }
	int get_row() const { return frow; }
	int get_column() const { return fcolumn; }

	void set_name(const string& name) { fname = name; }
	void set_row(int row) { frow = row; }
	void set_column(int column) { fcolumn = column; }


};

ostream& operator<< (ostream& out, const Room& rhs)
{
	out << rhs.get_room_name() << endl << "Rows:" <<rhs.get_row() << endl <<
		"Colums:" << rhs.get_column()<< endl;
	return out;

}



class Track  {
private:
	Room froom;
	Movie fmovie;
	string fday;
	string fstart_time;

public:

	Track(const Room& room, const Movie& movie, const string& day, const string& start_time) :
		froom{ room }, fmovie{ movie }, fday{day}, fstart_time{ start_time } {};
	
	Movie get_movie() const { return fmovie; }
	Room get_room() const { return froom; }
	string get_day() const { return fday; }
	string get_start_time() const { return fstart_time; }

	void show_track(void) {
		cout << fmovie.get_movie_name() << endl << froom.get_room_name()
			<< endl << get_day() << endl << get_start_time() << endl;
	}
};

ostream& operator<< (ostream& out, const Track& rhs)
{
	out << rhs.get_movie() << rhs.get_room() <<
		rhs.get_day() << endl << rhs.get_start_time() << endl << endl << endl;
	return out;


}

bool operator== (const Track& lhs, const Track& rhs)
{
	return lhs.get_movie().get_movie_name() == rhs.get_movie().get_movie_name() &&
		lhs.get_room().get_room_name() == rhs.get_room().get_room_name() &&
		lhs.get_day() == rhs.get_day() &&
		lhs.get_start_time() == rhs.get_start_time();
}



class User {
	string fusername;
	string femail;
	string fpassword;
public:
	User(const string& username="", const string& email="", const string& password="") :
		fusername{ username }, femail{ email }, fpassword{password} {};

	string get_user_name() const { return fusername; }
	string get_email() const { return femail; }
	string get_password() const { return fpassword; }

	void set_user_name(const string& username) { fusername = username; }
	void set_email(const string& email) { femail = email; }
	void set_password(const string& password) { fpassword = password; }
};

ostream& operator<< (ostream& out, const User& rhs)
{
	out << rhs.get_user_name() << endl << rhs.get_email() << endl << rhs.get_password() << endl;
	return out;

}


class Seat	
{
private:
	int fseat;
	bool favailability;
public:
	Seat(int seat) :
		fseat{ seat }, favailability{false} {};

	bool get_availability() const { return favailability; }
	int get_seat() const { return fseat; }

};

ostream& operator<< (ostream& out, const Seat& rhs)
{
	out << rhs.get_seat() << endl;
	return out;

}

bool operator== (int& lhs, const Seat& rhs)
{
	return lhs == rhs.get_seat();
}




class Order {
	User fuser;
	Track ftrack;
	vector<Seat> fseats;
public:
	Order(User user, Track track, vector<Seat> seats) :
		fuser{ user }, ftrack{ track }, fseats{ seats }{};

	User getUser() const { return fuser; };
	Track getTrack() const { return ftrack; };
	vector<Seat> getSeats() const { return fseats; };
};

ostream& operator<< (ostream& out, const Order& rhs)
{
	out << rhs.getUser() << endl << rhs.getTrack();
	for (auto i : rhs.getSeats()) 
	{
		out << i;
	}
	return out;

}


void save_movies(const vector<Movie>& movies)
{
	fstream file("C:\\Users\\adamc\\Desktop\\movies.txt");

	if (file.is_open())
	{
		for (auto element : movies)
		{
			file << element;
		}
	}
	file.close();
}

void save_rooms(const vector<Room>& rooms)
{
	fstream file("C:\\Users\\adamc\\Desktop\\rooms.txt");

	if (file.is_open())
	{
		for (auto element : rooms)
		{
			file << element;
		}
	}
	file.close();
}


void save_tracks(const vector<Track>& tracks)
{
	fstream file("C:\\Users\\adamc\\Desktop\\tracks.txt");

	if (file.is_open())
	{
		for (auto element : tracks)
		{
			file << element;
		}
	}
	file.close();
}

void save_users(const vector<User>& users)
{
	fstream file("C:\\Users\\adamc\\Desktop\\users.txt");

	if (file.is_open())
	{
		for (auto element : users)
		{
			file << element;
		}
	}
	file.close();
}


void save_orders(const vector<Order>& orders)
{
	fstream file("C:\\Users\\adamc\\Desktop\\orders.txt");

	if (file.is_open())
	{
		for (auto element : orders)
		{
			file << element;
		}
	}
	file.close();
}


vector<int> pass_truck(const vector<Track>& tracks, const vector<Movie>& movies, int& i)
{
	vector<int> passed_trucks;
	string movie_name = movies[i].get_movie_name();

	for(int j=0; j<tracks.size(); j++)
	{
		if(tracks[j].get_movie().get_movie_name()==movie_name)
		{
			passed_trucks.push_back(j);
			
		}
		

	}
	return passed_trucks;
}





vector<Movie> get_movies()
{
	fstream file2("C:\\Users\\adamc\\Desktop\\movies.txt");
	string line;
	vector<Movie> saved_movies;
	int line_count = 0;
	if (file2.is_open()) {
		while (getline(file2, line)) {
			line_count++;
		}
		file2.close();
	}

	fstream file("C:\\Users\\adamc\\Desktop\\movies.txt");
	if (file.is_open()) 
	{
		int i = 0;
		while (getline(file, line)) 
		{
			i++;
			string title = line;
			getline(file, line);
			i++;
			string genre = line;
			getline(file, line);
			i++;
			line.erase(0, 14);
			line.erase(line.find("min"), 3);
			string time = line;
			Movie movie(title, genre, stoi(time));
			saved_movies.push_back(movie);
		
		if (i == line_count)
			break;
		}
	}
	return saved_movies;
}


vector<Room> get_rooms()
{
	fstream file2("C:\\Users\\adamc\\Desktop\\rooms.txt");
	string line;
	vector<Room> saved_rooms;
	int line_count = 0;
	if (file2.is_open()) {
		while (getline(file2, line)) {
			line_count++;
		}
		file2.close();
	}

	fstream file("C:\\Users\\adamc\\Desktop\\rooms.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			i++;
			string room_name = line;
			getline(file, line);
			i++;
			line.erase(0,5);
			string rows = line;
			getline(file, line);
			i++;
			line.erase(0, 7);
			string columns = line;
			Room room(room_name, stoi(rows), stoi(columns));
			saved_rooms.push_back(room);

			if (i == line_count)
				break;
		}
	}
	return saved_rooms;
}



vector<Track> get_tracks()
{
	fstream file2("C:\\Users\\adamc\\Desktop\\tracks.txt");
	string line;
	vector<Track> saved_tracks;
	int line_count = 0;
	if (file2.is_open()) {
		while (getline(file2, line)) {
			line_count++;
		}
		file2.close();
	}

	fstream file("C:\\Users\\adamc\\Desktop\\tracks.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			i++;
			string title = line;
			getline(file, line);
			i++;
			string genre = line;
			getline(file, line);
			i++;
			line.erase(0, 14);
			line.erase(line.find("min"), 3);
			string time = line;
			Movie movie(title, genre, stoi(time));
			getline(file, line);
			i++;
			string room_name = line;
			getline(file, line);
			i++;
			line.erase(0, 5);
			string rows = line;
			getline(file, line);
			i++;
			line.erase(0, 7);
			string columns = line;
			Room room(room_name, stoi(rows), stoi(columns));
			getline(file, line);
			i++;
			string day = line;
			getline(file, line);
			i++;
			string hour = line;
			getline(file, line);
			getline(file, line);
			i = i + 2;
			saved_tracks.push_back(Track(room, movie, day, hour));
			if (i == line_count)
				break;
		}
	}
	return saved_tracks;
}

vector<User> get_users()
{
	fstream file2("C:\\Users\\adamc\\Desktop\\users.txt");
	string line;
	vector<User> saved_users;
	int line_count = 0;
	if (file2.is_open()) {
		while (getline(file2, line)) {
			line_count++;
		}
		file2.close();
	}

	fstream file("C:\\Users\\adamc\\Desktop\\users.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			i++;
			string username = line;
			getline(file, line);
			i++;
			string email = line;
			getline(file, line);
			i++;
			string password = line;
			User user(username, email, password);
			saved_users.push_back(user);

			if (i == line_count)
				break;
		}
	}
	return saved_users;
}






//zwraca wektor wektorow <string> pierwsza pozycja to daty bez powtorzeń drugi to godziny dla kolejnych dni a trzeci zwraca indeksy
vector<vector<string>> print_hours(const vector<string>& dates, const vector<string>& hours)
{
	
	int date_num = 1;
	int hour_num = 1;
	int buffer = 1;
	string current_date = dates[0];

	vector<string> d = { "" };
	vector<string> h = { "" };
	vector<string> id_ih;
	vector<vector<string>> d_h_index;
	cout << "Wybierz date oraz godzine seansu: " << endl;
	cout << date_num << ": " << current_date << endl;
	d.push_back(current_date);
	for (int i = 0; i < dates.size(); i++)
	{
		if (dates[i] != current_date)
		{
			current_date = dates[i];
			date_num++;
			cout <<"\n"<<date_num << ": " << current_date << endl;
			d.push_back(current_date);
		}
		cout << hour_num << ": " << hours[i] << endl;
		h.push_back(hours[i]);
		hour_num++;
	}
	cout << endl << "Aby wybrac najpierw zatwierdz enterem date a potem godzine" << endl;
	cin >> date_num;
	cin >> hour_num;
	id_ih = { to_string(date_num), to_string(hour_num) };
	d_h_index = { d,h,id_ih };
	return d_h_index;
}












void print_seats(const Track& track, const vector<Order>& orders)
{
		int rows;
		int columns;
		int seat=0;
		rows = track.get_room().get_row();
		columns = track.get_room().get_column();
		int s = 1;

		for (int r = 1; r < rows; r++)
		{
			for (int c = 1; c < columns; c++)
			{

				if (s < 10)
				{
					for (auto i : orders)
					{
						if (i.getTrack() == track)
						{
							for (auto j : i.getSeats())
							{
								if (s == j) {
									cout << "-" << "     ";
									s++;
								}
							}
						}
					}
				}

				if (s >= 10 && s < 100)
				{
					for (auto i : orders)
					{
						if (i.getTrack() == track)
						{
							for (auto j : i.getSeats())
							{
								if (s == j) {
									cout << "--" << "    ";
									s++;
								}
							}
						}
					}
				}
				else
					cout << s << "     ";
				if (s >= 100)
				{
					for (auto i : orders)
					{
						if (i.getTrack() == track)
						{
							for (auto j : i.getSeats())
							{
								if (s == j) {
									cout << "---" << "   ";
									s++;
								}
							}
						}
					}
				}
				else
					cout << s << "   ";
				s++;
			}
			cout << endl;
		}

}














int main()
{
	Movie Avatar("Avatar Cien Wody", "Action, Adventure, Fantasy", 168);
	Movie Zoolander("Zoolander", "Comedy", 124);
	Movie LOTR("LOTR", "Adventure, Fantasy", 168);
	vector <Movie> movies = { Avatar,Zoolander,LOTR };
	vector<Track> tracks = get_tracks();
	save_movies(movies);

	Room C2("C2", 6, 8);
	Room C3("C3", 8, 8);
	Room A1("A1", 9, 9);
	Room A2("A2", 12, 12);
	vector<Room> rooms = { C2,C3,A1,A2 };
	save_rooms(rooms);

	User user1("adam12", "adam12@gmail.com", "qwerty");
	User user2("daniel34", "daniel@gmail.com", "qwerty");
	User user3("maiek42", "maiek@gmail.com", "rwqwerr");
	User user4("namus612", "namus@gmail.com", "123445");
	vector<User> users;
	users=get_users();

	vector<Seat>zaj_miej1 = { 34,35,36 };
	vector<Seat>zaj_miej2 = { 43,45,46 };
	vector<Seat>zaj_miej3 = { 92,78,18 };
	vector<Seat>zaj_miej4 = { 24,53,18 };


	Order order1(user1, tracks[0], zaj_miej1);
	Order order2(user2, tracks[1], zaj_miej2);
	Order order3(user3, tracks[2], zaj_miej3);
	Order order4(user4, tracks[3], zaj_miej4);
	vector<Order> orders = { order1,order2,order3 };
	save_orders(orders);


	vector <string> hours = { "10:30", "11:00", "11:30", "12:00", "12:30",
		"13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00", "16:30",
		"17:00", "17:30", "18:00", "18:30", "19:00", "19:30", "20:00",
		"20:30", "21:00", "21:30", "22:00", "22:30", "23:00" };


	string wiersz;
	cin >> wiersz;

	//admin
	if (wiersz == "admin") {
		cout << "Czy chesz ustawic date poszczegolnych filmow na ten tydzien (type 0 if want to go to next day)?" << endl;
		cout << "Spowoduje to usuniecie obecnego harmonogramu" << endl;
		cin >> wiersz;
		if (wiersz == "yes")
		{
			tracks.clear();
			system("CLS");

			for (int i = 0; i < 7; i++)
			{
				string day;
				string hour;
				int dayInt = 25 + i;
				int monthInt = 1;
				int yearInt = 2023;
				if (dayInt > 31)
				{
					dayInt -= 31;
					monthInt++;
				}
				if (monthInt > 12)
				{
					monthInt -= 12;
					yearInt++;
				}
				day = to_string(dayInt) + "/" + to_string(monthInt) + "/" + to_string(yearInt);
				cout << day << endl;


				for (;;) {
					cout << "Jaki film chcesz zaplanowac?" << endl;

					int movie_number;
					for (int i = 0; i < movies.size(); i++)
					{
						cout << i + 1 << " " << movies[i].get_movie_name() << endl;

					}
					cin >> movie_number;
					movie_number--;
					system("CLS");

					if (movie_number == -1)
						break;

					cout << "W jakim pomieszczeniu ma odbyc sie projekcja?" << endl;
					int room_number;
					for (int i = 0; i < rooms.size(); i++)
					{
						cout << i + 1 << " " << rooms[i].get_room_name()
							<< "Pojemnosc sali:" << rooms[i].get_capacity() << endl;

					}
					cin >> room_number;
					room_number--;
					system("CLS");

					if (room_number == -1)
						break;

					cout << "O ktorej godzinie (10:30 - 22:30)?" << endl;
					int hour_number;
					for (int i = 0; i < hours.size(); i++)
					{
						cout << i + 1 << " " << hours[i] << endl;

					}
					cin >> hour_number;
					hour_number--;
					system("CLS");

					if (hour_number == -1)
						break;

					tracks.push_back(Track(rooms[room_number], movies[movie_number], day, hours[hour_number]));
				}
			}
			save_tracks(tracks);
		}


	}




	///Użytkownik
	else {
		cout << "*****************************************" << endl;


		string username;
		string password;
		string email;

		cout << "Wiataj w naszym kinie!" << endl << endl;
		cout << "podaj nazwe uzytkownika" << endl;
		cin >> username;
		cout << "podaj swoj email" << endl;
		cin >> email;
		cout << "podaj swoje haslo" << endl;
		cin >> password;

		User nowy(username, email, password);
		users.push_back(nowy);
		save_users(users);
		cout << "pomyslnie zalozyles konto!" << endl;


		cout << "Wybierz jeden z dostepnych filmow: " << endl << endl;
		int movie_number = 1;
		int i;
		for (auto i : movies)
		{
			cout << '\n' << movie_number << ":" << endl;
			cout << i << endl;
			movie_number++;

		}
		movie_number = 1;



		int pozycja = 0;


		vector<int>tracks_number;
		vector<string>tracks_dates;
		vector<string>tracks_hours;
		int chosen_track_index = 0;

		cin >> pozycja;

		for (;;)
		{
			if (pozycja != 0 && pozycja <= movies.size())
			{
				pozycja--;
				system("CLS");
				tracks_number = pass_truck(tracks, movies, pozycja);
				cout << movies[pozycja];
				for (auto i : tracks_number)
				{
					tracks_dates.push_back(tracks[i].get_day());
					tracks_hours.push_back(tracks[i].get_start_time());

				}
				vector<vector<string>>d_h_index = print_hours(tracks_dates, tracks_hours);
				vector<string> d = d_h_index[0];
				vector<string> h = d_h_index[1];
				vector<int> index_d_h = { stoi(d_h_index[2][0]),stoi(d_h_index[2][1]) };
				string chosen_date = d[index_d_h[0]];
				string chosen_hour = h[index_d_h[1]];

				for (i = 0; i < tracks.size(); i++)
				{
					string temp1 = tracks[i].get_day();
					string temp2 = tracks[i].get_start_time();
					if (chosen_date == temp1 && chosen_hour == temp2
						&& movies[pozycja].get_movie_name() == tracks[i].get_movie().get_movie_name())
					{
						chosen_track_index = i;
						cout << chosen_track_index << endl;
					}

				}
				break;

			}
			else
			{
				system("CLS");
				cout << "Nie ma takiej pozycji." << endl;
				cout << "Wybierz jeszcze raz: " << endl;
				for (auto i : movies)
				{
					cout << movie_number << ":" << endl;
					cout << i << endl;
					movie_number++;

				}
				movie_number = 1;
				cin >> pozycja;
			}
		}



		for (;;)
		{
			
			system("CLS");
			cout << "Zarezerwuj miejsce: " << endl;

			int seat = 0;

			print_seats(tracks[chosen_track_index], orders);
			cin >> seat;
			Seat miejsce(seat);
			vector<Seat> seats;
			seats.push_back(miejsce);


			
			system("CLS");

			//print_seats(tracks[chosen_track_index], orders);
			cout << "Chcesz wybrac kolejne miejsce?" << endl;
			string chcesz;
			cin >> chcesz;
			if (chcesz != "tak")
			{
				Order zamowienie(nowy, tracks[chosen_track_index], seats);
				orders.push_back(zamowienie);
				save_orders(orders);
				break;
			}
			else {
				print_seats(tracks[chosen_track_index], orders);
			}

		}
	}
}

