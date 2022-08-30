#include <iostream>
using namespace std; 

/*Name: Tanisha Mahmud 
Class: CS 135 
Lab 10 */

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER}; // establish genres
class Time {  // declare class Time 
public:
    int h; //hours 
    int m; // minutes 
};

int minutesSinceMidnight(Time time)
{
    int count; //initialize variable for count 
    count = (time.h * 60); //count 60 minutes per hour 
    count += time.m; // add minutes 
    return count; 
}

int minutesUntil(Time earlier, Time later)
{
    int count; 
    count = (later.h - earlier.h) * 60;  // convert hours into mins 
    if (later.m - earlier.m < 0) 
    {
        count -= earlier.m - later.m; 
    }
    else
    {
        count += later.m - earlier.m; 
    }
    return count; 
}

Time addMinutes(Time time0, int min)
{
    Time later; // create new time 
    later.h = time0.h; // give it the same hour 
    later.m = time0.m + min; // add mins 
    if (later.m >= 60) // if min goes above 60, convert to hour
    {
        int converter; 
        converter = later.m / 60; 
        later.h += converter;
        later.m -= converter * 60 ; 
    }
    return later; 
}

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
void printTimeSlot(TimeSlot ts)
{
    printMovie(ts.movie); 
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    cout << "[starts at " << ts.startTime.h << ":" << ts.startTime.m
    << ", ends by " << endtime.h << ":" << endtime.m << "]"; 
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot newtime; // declare new time variable 
    newtime.movie = nextMovie; //for same movie 
    Time endtime = addMinutes(ts.startTime, ts.movie.duration); //calc end
    newtime.startTime = endtime; 
    return newtime; 
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int checker; 
    checker = minutesUntil(ts1.startTime, ts2.startTime); //time diff
    if (checker < 0)
    {
        checker = minutesUntil(ts2.startTime, ts1.startTime); // check which
        if (checker < ts2.movie.duration) // if not enough time 
        {
            return true;
        }
    }
    else 
    {
        if (checker < ts1.movie.duration)
        {
            return true; 
        }
    }
    return false; 
}
int main()
{
    Movie BTTF; 
    BTTF.title = "Back to the Future"; 
    BTTF.genre = COMEDY; 
    BTTF.duration = 116; 
    TimeSlot BTTFt; 
    BTTFt.movie = BTTF; 
    BTTFt.startTime.h = 9; 
    BTTFt.startTime.m= 15; 
    printTimeSlot(BTTFt); 
    Movie panther; 
    panther.title = "Black Panther"; 
    return 0; 
}