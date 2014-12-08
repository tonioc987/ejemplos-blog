#include <ncurses.h>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex ncurses_mutex;

class NCursesWindow {
public:
  NCursesWindow(int height, int width, 
    int starty, int startx, int counter) :
    height(height), width(width), starty(starty), 
    startx(startx), counter(counter) {
    // inicializa una ventana
    window = newwin(height, width, starty, startx);
  }
  
  void operator() (){
    int i = 0;
    unique_lock<mutex> lock{ncurses_mutex, defer_lock};
    while(i < 10) {
      // las rutinas de ncurses no son seguras con multiples
      // hilos, las protegemos con un mutex
      lock.lock();
      mvwprintw(window, 0, 0, "%d", counter);
      wrefresh(window);
      lock.unlock();
      this_thread::sleep_for(chrono::seconds(1));
      i++;
      counter++;
    }
  }
  
private:
  int starty, startx, height, width;
  int counter;
  WINDOW *window;
};

int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  refresh();
  
  thread t1{NCursesWindow{5,5,5,5,0}};
  thread t2{NCursesWindow{5,5,5,11,10}};
  thread t3{NCursesWindow{5,5,11,5,20}};
  thread t4{NCursesWindow{5,5,11,11,30}};
  
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  endwin();
  return 0;
}
