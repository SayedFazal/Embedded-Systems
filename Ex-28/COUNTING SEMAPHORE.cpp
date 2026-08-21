#include <systemc.h>

SC_MODULE(Counting_Semaphore) {
    int sem;

    void task() {
        while (true) {
            wait(1, SC_SEC);

            if (sem > 0) {
                sem--;

                cout << "Task accessing resource at "
                     << sc_time_stamp()
                     << " Remaining: " << sem << endl;

                wait(2, SC_SEC);

                sem++;

                cout << "Task released resource at "
                     << sc_time_stamp()
                     << " Available: " << sem << endl;
            }
        }
    }

    SC_CTOR(Counting_Semaphore) {
        sem = 2;

        SC_THREAD(task);
        SC_THREAD(task);
        SC_THREAD(task);
    }
};

int sc_main(int argc, char* argv[]) {

    Counting_Semaphore obj("Counting");

    sc_start(10, SC_SEC);

    return 0;
}
