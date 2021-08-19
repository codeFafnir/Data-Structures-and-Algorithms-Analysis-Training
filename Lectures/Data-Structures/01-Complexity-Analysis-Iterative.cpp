#include <bits/stdc++.h>
using namespace std;

void function_1(int n) {
    int i = 1;
    while (i * i <= n) {
        int j = 1;
        while (j <= n) {
            j *= 2;
        }
        i += 1;
    }
}
void function_2(int n) {
    int i = 1, s = 1;
    while (s <= n) {
        i += 1;
        s += i;
    }
}
void function_3(int n) {
    int i = 1;
    while (i * i <= n) {
        i += 1;
    }
}
void function_4() {
    int i = 1;
    while (i <= 100) {
        i += 1;
    }
}
void function_5() {
    int i = 1;
    while (i <= 100) {
        int j = 1;
        while (j <= 100) {
            j += 1;
        }
        i += 1;
    }
}
void function_6(int n) {
    int i = 1;
    while (i <= n) {
        i *= 2;
    }
}
void function_7(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            j *= 2;
        }
        i += 1;
    }
}
void function_8(int n) {
    int i = n / 2;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            int k = 1;
            while (k <= n) {
                k *= 2;
            }
            j *= 2;
        }
        i += 1;
    }
}
void function_9(int n) {
    int i = 1;
    while (i <= n) {
        i += 1;
    }
}
void function_10(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= 100) {
            j += 1;
        }
        i += 1;
    }
}
void function_11(int n) {
    int i = n / 2;
    while (i <= n) {
        int j = 1;
        while (j <= n / 2) {
            int k = 1;
            while (k <= n) {
                k *= 2;
            }
            j += 1;
        }
        i += 1;
    }
}
void function_12(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            int k = 1;
            while (k <= 100) {
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}
void function_13(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            j += 1;
        }
        i += 1;
    }
}
void function_14(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            j += 1;
        }
        i += 1;
    }
}
void function_15(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            int k = 1;
            while (k <= j) {
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}
void function_16(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            int k = 1;
            while (k <= n) {
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}
int main() {
    
    function_1(100);
    function_1(1000);
    function_2(100);
    function_2(1000);
    function_3(100);
    function_3(1000);
    function_4();
    function_4();
    function_5();
    function_5();
    function_6(100);
    function_6(1000);
    function_7(100);
    function_7(1000);
    function_8(100);
    function_8(1000);
    function_9(100);
    function_9(1000);
    function_10(100);
    function_10(1000);
    function_11(100);
    function_11(1000);
    function_12(100);
    function_12(1000);
    function_13(100);
    function_13(1000);
    function_14(100);
    function_14(1000);
    function_15(10);
    function_15(100);
    function_16(10);
    function_16(100);
    
}
