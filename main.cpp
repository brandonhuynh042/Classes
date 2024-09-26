#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include "Media.h"
#include "Movies.h"
#include "VideoGame.h"
#include "Music.h"
using namespace std;

// This program stores a database of media types, where the user can add, search, and delete from the database.
// Brandon Huynh, last edited 9/26/2024.

// forwarding functions
void addMovie(vector<Media*> &database);
void addMusic(vector<Media*> &database);
void addVideoGame(vector<Media*> &database);
void searchDatabase(vector<Media*> &database);
void deleteMedia(vector<Media*> &database);

int main() {
  vector <Media*> database;
  bool quit = false;
  char input[10];
  // Main sequence
  while (quit == false) {
    // Take in user input, show commands
    cout << "You can: \'ADD\' \'SEARCH\' \'DELETE\' \'QUIT\'" << endl;
    cin >> input;
    // See what they entered...
    if (strcmp(input, "ADD") == 0) {
      // What kind of media do they want to add? Go to the corresponding add function.
      cout << "You can add: \'MOVIE\' \'MUSIC\' \'VIDEOGAME\'" << endl;
      cin >> input;
      if (strcmp(input, "MOVIE") == 0) {
	addMovie(database);
      }
      else if (strcmp(input, "MUSIC") == 0) {
	addMusic(database);
      }
      else if (strcmp(input, "VIDEOGAME") == 0) {
	addVideoGame(database);
      }
    }
    else if (strcmp(input, "SEARCH") == 0) {
      searchDatabase(database);
    }
    else if (strcmp(input, "DELETE") == 0) {
      deleteMedia(database);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Quitting." << endl;
      quit = true;
    }
    else {
      cout << "Please enter a valid input!";
    }
  }
  return 0;
}

void addMovie(vector<Media*> &database) {
  // Create a new movie.
  Movies* newMovie = new Movies();
  // Take user inputs for all of the different information, add to the new movie.
  cout << "What is the title of the movie?" << endl;
  char titleInput[50];
  cin.ignore(64, '\n');
  cin.get(titleInput, 50);
  newMovie->setTitle(titleInput);
  cout << "What year did the movie come out?" << endl;
  int yearInput;
  cin >> yearInput;
  newMovie->setYear(yearInput);
  cout << "What is the duration in minutes?" << endl;
  int durInput;
  cin >> durInput;
  newMovie->setDuration(durInput);
  float ratingInput;
  cout << "What is the rating?" << endl;
  cin >> ratingInput;
  newMovie->setRating(ratingInput);
  char directorInput[50];
  cout << "Who is the director?" << endl;
  cin.ignore(64, '\n');  
  cin.get(directorInput, '\n');
  newMovie->setDirector(directorInput);
  // Add the movie to the end of the database!
  cout << "Inserting movie: " << newMovie->getTitle() << ", " << newMovie->getYear() << ", " << newMovie->getDuration() << " minutes, " << newMovie->getRating() << ", directed by " << newMovie->getDirector() << endl; 
  database.push_back(newMovie);
 }

void addMusic(vector<Media*> &database) {
  // Same process as add movie, but for music stuff
  Music* newMusic = new Music();
  cout << "What is the song title?" << endl;
  char titleInput[50];
  cin.ignore(64, '\n');
  cin.get(titleInput, 50);
  newMusic->setTitle(titleInput);
  cout << "What year did the song come out?" << endl;
  int yearInput;
  cin >> yearInput;
  newMusic->setYear(yearInput);
  cout << "What is the artist's name?" << endl;
  char artistInput[50];
  cin.ignore(64, '\n');
  cin.get(artistInput, 50);
  newMusic->setArtist(artistInput);
  cout << "What is the publisher of the song?" << endl;
  char publisherInput[50];
  cin.ignore(64, '\n');
  cin.get(publisherInput, 50);
  newMusic->setPublisher(publisherInput);
  cout << "How long is the song in minutes?" << endl;
  int durInput;
  cin >> durInput;
  newMusic->setDuration(durInput);
  // Add the music to the end of the database
  cout << "Inserting music: " << newMusic->getTitle() << ", " << newMusic->getArtist() << ", " << newMusic->getPublisher() << ", " << newMusic->getYear() << ", " << newMusic->getDuration() << endl;
  database.push_back(newMusic);
}

