#include <iostream>
#include <thread>
#include <cmath>
#include <string>
#include <algorithm>

#include "functors.h"
#include "util.h"

using namespace std;

int main() {

    double x_0, x_1;
    // int steps_cnt, threads_cnt;
    int steps_cnt, threads_cnt;
    string functionName;

    cout << "Enter function name (POLYNOMIAL, SIN, COS, SIN_COS_POLYNOMIAL, LOGARITHMIC, EXPONENTIAL)" << endl;
    cin >> functionName;
    Function *function = selectFunction(functionName);
    vector<double> a {2, 5, 4, 7};
    cout << "Enter x_0 and x_1" << endl;
    cin >> x_0 >> x_1;
    cout << "Enter steps and threads" << endl;
    cin >> steps_cnt >> threads_cnt;
    if (threads_cnt > steps_cnt) {
        cout << "Threads count is more than Steps count. Exiting." << endl;
        return -1;
    }

    cout << endl << "Counting Integral of \"" << function->representation() <<
            "\" from " << x_0 << " to " << x_1 << endl;

    int avg_steps = steps_cnt / threads_cnt;
    int left_steps = steps_cnt % threads_cnt;
    double interval = (x_1 - x_0) / steps_cnt;
    auto steps_per_thread = new int[threads_cnt];
    for (int i = 0; i < threads_cnt; i++) {
        steps_per_thread[i] = avg_steps;
        if (left_steps > 0) {
            steps_per_thread[i]++;
            left_steps--;
        }
    }

    double start = x_0;
    thread compute_threads[threads_cnt];
    auto results = new double[threads_cnt];
    for (int i = 0; i < threads_cnt; i++) {
        results[i] = 0.0;
    }
    double result = 0;
    for (int i = 0; i < threads_cnt; i++) {
        compute_threads[i] = thread(sample_integral, function, start, interval, steps_per_thread[i],
                                    ref(results[i]));
        start += interval * steps_per_thread[i];
    }

    for (int i = 0; i < threads_cnt; i++) {
        if (compute_threads[i].joinable()) {
            compute_threads[i].join();
            result += results[i];
        }
    }

    cout << result;

    /**
     * There was a part for timing
     */
//    clock_t tStart;
//    for (int threads_cnt = 1; threads_cnt < 10; threads_cnt++) {
//        tStart = clock();
//
//        int avg_steps = steps_cnt / threads_cnt;
//        int left_steps = steps_cnt % threads_cnt;
//        double interval = (x_1 - x_0) / steps_cnt;
//        auto steps_per_thread = new int[threads_cnt];
//        for (int i = 0; i < threads_cnt; i++) {
//            steps_per_thread[i] = avg_steps;
//            if (left_steps > 0) {
//                steps_per_thread[i]++;
//                left_steps--;
//            }
//        }
//
//        double start = x_0;
//        thread compute_threads[threads_cnt];
//        auto results = new double[threads_cnt];
//        for (int i = 0; i < threads_cnt; i++) {
//            results[i] = 0.0;
//        }
//        double result = 0;
//        for (int i = 0; i < threads_cnt; i++) {
//            compute_threads[i] = thread(sample_integral, function, start, interval, steps_per_thread[i],
//                                        ref(results[i]));
//            start += interval * steps_per_thread[i];
//        }
//
//        for (int i = 0; i < threads_cnt; i++) {
//            if (compute_threads[i].joinable()) {
//                compute_threads[i].join();
//                result += results[i];
//            }
//        }
//
//        cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
//    }
}
