#include <systemc.h>
SC_MODULE(rtos_scheduler) {
  void task10 {
    while(true) {
      cout << "Task1 Running at " << sc time stamp() << endl;
      wait(1, SC_SEC);
    }
  }
  void task2() {
    while(true) {
      cout << "Task2 Running at " << sc time_stamp() << endl;
      wait(1, SC_SEC);
    }
  }
  SC_CTOR(rtos_scheduler) {
    SC THREAD(task1);
    SC_THREAD(task2);
  }
};
int sc_main(int argc, char* argv[]) { 
  rtos_scheduler obj("Scheduler");
  sc_start(6, SC_SEC);
  return 0;
}
