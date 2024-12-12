#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string name;
    string mpaaRating;
    int rating1, rating2, rating3, rating4, rating5;

public:
    Movie(string movieName, string mpaaRating) 
        : name(movieName), mpaaRating(mpaaRating), 
          rating1(0), rating2(0), rating3(0), rating4(0), rating5(0) {}

    string getName() const {
        return name;
    }

    void setName(const string& movieName) {
        name = movieName;
    }

    string getMPAARating() const {
        return mpaaRating;
    }

    void setMPAARating(const string& mpaaRating) {
        this->mpaaRating = mpaaRating;
    }

    void addRating(int rating) {
        if (rating >= 1 && rating <= 5) {
            switch (rating) {
                case 1:
                    rating1++;
                    break;
                case 2:
                    rating2++;
                    break;
                case 3:
                    rating3++;
                    break;
                case 4:
                    rating4++;
                    break;
                case 5:
                    rating5++;
                    break;
            }
        } else {
            cout << "Invalid rating. Rating must be between 1 and 5." << endl;
        }
    }

    double getAverage() const {
        int totalRatings = rating1 + rating2 + rating3 + rating4 + rating5;
        if (totalRatings == 0) {
            return 0.0; // Handle division by zero
        }
        return (rating1 * 1 + rating2 * 2 + rating3 * 3 + rating4 * 4 + rating5 * 5) / static_cast<double>(totalRatings);
    }
};

int main() {
    Movie movie1("The Shawshank Redemption", "R");
    Movie movie2("The Godfather", "R");

    movie1.addRating(5);
    movie1.addRating(5);
    movie1.addRating(5);
    movie1.addRating(4);
    movie1.addRating(5);

    movie2.addRating(5);
    movie2.addRating(5);
    movie2.addRating(4);
    movie2.addRating(5);
    movie2.addRating(4);

    cout << "Movie 1:" << endl;
    cout << "Name: " << movie1.getName() << endl;
    cout << "MPAA Rating: " << movie1.getMPAARating() << endl;
    cout << "Average Rating: " << movie1.getAverage() << endl;

    cout << "\nMovie 2:" << endl;
    cout << "Name: " << movie2.getName() << endl;
    cout << "MPAA Rating: " << movie2.getMPAARating() << endl;
    cout << "Average Rating: " << movie2.getAverage() << endl;

    return 0;
}
