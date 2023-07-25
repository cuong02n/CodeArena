template <class T>
T kadane(T A[], int size) {
    T max_ending_here = A[0];
    T MAX = A[0];
    for (int i = 1; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0L) {
            max_ending_here = 0;
        } else if (max_ending_here > MAX) {
            MAX = max_ending_here;
        }
    }
    return MAX;
}

template <class T>
T kadane(T A[], int size, int& result_begin, int& result_end) {
    T max_ending_here = A[0];
    T MAX = A[0];
    int result_begin_tmp = -1;
    int result_end_tmp = -1;
    for (int i = 1; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
            result_begin_tmp = -1;
        } else {
            if (result_begin == -1) {
                result_begin_tmp = i;
            }
            if (max_ending_here > MAX) {
                MAX = max_ending_here;
                result_begin = result_begin_tmp;
                result_end = i;
            }
        }
    }
    return MAX;
}

void solve(bool verbose = false) {
    int n;
    cin >> n;
    ll A[n / 2 + n % 2];
    ll B[n / 2];
    int a = n / 2 + n % 2;
    int b = n / 2;
    for (int i = 0; i < n / 2; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    if (n % 2) {
        cin >> A[n / 2 + n % 2 - 1];
    }
    ll resA = kadane(A, n / 2 + n % 2);
    ll resB = (n == 1) ? LLONG_MIN : kadane(B, n / 2);

    cout << max(resA, resB) << endl;
}
