//
//  main.cpp
//  project 1
//  soccer team roster
//
//  Created by Sharlotte Holmes on 9/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

void displayMenu () {
    cout << "\nMENU\n";
    cout << "a - Add player\n";
    cout << "d - Remove player\n";
    cout << "u - Update player rating\n";
    cout << "r - Output players above a rating\n";
    cout << "o - Output roster\n";
    cout << "q - Quit\n"<< endl;
}

int main() {
    int jerseyNumbers, playerRatings;
    vector<int> jersey, ratings;
    
    // player information from user
    for (int i = 0; i < 5; i++) {
        cout << "Enter player "<< (i + 1) << "'s jersey number:\n";
        cin >> jerseyNumbers;
        jersey.push_back(jerseyNumbers);
        
        cout << "Enter player " << (i + 1) << "'s rating:\n"<< endl;
        cin >> playerRatings;
        ratings.push_back(playerRatings);
    }
    
    cout << "ROSTER\n";
    for (size_t j = 1; j < jersey.size() + 1; ++ j) {
        cout << "Player " << j << " -- Jersey number: " << jersey.at(j-1) << ", Rating: "<<ratings.at(j-1) << endl;
    }
    
    // building the menu
    char menuChoise;
    
    do {
        displayMenu();
        cout << "Choose an option:"<< endl;
        cin >> menuChoise;
        
        // implementing the menu options
        switch(menuChoise) {
                
            // Add player menu option
            case 'a':
                    cout << "Enter a new player's jersey number:"<< endl;
                    cin >> jerseyNumbers;
                    cout << "Enter the player's rating:"<< endl;
                    cin >> playerRatings;
                    jersey.push_back(jerseyNumbers);
                    ratings.push_back(playerRatings);
                    break;
            // Delete player menu option
            case 'd':
                    cout << endl<< "Enter a jersey number:" << endl;
                    cin >> jerseyNumbers;
                    
                    for ( size_t i = 0; i < jersey.size(); i++) {
                        if(jersey[i] == jerseyNumbers) {
                            jersey.erase(jersey.begin() + i);
                            ratings.erase(ratings.begin() + i);
                            break;
                        }
                    }
                    break;
                
                
            // Update Player Rating menu option
            case 'u':
                    cout << "Enter a jersey number:" << endl;
                    cin >> jerseyNumbers;
                    int newRatings;
                    cout << "Enter the player's rating:" << endl;
                    cin >> newRatings;
                    
                    for (size_t i = 0; i < jersey.size(); i++){
                        if(jersey[i] == jerseyNumbers) {
                            ratings[i] = newRatings;
                            break;
                        }
                    }
                    break;
            // Rating menu option
            case 'r':
                    int threshold;
                    cout << "Enter a rating:" << endl;
                    cin >> threshold;
                    cout << endl<< "ABOVE " << threshold << endl;
                    for(size_t i = 0; i < jersey.size(); ++i){
                       if (ratings[i] > threshold) {
                        cout << "Player " << (i+1) << " -- Jersey number: "<< jersey[i]<< ", Rating: "<< ratings[i]<< endl;
                       }
                    }
                    break;
            // Output roster menu option
            case 'o':
                    cout <<"ROSTER\n";
                    for (size_t i = 0; i < jersey.size(); ++i){
                        cout << "Player " << (i + 1) << " -- Jersey number: " << jersey.at(i) << ", Rating: " << ratings.at(i) << endl;
                    }
                    break;
        }
    } while (menuChoise != 'q');

    
    return 0;
}
