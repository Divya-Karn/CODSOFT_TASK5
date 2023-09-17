#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Movie{
    public:
    string title;
    int availableSeats;
    double priceperseat;
    Movie(string t,int seats,double price)
    {
        title=t;
        availableSeats=seats;
        priceperseat=price;
    }
};
class Bookingsystem{
    vector<Movie>movies;
    public:
    void addmovie(string title,int availableSeats,double priceperseat)
    {
           Movie movie(title,availableSeats,priceperseat);
           movies.push_back(movie);
    }
    
    void showmovies()
    {
        cout<<"HERE IS THE MOVIE LISTINGS!!\n";
        for(int i=0;i<movies.size();i++)
        {
            cout<<i+1<<"."<<movies[i].title<<"{Seats:"<<movies[i].availableSeats<<",Price:rupees"<<movies[i].priceperseat<<"}\n";
        }
    }
    
    void bookticket(int movienumber,int numoftickets)
    {
        Movie& selectedmovie=movies[movienumber];
    
        if(movienumber<0 || movienumber>=movies.size())
        {
            cout<<"INVALID MOVIE SELECTION!!"<<endl;
             return;
        }
    
    
   else if(selectedmovie.availableSeats<numoftickets)
    {
        
        cout<<"SORRY!!Not Enough Seats Available. "<<endl;
        return;
    }
    
    
    double totalcost=selectedmovie.priceperseat*numoftickets;
     cout<<"BOOKING SUCCESSFUL FOR  "<<selectedmovie.title<<"!"<<endl;
     cout<<"Total Cost:rupees"<<totalcost<<endl;
     cout<<"HAPPY WATCHING!!";
     cout<<endl;
     selectedmovie.availableSeats -=numoftickets;
    
    }
};
int main()
{
    Bookingsystem bookingsystem;
    bookingsystem.addmovie("DDLJ",50,150.0);
    bookingsystem.addmovie("TITANIC",60,140.0);
    bookingsystem.addmovie("SHERSHAH",30,120.0);
    bookingsystem.addmovie("HERO",20,100.0);
    while(true)
    {
        cout<<"\nWELCOME TO THE MOVIE TICKET BOOKING SYSTEM!!"<<endl;
        cout<<"PLEASE LOOK UP TO OUR MENU!!\n"<<endl;
        cout<<"1.Show Movies"<<endl;
        cout<<"2.Book A Ticket"<<endl;
        cout<<"3.Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            bookingsystem.showmovies();
        }
        else if(choice==2)
        {
            int movienumber,numoftickets;
            cout<<"Enter the Movie number: ";
            cin>>movienumber;
            cout<<"Total number of ticket do you want?";
            cin>>numoftickets;
            movienumber--;
           
            bookingsystem.bookticket(movienumber,numoftickets);
             


        }
        else if(choice==3)
        {
            
            exit(0);
        }
        else
        {
            cout<<"INVALID CHOICE. PLEASE TRY AGAIN!!"<<endl;
        }
    }

}