void addVideoGame(vector<Media*> &database) {
  // Same process as add movie, but for video game stuff
  VideoGame* newVideoGame = new VideoGame();
  cout << "What is the name of the video game?" << endl;
  char titleInput[50];
  cin.ignore(64, '\n');
  cin.get(titleInput, 50);
  newVideoGame->setTitle(titleInput);
  cout << "What year did the game come out?" << endl;
  int yearInput;
  cin >> yearInput;
  newVideoGame->setYear(yearInput);
  cout << "Who was the publisher of the game?" << endl;
  char publisherInput[50];
  cin.ignore(64, '\n');
  cin.get(publisherInput, 50);
  newVideoGame->setPublisher(publisherInput);
  cout << "What is the rating of the game?" << endl;
  float ratingInput;
  cin >> ratingInput;
  newVideoGame->setRating(ratingInput);
  // Add the video game to the end of the database
  cout << "Inserting video game: " << newVideoGame->getTitle() << ", " << newVideoGame->getPublisher() << ", " << newVideoGame->getYear() << ", " << newVideoGame->getRating() << endl;
  database.push_back(newVideoGame);
}

void searchDatabase(vector<Media*> &database) {
  // See if the user wants to search by title or year
  cout << "Search by: \'TITLE\', \'YEAR\'" << endl;
  char searchInput[6];
  cin >> searchInput;
  if (strcmp(searchInput, "TITLE") == 0) {
    // Recieve the users search
    cout << "What is the title of the media?" << endl;
    char titleInput[50];
    cin.ignore(64, '\n');
    cin.get(titleInput, 50);
    // Traverse through the database, and print the media if found.
    for (vector<Media*>:: iterator it = database.begin(); it != database.end(); ++it) {
      if (strcmp((*it)->getTitle(), titleInput) == 0) {
	cout << "Found: ";
	(*it)->print();
      }
    }
  }
  else if (strcmp(searchInput, "YEAR") == 0) {
    // Same process as search by title, but for year
    cout << "What year was it released?" << endl;
    int yearInput;
    cin >> yearInput;
    for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it) {
      if ((*it)->getYear() == yearInput) {
	cout << "Found: ";
	(*it)->print();
	cout << '\n';
      }
    }
  }
  else {
    cout << "Please enter a valid input..." << endl;
  }
}

void deleteMedia(vector<Media*> &database) {
  // See if the user wants to search by title or year
  cout << "Search by: \'TITLE\', \'YEAR\'" << endl;
  char searchInput[6];
  cin >> searchInput;
    if (strcmp(searchInput, "TITLE") == 0) {
    cout << "What is the title of the media?" << endl;
    char titleInput[50];
    cin.ignore(64, '\n');
    cin.get(titleInput, 50);
    // Traverse through the database, and print if media is found.
    for (vector<Media*>:: iterator it = database.begin(); it != database.end(); ++it) {
      if (strcmp((*it)->getTitle(), titleInput) == 0) {
        cout << "Found: ";
        (*it)->print();
	// Seeing if the user wants to delete it
	cout << "Would you like to delete this? Type \'YES\' or \'NO\'." << endl;
	char deleteInput[4];
	cin.ignore(16, '\n');
	cin.get(deleteInput, 4);
	// If so, delete it and free the memory
	if (strcmp(deleteInput, "YES") == 0) {
	  database.erase(it);
	  delete *it;
	  cout << "Deleted!" << endl;
	  return;
	}
	else {
	  cout << "Not deleted?" << endl;
	}
      }
    }
    cout << "Not found!" << endl;
  }
  else if (strcmp(searchInput, "YEAR") == 0) {
    // Same process as title, but for year
    cout << "What year was it released?" << endl;
    int yearInput;
    cin >> yearInput;
    for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it) {
      if ((*it)->getYear() == yearInput) {
        cout << "Found: ";
        (*it)->print();
         cout << "Would you like to delete this? Type \'YES\' or \'NO\'." << endl;
        char deleteInput[4];
        cin.ignore(16, '\n');
        cin.get(deleteInput, 4);
        if (strcmp(deleteInput, "YES") == 0) {
          database.erase(it);
          delete *it;
          cout << "Deleted!" << endl;
          return;
        }
        else {
          cout << "Not deleted?" << endl;
        }

      }
    }
    cout << "Not found!" << endl;
  }
  else {
    cout << "Please enter a valid input..." << endl;
  }


}
